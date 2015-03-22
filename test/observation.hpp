#ifndef __PQDIF_OBSERVATION_HPP
#define __PQDIF_OBSERVATION_HPP

#include "config.hpp"

namespace pqdif { namespace observation {

	namespace trigger
	{
		enum class method_id_t
			: std::uint32_t
		{
			NONE = ID_TRIGGER_METH_NONE,
			CHANNEL = ID_TRIGGER_METH_CHANNEL,
			PERIODIC = ID_TRIGGER_METH_PERIODIC,
			EXTERNAL = ID_TRIGGER_METH_EXTERNAL,
			PERIODIC_STATS = ID_TRIGGER_METH_PERIODIC_STATS
		};


		inline auto &static_convert()
		{
			static convert_t<method_id_t> convert(
				DEFINE_ID(method_id_t::NONE, ID_TO_STRING(ID_TRIGGER_METH_NONE)),
				DEFINE_ID(method_id_t::CHANNEL, ID_TO_STRING(ID_TRIGGER_METH_CHANNEL)),
				DEFINE_ID(method_id_t::PERIODIC, ID_TO_STRING(ID_TRIGGER_METH_PERIODIC)),
				DEFINE_ID(method_id_t::EXTERNAL, ID_TO_STRING(ID_TRIGGER_METH_EXTERNAL)),
				DEFINE_ID(method_id_t::PERIODIC_STATS, ID_TO_STRING(ID_TRIGGER_METH_PERIODIC_STATS))
				);

			return convert;
		}
	}

	struct one_series_instance_t
	{
		static const std::uint32_t TagValueSize = 3;

		tag_value_t<std::uint32_t> series_offset_ = { tagSeriesOffset };
		tag_value_t<std::uint32_t> series_scale_ = { tagSeriesScale };
		tag_value_t<std::vector<double>> series_values_ = { tagSeriesValues };
	
		std::pair<std::uint32_t, std::uint32_t> element_cnt() const
		{
			return{ 1, TagValueSize };
		}
	};

	template < typename StreamT >
	StreamT &operator<<(StreamT &os, const one_series_instance_t &val)
	{
		os << tag_size_t{ one_series_instance_t::TagValueSize }
			<< val.series_offset_
			<< val.series_scale_
			<< val.series_values_;

		return os;
	}

	template < typename StreamT >
	StreamT &operator>>(StreamT &os, one_series_instance_t &val)
	{
		tag_size_t size = {0};
		os >> size
			>> val.series_offset_
			>> val.series_scale_
			>> val.series_values_;

		assert(size == one_series_instance_t::TagValueSize);

		return os;
	}


	struct series_instances_t
	{
		tag_value_t<std::vector<one_series_instance_t>> one_series_inst_{tagOneSeriesInstance};

		std::pair<std::uint32_t, std::uint32_t> element_cnt() const
		{
			std::uint32_t list_cnt = 1;
			std::uint32_t element_size = one_series_inst_.value_.size();
			std::for_each(one_series_inst_.value_.cbegin(), one_series_inst_.value_.cend(),
				[&list_cnt, &element_size](const auto &val)
			{
				auto ret = val.element_cnt();
				list_cnt += ret.first;
				element_size += ret.second;
			});

			return{ list_cnt, element_size };
		}
	};

	template < typename StreamT >
	StreamT &operator<<(StreamT &os, const series_instances_t &val)
	{
		os << val.one_series_inst_;

		return os;
	}

	template < typename StreamT >
	StreamT &operator>>(StreamT &os, series_instances_t &val)
	{
		os >> val.one_series_inst_;

		return os;
	}


	struct one_channel_instance_t
	{
		static const std::uint32_t TagValueSize = 3;

		tag_value_t<std::string> xx_ = {tagTimeCreate};
		tag_value_t<std::uint32_t> defn_idx_ = {tagChannelDefnIdx};
		tag_value_t<series_instances_t> series_instances_ = {tagSeriesInstances};

		std::pair<std::uint32_t, std::uint32_t> element_cnt() const
		{
			std::uint32_t list_cnt = 1;
			std::uint32_t element_size = TagValueSize;

			auto ret = series_instances_.value_.element_cnt();
			list_cnt += ret.first;
			element_size += ret.second;

			return{ list_cnt, element_size };
		}
	};

	template < typename StreamT >
	StreamT &operator<<(StreamT &os, const one_channel_instance_t &val)
	{
		os << tag_size_t{ one_channel_instance_t::TagValueSize }
			<< val.xx_
			<< val.defn_idx_
			<< val.series_instances_;

		return os;
	}

	template < typename StreamT >
	StreamT &operator>>(StreamT &os, one_channel_instance_t &val)
	{
		tag_size_t size = {0};
		os >> size
			>> val.xx_
			>> val.defn_idx_
			>> val.series_instances_;

		assert(size == one_channel_instance_t::TagValueSize);
		return os;
	}


	struct channel_instances_t
	{
		tag_value_t<std::vector<one_channel_instance_t>> one_instance_ = {tagOneChannelInst};

		std::pair<std::uint32_t, std::uint32_t> element_cnt() const
		{
			std::uint32_t list_cnt = 1;
			std::uint32_t element_size = one_instance_.value_.size();

			std::for_each(one_instance_.value_.cbegin(), one_instance_.value_.cend(),
				[&list_cnt, &element_size](const auto &val)
			{
				auto ret = val.element_cnt();
				list_cnt += ret.first;
				element_size += ret.second;
			});

			return{ list_cnt, element_size };
		}
	};

	template < typename StreamT >
	StreamT &operator<<(StreamT &os, const channel_instances_t &val)
	{
		os << val.one_instance_;

		return os;
	}

	template < typename StreamT >
	StreamT &operator>>(StreamT &os, channel_instances_t &val)
	{
		os >> val.one_instance_;

		return os;
	}


	struct xml_observation_t
	{
		static const std::uint32_t TagValueSize = 5;

		tag_value_t<std::string> name_				= { tagObservationName };
		tag_value_t<std::string> create_time_		= { tagTimeCreate };
		tag_value_t<std::string> start_time_		= { tagTimeStart };
		tag_value_t<trigger::method_id_t> trigger_method_id_ = { tagTriggerMethodID };
		tag_value_t<channel_instances_t> channel_instances_ = {tagChannelInstances};


		std::pair<std::uint32_t, std::uint32_t> element_cnt() const
		{
			std::uint32_t list_cnt = 1;
			std::uint32_t element_size = TagValueSize;

			auto ret = channel_instances_.value_.element_cnt();
			list_cnt += ret.first;
			element_size += ret.second;

			return{ list_cnt, element_size };
		}
	};


	template < typename StreamT >
	StreamT &operator<<(StreamT &os, const xml_observation_t &val)
	{
		os << tag_size_t{ xml_observation_t::TagValueSize }
			<< val.name_
			<< val.create_time_
			<< val.start_time_
			<< val.trigger_method_id_
			<< val.channel_instances_;

		return os;
	}

	template < typename StreamT >
	StreamT &operator>>(StreamT &os, xml_observation_t &val)
	{
		tag_size_t size = {0};

		os >> size
			>> val.name_
			>> val.create_time_
			>> val.start_time_
			>> val.trigger_method_id_
			>> val.channel_instances_;

		assert(size == xml_observation_t::TagValueSize);
		return os;
	}
}}


#endif