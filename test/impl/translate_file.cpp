#include "translate_file.hpp"

#include <filesystem>

#include "../container.hpp"
#include "../data_source.hpp"
#include "../monitor.hpp"
#include "../observation.hpp"


#include "element_to_buffer.hpp"
#include "buffer_to_element.hpp"


namespace pqdif { namespace impl {
	

	template < typename T >
	void write(std::fstream &os, const T &val)
	{
		os.write(reinterpret_cast<const char *>(&val), sizeof(val));
	}

	template < typename T >
	std::uint32_t read(std::fstream &os, T &val)
	{
		os.read(reinterpret_cast<char *>(&val), sizeof(val));
		return sizeof(val);
	}

	pqdif_header_t create_element_header(const GUID &type, std::uint32_t data_size, std::uint32_t next_offset, std::uint32_t check_sum)
	{
		pqdif_header_t header;
		header.guidRecordSignature = guidRecordSignaturePQDIF;
		header.tagRecordType	= type;
		header.sizeHeader		= sizeof(header);
		header.sizeData			= data_size;
		header.checksum			= check_sum;
		header.linkNextRecord	= next_offset;

		return header;
	}

	template < typename T >
	struct translate_impl_t;

	template < >
	struct translate_impl_t<container::xml_container_t>
	{
		static auto to_buffer(const container::xml_container_t &val)
		{
			return container_to_buffer(val);
		}

		static void to_element(const buffer_t &buffer, container::xml_container_t &val)
		{
			return buffer_to_container(buffer, val);
		}
	};

	template < >
	struct translate_impl_t<data_source::xml_data_source_t>
	{
		static auto to_buffer(const data_source::xml_data_source_t &val)
		{
			return data_source_to_buffer(val);
		}

		static void to_element(const buffer_t &buffer, data_source::xml_data_source_t &val)
		{
			buffer_to_data_source(buffer, val);
		}
	};

	template < >
	struct translate_impl_t<monitor::xml_monitor_setting_t>
	{
		static auto to_buffer(const monitor::xml_monitor_setting_t &val)
		{
			return monitor_setting_to_buffer(val);
		}

		static void to_element(const buffer_t &buffer, monitor::xml_monitor_setting_t &val)
		{
			buffer_to_monitor_setting(buffer, val);
		}
	};

	template < >
	struct translate_impl_t<observation::xml_observation_t>
	{
		static auto to_buffer(const observation::xml_observation_t &val)
		{
			return observation_to_buffer(val);
		}

		static void to_element(const buffer_t &buffer, observation::xml_observation_t &val)
		{
			buffer_to_observation(buffer, val);
		}
	};



	template < typename T >
	std::uint32_t write_impl(std::fstream &os, const T &val, const GUID &tag_type, std::uint32_t offset, std::uint32_t check_sum)
	{
		auto buffer = translate_impl_t<T>::to_buffer(val);

		std::uint32_t data_size = buffer.first.second + buffer.second.second;
		pqdif_header_t header = create_element_header(tag_type, data_size, offset + data_size + sizeof(pqdif_header_t), check_sum);

		write(os, header);
		os.write(buffer.first.first.get(), buffer.first.second);
		os.write(buffer.second.first.get(), buffer.second.second);

		return data_size + sizeof(pqdif_header_t);
	}

	template < typename T >
	void read_impl(std::fstream &os, const pqdif_guid_t &guid, T &val)
	{
		pqdif_header_t header;
		read(os, header);

		if( header.tagRecordType != guid )
		{
			os.seekg(header.linkNextRecord);
		}
		else
		{
			auto file_buffer = make_buffer(static_cast<std::uint32_t>(header.sizeData));
			os.read(file_buffer.first.get(), file_buffer.second);

			translate_impl_t<T>::to_element(file_buffer, val);
		}
	}

	template < typename T >
	void read_impl(std::fstream &os, const pqdif_guid_t &guid, std::vector<T> &val)
	{
		while( 1 )
		{
			pqdif_header_t header;
			read(os, header);

			if( header.sizeData == 0 )
				break;

			if( header.tagRecordType != guid )
			{
				os.seekg(header.linkNextRecord);
			}
			else
			{
				auto file_buffer = make_buffer(static_cast<std::uint32_t>(header.sizeData));
				os.read(file_buffer.first.get(), file_buffer.second);

				T v;
				translate_impl_t<T>::to_element(file_buffer, v);
				val.push_back(v);
			}
		}

	}

	bool translate_file_t::open(const std::string &path)
	{
		if( std::tr2::sys::exists(std::tr2::sys::path(path)) )
		{
			os_.open(path, std::ios_base::binary | std::ios_base::out | std::ios_base::in | std::ios_base::app);
			return true;
		}
		else
		{
			os_.open(path, std::ios_base::binary | std::ios_base::out);
			return false;
		}
		
		if( !os_.good() )
			throw std::runtime_error("open pqdif file error");
	}

	void translate_file_t::close()
	{
		os_.close();
	}

	void translate_file_t::write_observation(const observation::xml_observation_t &observation)
	{
		offset_ += write_impl(os_, observation, tagRecObservation, offset_, 0);
	}

	void translate_file_t::read(container::xml_container_t &container, data_source::xml_data_source_t &data_source, std::vector<observation::xml_observation_t> &observations)
	{
		read_impl(os_, tagContainer, container);
		read_impl(os_, tagRecDataSource, data_source);
		read_impl(os_, tagRecObservation, observations);
	}

	void translate_file_t::translate(
		const container::xml_container_t &container, 
		const data_source::xml_data_source_t &data_source,
		const monitor::xml_monitor_setting_t &monitor_setting)
	{
		offset_ += write_impl(os_, container, tagContainer, offset_, 0);
		offset_ += write_impl(os_, data_source, tagRecDataSource, offset_, 0);
		offset_ += write_impl(os_, monitor_setting, tagRecMonitorSettings, offset_, 0);

		return;

		pqdif_element_t element, element1;
		element.typeElement = ID_ELEMENT_TYPE_SCALAR;
		element.typePhysical = ID_PHYS_TYPE_UNS_INTEGER4;
		element.isEmbedded = true;

		
		element1.typeElement = ID_ELEMENT_TYPE_COLLECTION;
		element1.isEmbedded = false;
		

		impl::write(os_, create_element_header(tagContainer, 4 + 1 * 28, 4 + 1 * 28 + sizeof(pqdif_header_t), 0));
		
		impl::write(os_, 1);
		element.tagElement = tagValueTypeID;
		impl::write(os_, element);


		impl::write(os_, create_element_header(tagContainer, 4 + 1 * 28, 2 *(4 + 1 * 28 + sizeof(pqdif_header_t)), 0));

		impl::write(os_, 1);
		element.tagElement = tagValueTypeID;
		impl::write(os_, element);


		impl::write(os_, create_element_header(tagContainer, 4 + 1 * 28, 1000, 0));

		impl::write(os_, 1);
		element.tagElement = tagValueTypeID;
		impl::write(os_, element);
		
	}

}}