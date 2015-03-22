#include "engine.hpp"


#include <filesystem>

#include "container.hpp"
#include "data_source.hpp"
#include "monitor.hpp"
#include "observation.hpp"

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_iterators.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_utils.hpp"

#include "impl/xml_helper.hpp"
#include "impl/translate_file.hpp"


namespace pqdif {

	struct engine_t::impl
	{
		error_handler_t error_handler_;

		container::xml_container_t container_;
		data_source::xml_data_source_t data_source_;
		monitor::xml_monitor_setting_t monitor_;
		std::vector<observation::xml_observation_t> observations_;

		pqdif::impl::translate_file_t translate_impl_;

		impl(const error_handler_t &error_handler)
			: error_handler_(error_handler)
		{}

		bool parse_xml(const std::string &path)
		{
			rapidxml::file<> fdoc(path.c_str());

			rapidxml::xml_document<> doc;
			doc.parse<0>(fdoc.data());

			auto root = doc.first_node();
			
			// parse container
			{
				auto container_node = root->first_node("tagContainer");
				xml::to_value(container_node, container_.version_info_);
				xml::to_value(container_node, container_.create_time_);
				xml::to_value(container_node, container_.file_name_);
				xml::to_value(container_node, container_.language_);
				xml::to_value(container_node, container_.compr_style_, container::compress_style::static_convert());
				xml::to_value(container_node, container_.compr_algorithm_, container::compress_algorithm::static_convert());
			}

			// parse data source
			{
				auto data_source_node = root->first_node("tagRecDataSource");
				xml::to_value(data_source_node, data_source_.type_id_, data_source::data_source_type::static_convert());
				xml::to_value(data_source_node, data_source_.vendor_id_, data_source::vendor::static_convert());
				xml::to_value(data_source_node, data_source_.equipment_id_, data_source::equipment::static_convert());
				xml::to_value(data_source_node, data_source_.effective_);

				auto channels_node = data_source_node->first_node(data_source_.channel_defns_.guid_name_.c_str());
				
				pqdif::data_source::channel_defns_t channel_defns;
				std::for_each(
					rapidxml::node_iterator<char>(channels_node), 
					rapidxml::node_iterator<char>(), 
					[this, &channel_defns](const rapidxml::xml_node<char> &val)
				{
					using namespace pqdif::data_source;

					// channel
					assert(val.name() == channel_defns.one_channel_defn_.guid_name_);
					one_channel_defn_t channel_defn;
				
					auto attr = val.first_attribute("attr");
					if( attr != nullptr )
					{
						channel_defn.attr_ = stdex::to_number(attr->value());
					}

					auto cls = val.first_attribute("cls");
					if( cls != nullptr )
					{
						channel_defn.cls_ = stdex::to_number(cls->value());
					}

					xml::to_value(&val, channel_defn.name_);
					xml::to_value(&val, channel_defn.phase_id_, channel::phase_convert());
					xml::to_value(&val, channel_defn.quantity_type_, channel::quantity_type_convert());
					xml::to_value(&val, channel_defn.quantity_measure_id_, channel::quantity_measure_convert());
					
					
					// series
					auto series_node = val.first_node(channel_defn.seires_defns_.guid_name_.c_str());
					std::for_each(
						rapidxml::node_iterator<char>(series_node),
						rapidxml::node_iterator<char>(),
						[&channel_defn](const rapidxml::xml_node<char> &val)
					{
						using namespace pqdif::data_source;

						
						one_series_defn_t series_defn;
						auto attr = val.first_attribute();
						if( attr != nullptr )
						{
							series_defn.attribute_ = stdex::to_number(attr->value());
						}

						xml::to_value(&val, series_defn.value_type_, channel::series::value_type_convert()),
						xml::to_value(&val, series_defn.quantity_units_id_, channel::series::quantity_units_convert()),
						xml::to_value(&val, series_defn.quantity_character_id_, channel::series::quantity_character_convert()),
						xml::to_value(&val, series_defn.storage_method_id_, channel::series::storage_method_convert()),
						xml::to_value(&val, series_defn.greek_prefix_id_, channel::series::hint_greek_convert()),

						channel_defn.seires_defns_.value_.one_series_defn_.value_.emplace_back(std::move(series_defn));
					});

					channel_defns.one_channel_defn_.value_.emplace_back(std::move(channel_defn));
				});

				data_source_.channel_defns_.value_.one_channel_defn_.value_ = std::move(channel_defns.one_channel_defn_.value_);
			}

			// parse monitor
			{
				auto monitor_node = root->first_node("tagRecMonitorSettings");
				if( monitor_node != nullptr )
				{
					xml::to_value(monitor_node, monitor_.effective_);
					xml::to_value(monitor_node, monitor_.time_installed_);
					xml::to_value(monitor_node, monitor_.use_calibration_);
					xml::to_value(monitor_node, monitor_.use_trasducer_);
					xml::to_value(monitor_node, monitor_.nominal_frequency_);
					xml::to_value(monitor_node, monitor_.connection_type_, monitor::physical::static_convert());
				}
			}

			return true;
		}
	};


	engine_t::engine_t(const error_handler_t &error_handler)
		: impl_(std::make_unique<impl>(error_handler))
	{

	}

	engine_t::~engine_t()
	{}


	bool engine_t::start(const std::string &xml_path, const std::string &pqdif_path)
	{
		try
		{
			if( !impl_->translate_impl_.open(pqdif_path) )
			{
				impl_->parse_xml(xml_path);

				impl_->translate_impl_.translate(
					impl_->container_,
					impl_->data_source_,
					impl_->monitor_);
			}
			else
			{
				impl_->translate_impl_.read(impl_->container_, impl_->data_source_, impl_->observations_);
			}
		}
		catch( std::exception &e )
		{
			impl_->error_handler_(e.what());
			return false;
		}

		return true;
	}

	bool engine_t::stop()
	{
		impl_->translate_impl_.close();
		return true;
	}

	const data_source::xml_data_source_t &engine_t::get_data_source() const
	{
		return impl_->data_source_;
	}

	const std::vector<observation::xml_observation_t> &engine_t::get_observations() const
	{
		return impl_->observations_;
	}

	void engine_t::put_observation(const observation::xml_observation_t &val)
	{
		impl_->translate_impl_.write_observation(val);
		impl_->observations_.push_back(val);
	}

}