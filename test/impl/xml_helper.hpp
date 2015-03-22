#ifndef __PQDIF_XML_HELPER_IMPL_HPP
#define __PQDIF_XML_HELPER_IMPL_HPP

#include "config.hpp"
#include "algorithm.hpp"

namespace pqdif { namespace xml {

	namespace details {

		template < typename T, typename U = std::enable_if<std::is_same<T, std::string>::value, T>::type >
		inline std::string wrapper_cast_t(const char *value)
		{
			return value;
		}


		template < typename T, typename U = std::enable_if<std::is_arithmetic<T>::value, T>::type >
		T wrapper_cast_t(const char *value)
		{
			return stdex::to_number(value);
		}
	}
	


	template < typename NodeT, typename T >
	void to_value(const NodeT &node, tag_value_t<T> &tag_val)
	{
		auto val = node->first_node(tag_val.guid_name_.c_str());
		if( val == nullptr )
		{
			std::string msg = "parse xml error: " + tag_val.guid_name_;
			throw std::logic_error(msg);
		}

		tag_val.value_ = details::wrapper_cast_t<T>(val->value());
	}

	template < typename NodeT, typename T, typename ConvertT >
	void to_value(const NodeT &node, tag_value_t<T> &tag_val, convert_t<ConvertT> &c)
	{
		auto val = node->first_node(tag_val.guid_name_.c_str());
		if( val == nullptr )
		{
			std::string msg = "parse xml error: " + tag_val.guid_name_;
			throw std::logic_error(msg);
		}

		tag_val.value_ = string_2_id(c, val->value());
	}

}}

#endif