#include "buffer_to_element.hpp"

#include "../config.hpp"

#include "../container.hpp"
#include "../data_source.hpp"
#include "../monitor.hpp"
#include "../observation.hpp"


namespace pqdif { namespace impl { 



	struct i_serialize_t
	{
		const char *buffer_;
		const char *cur_buffer_;
		std::uint32_t buffer_size_ = 0;
		std::uint32_t offset_ = 0;

		i_serialize_t(const buffer_t &buffer)
			: buffer_(buffer.first.get())
			, cur_buffer_(buffer.first.get())
			, buffer_size_(buffer.second)
		{}


		pqdif_element_t read_element_impl()
		{
			offset_ += sizeof(pqdif_element_t);
			assert(offset_ <= buffer_size_);

			pqdif_element_t element = *reinterpret_cast<const pqdif_element_t *>(cur_buffer_);
			cur_buffer_ += sizeof(pqdif_element_t);
			
			return element;
		}

		std::uint32_t read_size_impl(std::uint32_t offset)
		{
			std::uint32_t v = *reinterpret_cast<const std::uint32_t *>(buffer_ + offset);
			return v;
		}

		std::uint32_t read_size_impl()
		{
			offset_ += sizeof(std::uint32_t);
			assert(offset_ <= buffer_size_);

			std::uint32_t v = *reinterpret_cast<const std::uint32_t *>(cur_buffer_);
			cur_buffer_ += sizeof(std::uint32_t);

			return v;
		}

		i_serialize_t &operator>>(tag_size_t &val)
		{
			offset_ += sizeof(val);
			assert(offset_ <= buffer_size_);

			val = *reinterpret_cast<const tag_size_t *>(cur_buffer_);
			cur_buffer_ += sizeof(val);

			return *this;
		}

		template < typename T >
		typename std::enable_if<std::is_enum<T>::value, i_serialize_t &>::type operator>>(tag_value_t<T> &val)
		{
			auto element = read_element_impl();
			
			assert(element.tagElement == val.guid_);
			assert(element.typeElement == ID_ELEMENT_TYPE_SCALAR);
			assert(element.typePhysical == ID_PHYS_TYPE_UNS_INTEGER4);
			assert(element.isEmbedded);

			val.value_ = *(T *)(element.valueEmbedded);
			return *this;
		}


		i_serialize_t &operator>>(tag_value_t<std::uint32_t> &val)
		{
			auto element = read_element_impl();

			assert(element.tagElement == val.guid_);
			assert(element.typeElement == ID_ELEMENT_TYPE_SCALAR);
			assert(element.typePhysical == ID_PHYS_TYPE_UNS_INTEGER4);
			assert(element.isEmbedded);

			val.value_ = *(std::uint32_t *)element.valueEmbedded;

			return *this;
		}

		i_serialize_t &operator>>(tag_value_t<double> &val)
		{
			auto element = read_element_impl();

			assert(element.tagElement == val.guid_);
			assert(element.typeElement == ID_ELEMENT_TYPE_SCALAR);
			assert(element.typePhysical == ID_PHYS_TYPE_REAL8);
			assert(element.isEmbedded);

			val.value_ = *(double *)element.valueEmbedded;
			return *this;
		}

		i_serialize_t &operator>>(tag_value_t<std::string> &val)
		{
			auto element = read_element_impl();

			assert(element.tagElement == val.guid_);
			assert(element.typeElement == ID_ELEMENT_TYPE_VECTOR);
			assert(element.typePhysical == ID_PHYS_TYPE_CHAR1);
			assert(!element.isEmbedded);

			std::uint32_t size = read_size_impl(element.link.linkElement);
			val.value_.append(buffer_ + element.link.linkElement + 4, size);

			return *this;
		}

		i_serialize_t &operator>>(tag_value_t<pqdif_multi_value_t> &val)
		{
			auto element = read_element_impl();

			assert(element.tagElement == val.guid_);
			assert(element.typeElement == ID_ELEMENT_TYPE_SCALAR);
			assert(element.typePhysical == ID_PHYS_TYPE_UNS_INTEGER4);
			assert(element.isEmbedded);

			val.value_ = *(std::uint32_t *)element.valueEmbedded;

			return *this;
		}

		i_serialize_t &operator>>(tag_value_t<pqdif_guid_t> &val)
		{
			auto element = read_element_impl();

			assert(element.tagElement == val.guid_);
			assert(element.typeElement == ID_ELEMENT_TYPE_SCALAR);
			assert(element.typePhysical == ID_PHYS_TYPE_GUID);
			assert(!element.isEmbedded);

			std::memcpy(&val.value_, buffer_ + element.link.linkElement, sizeof(pqdif_guid_t));
		

			return *this;
		}

		i_serialize_t &operator>>(tag_value_t<std::vector<double>> &val)
		{
			auto element = read_element_impl();

			assert(element.tagElement == val.guid_);
			assert(element.typeElement == ID_ELEMENT_TYPE_VECTOR);
			assert(element.typePhysical == ID_PHYS_TYPE_REAL8);
			assert(!element.isEmbedded);

			std::uint32_t size = read_size_impl(element.link.linkElement);
			for( auto i = 0; i != size; ++i )
			{
				val.value_.push_back(*(reinterpret_cast<const double *>(buffer_ + element.link.linkElement + 4 ) + i));
			}

			return *this;
		}

		template < typename T >
		i_serialize_t &operator>>(tag_value_t<std::vector<T>> &val)
		{
			std::uint32_t size = read_size_impl();
			val.value_.resize(size);

			for( auto i = 0; i != val.value_.size(); ++i )
			{
				auto element = read_element_impl();

				assert(element.tagElement == val.guid_);
				assert(element.typeElement == ID_ELEMENT_TYPE_COLLECTION);
			}

			std::for_each(val.value_.begin(), val.value_.end(), 
				[this](auto &v)
			{
				*this >> v;
			});

			return *this;
		}

		template < typename T >
		typename std::enable_if<std::is_class<T>::value, i_serialize_t &>::type operator>>(tag_value_t<T> &val)
		{
			auto element = read_element_impl();

			assert(element.tagElement == val.guid_);
			assert(element.typeElement == ID_ELEMENT_TYPE_COLLECTION);

			*this >> val.value_;

			return *this;
		}
	};


	template < typename T >
	void to_element_helper(const buffer_t &buffer, T &val)
	{
		i_serialize_t os(buffer);
		os >> val;
	}


	void buffer_to_container(const buffer_t &buffer, container::xml_container_t &val)
	{
		to_element_helper(buffer, val);
	}

	void buffer_to_data_source(const buffer_t &buffer, data_source::xml_data_source_t &val)
	{
		to_element_helper(buffer, val);
	}

	void buffer_to_monitor_setting(const buffer_t &buffer, monitor::xml_monitor_setting_t &val)
	{
		to_element_helper(buffer, val);
	}

	void buffer_to_observation(const buffer_t &buffer, observation::xml_observation_t &val)
	{
		to_element_helper(buffer, val);
	}

}
}