#include "element_to_buffer.hpp"

#include "../config.hpp"

#include "../container.hpp"
#include "../data_source.hpp"
#include "../monitor.hpp"
#include "../observation.hpp"

#include <list>


namespace pqdif { namespace impl {

	template < typename T >
	void init_scalar_element(pqdif_element_t &element, const pqdif_guid_t &guid, char phys_type, const T &val)
	{
		element.tagElement	= guid;
		element.typeElement = ID_ELEMENT_TYPE_SCALAR;
		element.typePhysical= phys_type;
		element.isEmbedded	= true;
		std::memcpy(&element.valueEmbedded, &val, sizeof(val));
	}

	void init_scalar_additional_element(pqdif_element_t &element, const pqdif_guid_t &guid, char phys_type, std::uint32_t offset, std::uint32_t size)
	{
		element.tagElement = guid;
		element.typeElement = ID_ELEMENT_TYPE_SCALAR;
		element.typePhysical = phys_type;
		element.isEmbedded = false;
		element.link.linkElement = offset;
		element.link.sizeElement = size;
	}

	void init_vector_element(pqdif_element_t &element, const pqdif_guid_t &guid, char phys_type, std::uint32_t offset, std::uint32_t size)
	{
		element.tagElement = guid;
		element.typeElement = ID_ELEMENT_TYPE_VECTOR;
		element.typePhysical = phys_type;
		element.isEmbedded = false;
		element.link.linkElement = offset;
		element.link.sizeElement = size;
	}

	void init_collection_element(pqdif_element_t &element, const pqdif_guid_t &guid, std::uint32_t offset)
	{
		element.tagElement = guid;
		element.typeElement = ID_ELEMENT_TYPE_COLLECTION;
		element.typePhysical = 0;
		element.isEmbedded = false;
		element.link.linkElement = offset;
		element.link.sizeElement = 0;
	}

	struct o_serialize_t
	{
		static const std::uint32_t COLLECTION_NUMBER_SIZE = sizeof(std::uint32_t);
		static const std::uint32_t COLLECTION_ELEMENT_SIZE = sizeof(pqdif_element_t);

		buffer_t element_buffer_;
		buffer_t data_buffer_;
		std::list<std::string> data_nodes_;

		const std::uint32_t collection_cnt_ = 0;
		const std::uint32_t element_cnt_ = 0;

		pqdif_element_t *cur_element_ = nullptr;
		std::uint32_t cur_element_cnt_ = 0;
		std::uint32_t cur_collection_cnt_ = 0;

		std::uint32_t offset_ = 0;
		std::uint32_t element_buffer_size_ = 0;

		o_serialize_t(std::uint32_t collection_cnt, std::uint32_t element_cnt)
			: element_buffer_(make_buffer(COLLECTION_NUMBER_SIZE + collection_cnt * COLLECTION_NUMBER_SIZE + element_cnt * COLLECTION_ELEMENT_SIZE))
			, element_cnt_(element_cnt)
			, collection_cnt_(collection_cnt)
			, cur_element_(reinterpret_cast<pqdif_element_t *>(element_buffer_.first.get()))
			, offset_(collection_cnt * COLLECTION_NUMBER_SIZE + element_cnt * COLLECTION_ELEMENT_SIZE)
		{
		}

		buffer_t element_buffer()
		{
			return element_buffer_;
		}

		buffer_t data_buffer()
		{
			std::uint32_t size = 0;
			std::for_each(data_nodes_.cbegin(), data_nodes_.cend(), 
				[&size](const auto &val)
			{
				size += val.size();
			});

			data_buffer_ = make_buffer(size);

			std::uint32_t offset = 0;
			std::for_each(data_nodes_.cbegin(), data_nodes_.cend(),
				[this, &offset](const auto &val)
			{
				std::copy(val.cbegin(), val.cend(), 
					stdext::make_unchecked_array_iterator(data_buffer_.first.get() + offset));
				offset += val.size();
			});

			assert(offset == size);
			return data_buffer_;
		}

		template < typename T >
		void init_scalar_impl(const tag_value_t<T> &val, char phys_type)
		{
			init_scalar_element(*cur_element_, val.guid_, phys_type, val.value_);

			cur_element_ += 1;
			++cur_element_cnt_;
			element_buffer_size_ += COLLECTION_ELEMENT_SIZE;

			assert(cur_element_cnt_ <= element_cnt_);
			assert(element_buffer_size_ <= element_buffer_.second);
		}

		void init_scalar_additional_impl(const GUID &guid, const char *data, std::uint32_t size, char phys_type)
		{
			init_scalar_additional_element(*cur_element_, guid, phys_type, offset_, size);
			cur_element_ += 1;
			++cur_element_cnt_;
			element_buffer_size_ += COLLECTION_ELEMENT_SIZE;

			assert(cur_element_cnt_ <= element_cnt_);
			assert(element_buffer_size_ <= element_buffer_.second);

			std::string data_buffer(data, size);
			data_nodes_.emplace_back(std::move(data_buffer));
			offset_ += size;
		}

		template < typename T >
		void init_vector_impl(const GUID &guid, const T *data, std::uint32_t size, char phys_type, std::uint32_t offset)
		{
			offset_ += offset;
			init_vector_element(*cur_element_, guid, phys_type, offset_, size);
			cur_element_ += 1;
			++cur_element_cnt_;
			element_buffer_size_ += COLLECTION_ELEMENT_SIZE;

			std::string data_size(reinterpret_cast<const char *>(&size), sizeof(size));
			size = size * sizeof(T);
			std::string data_buffer(reinterpret_cast<const char *>(data), size);
			data_nodes_.emplace_back(data_size + data_buffer);
			offset_ += size;

			assert(cur_element_cnt_ <= element_cnt_);
			assert(element_buffer_size_ <= element_buffer_.second);
		}

		void init_collection_size_impl(std::uint32_t size)
		{
			char *size_value = reinterpret_cast<char *>(cur_element_);
			std::memcpy(size_value, &size, sizeof(size));
			cur_element_ = reinterpret_cast<pqdif_element_t *>(size_value + sizeof(size));
			++cur_collection_cnt_;
			element_buffer_size_ += COLLECTION_NUMBER_SIZE;

			assert(cur_collection_cnt_ <= collection_cnt_);
			assert(element_buffer_size_ <= element_buffer_.second);
		}

		void init_collection_name_impl(const GUID &guid, std::uint32_t offset)
		{
			init_collection_element(*cur_element_, guid, offset);

			cur_element_ += 1;
			++cur_element_cnt_;
			element_buffer_size_ += COLLECTION_ELEMENT_SIZE;

			assert(cur_element_cnt_ <= element_cnt_);
			assert(element_buffer_size_ <= element_buffer_.second);
		}

		o_serialize_t &operator<<(const tag_size_t &val)
		{
			init_collection_size_impl(val.value_);

			return *this;
		}

		template < typename T >
		typename std::enable_if<std::is_enum<T>::value, o_serialize_t &>::type operator<<(const tag_value_t<T> &val)
		{
			init_scalar_impl(val, ID_PHYS_TYPE_UNS_INTEGER4);
			return *this;
		}

		o_serialize_t &operator<<(const tag_value_t<std::uint8_t> &val)
		{
			init_scalar_impl(val, ID_PHYS_TYPE_UNS_INTEGER1);
			return *this;
		}

		o_serialize_t &operator<<(const tag_value_t<std::uint16_t> &val)
		{
			init_scalar_impl(val, ID_PHYS_TYPE_UNS_INTEGER2);
			return *this;
		}

		o_serialize_t &operator<<(const tag_value_t<std::uint32_t> &val)
		{
			init_scalar_impl(val, ID_PHYS_TYPE_UNS_INTEGER4);
			return *this;
		}

		o_serialize_t &operator<<(const tag_value_t<double> &val)
		{
			init_scalar_impl(val, ID_PHYS_TYPE_REAL8);
			return *this;
		}

		o_serialize_t &operator<<(const tag_value_t<std::string> &val)
		{
			init_vector_impl(val.guid_, val.value_.c_str(), val.value_.size() + 1, ID_PHYS_TYPE_CHAR1, 4);
			return *this;
		}

		/*o_serialize_t &operator<<(const tag_value_t<pqdif_time_t> &val)
		{
			init_vector_impl(val, ID_PHYS_TYPE_TIMESTAMPPQDIF, 0);
			return *this;
		}*/

		o_serialize_t &operator<<(const tag_value_t<pqdif_multi_value_t> &val)
		{
			init_scalar_impl(val, ID_PHYS_TYPE_UNS_INTEGER4);
			return *this;
		}

		o_serialize_t &operator<<(const tag_value_t<pqdif_guid_t> &val)
		{
			init_scalar_additional_impl(val.guid_, val.value_.data(), val.value_.size(), ID_PHYS_TYPE_GUID);
			return *this;
		}

		o_serialize_t &operator<<(const tag_value_t<std::vector<double>> &val)
		{
			init_vector_impl(val.guid_, val.value_.data(), val.value_.size(), ID_PHYS_TYPE_REAL8, 4);
			return *this;
		}

		template < typename T >
		o_serialize_t &operator<<(const tag_value_t<std::vector<T>> &val)
		{
			init_collection_size_impl(val.value_.size());

			std::uint32_t offset = 0;
			for( auto i = 0; i != val.value_.size(); ++i )
			{
				if( i == 0 )
				{
					offset = cur_collection_cnt_ * COLLECTION_NUMBER_SIZE + (cur_element_cnt_ + val.value_.size()) * COLLECTION_ELEMENT_SIZE;
				}
				else
				{
					auto ret = val.value_[i - 1].element_cnt();
					offset += ret.first * COLLECTION_NUMBER_SIZE + ret.second * COLLECTION_ELEMENT_SIZE;
				}

				init_collection_name_impl(val.guid_, offset);
			}

			std::for_each(val.value_.cbegin(), val.value_.cend(),
				[this](const auto &v)
			{
				*this << v;
			});

			return *this;
		}

		template < typename T >
		typename std::enable_if<std::is_class<T>::value, o_serialize_t &>::type operator<<(const tag_value_t<T> &val)
		{
			init_collection_name_impl(val.guid_, (cur_collection_cnt_) * COLLECTION_NUMBER_SIZE + (cur_element_cnt_ + 1) * COLLECTION_ELEMENT_SIZE);

			*this << val.value_;
			return *this;
		}
	};

	template < typename T >
	auto to_buffer_helper(const T &val)
	{
		auto size = val.element_cnt();

		o_serialize_t os(size.first, size.second);
		os << val;

		return std::make_pair(os.element_buffer(), os.data_buffer());
	}

	std::pair<buffer_t, buffer_t> container_to_buffer(const container::xml_container_t &val)
	{
		return to_buffer_helper(val);
	}

	std::pair<buffer_t, buffer_t> data_source_to_buffer(const data_source::xml_data_source_t &val)
	{
		return to_buffer_helper(val);
	}

	std::pair<buffer_t, buffer_t> monitor_setting_to_buffer(const monitor::xml_monitor_setting_t &val)
	{
		return to_buffer_helper(val);
	}

	std::pair<buffer_t, buffer_t> observation_to_buffer(const observation::xml_observation_t &val)
	{
		return to_buffer_helper(val);
	}
}
}