#ifndef __PQDIF_CONFIG_HPP
#define __PQDIF_CONFIG_HPP


#include <cassert>
#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <functional>

#include "pqdif/pqdif_ph.h"
#include "pqdif/pqdif_id.h"
#include "pqdif/pqdif_lg.h"


#define ID_TO_STRING(id) #id
#define DEFINE_GUID(id) std::make_pair(id, std::string(ID_TO_STRING(id)))
#define DEFINE_ID(type, desc) std::make_pair(type, std::string(desc)) 


namespace pqdif {

	
	using error_handler_t = std::function<void(const std::string &)>;

	struct pqdif_guid_t;
	struct pqdif_multi_value_t;


	template < typename T >
	struct convert_t
	{
		std::map<T, std::string> id_to_string_;
		std::map<std::string, T> string_to_id_;

		template < typename ...Args >
		convert_t(const Args &...args)
		{
			init_impl(args...);
		}

		template < typename T, typename ...Args >
		void init_impl(const T&arg, const Args &...args)
		{
			init_impl(arg);
			init_impl(args...);
		}

		void init_impl(const std::pair<T, std::string> &arg)
		{
			id_to_string_[arg.first] = arg.second;
			string_to_id_[arg.second] = arg.first;
		}

		void init_impl(const std::pair<GUID, std::string> &arg)
		{
			id_to_string_[arg.first] = arg.second;
			string_to_id_[arg.second] = arg.first;
		}
	};


	template < typename T >
	inline const std::string &id_2_string(convert_t<T> &c, const T &type)
	{
		return c.id_to_string_[type];
	}

	template < typename T >
	inline const T &string_2_id(convert_t<T> &c, const std::string &val)
	{
		return c.string_to_id_[val];
	}

	pqdif_multi_value_t string_2_id(convert_t<pqdif_multi_value_t> &c, const std::string &val);


	struct pqdif_header_t
		: c_record_mainheader
	{
		static_assert(std::is_pod<c_record_mainheader>::value, "type must pod type");

		pqdif_header_t()
		{
			std::memset(this, 0, sizeof(*this));
		}
	};

	struct pqdif_element_t
		: c_collection_element
	{
		static_assert(std::is_pod<c_collection_element>::value, "type must pod type");

		/*pqdif_element_t()
		{
			std::memset(this, 0, sizeof(*this));
		}*/
	};

	struct pqdif_time_t
		: TIMESTAMPPQDIF
	{
		static_assert(std::is_pod<TIMESTAMPPQDIF>::value, "type must pod type");

		pqdif_time_t()
		{
			std::memset(this, 0, sizeof(*this));
		}

		pqdif_time_t(std::uint32_t d, double t)
		{
			day = d;
			sec = t;
		}

		const char *data() const
		{
			return reinterpret_cast<const char *>(this);
		}

		std::uint32_t size() const
		{
			return sizeof(*this);
		}
	};

	struct pqdif_guid_t
		: GUID
	{
		static_assert(std::is_pod<GUID>::value, "type must pod type");

		pqdif_guid_t()
		{
			std::memset(this, 0, sizeof(*this));
		}

		pqdif_guid_t(const GUID &val)
			: GUID(val)
		{}

		operator GUID() const
		{
			*this;
		}

		const char *data() const
		{
			return reinterpret_cast<const char *>(this);
		}

		std::uint32_t size() const
		{
			return sizeof(*this);
		}

		bool operator<(const pqdif_guid_t &r) const
		{
			return std::memcmp((const GUID *)this, (const GUID *) &r, sizeof(pqdif::pqdif_guid_t)) < 0;
		}
	};

	inline bool operator==(const GUID &l, const pqdif_guid_t &r)
	{
		return std::memcmp((const GUID *)&l, (const GUID *) &r, sizeof(pqdif::pqdif_guid_t)) == 0;
	}

	inline bool operator!=(const GUID &l, const pqdif_guid_t &r)
	{
		return std::memcmp((const GUID *)&l, (const GUID *) &r, sizeof(pqdif::pqdif_guid_t)) != 0;
	}

	inline bool operator!=(const pqdif_guid_t &l, const pqdif_guid_t &r)
	{
		return std::memcmp((const GUID *)&l, (const GUID *) &r, sizeof(pqdif::pqdif_guid_t)) != 0;
	}


	const pqdif_guid_t &string_2_GUID(const std::string &tag_name);
	const std::string &GUID_2_string(const pqdif_guid_t &guid);

	struct pqdif_collection_t
	{
		const pqdif_guid_t &guid_;
		std::uint32_t element_cnt_ = 0;

		pqdif_collection_t(const pqdif_guid_t &guid, std::uint32_t element_cnt)
			: guid_(guid)
			, element_cnt_(element_cnt)
		{}

		const pqdif_guid_t &guid() const
		{
			return guid_;
		}

		std::uint32_t element_cnt() const
		{
			return element_cnt_;
		}
	};


	struct  pqdif_multi_value_t
	{
		std::uint32_t value_ = 0;

		pqdif_multi_value_t() = default;

		pqdif_multi_value_t(std::uint32_t val)
			: value_(val)
		{}

		bool operator<(const pqdif::pqdif_multi_value_t &r) const
		{
			return value_ < r.value_;
		}

		pqdif_multi_value_t operator|=(const pqdif_multi_value_t &val) const
		{
			return pqdif_multi_value_t{val.value_ | value_};
		}
	};

	template < typename T >
	struct tag_value_t
	{
		pqdif_guid_t guid_;
		std::string guid_name_;
		T value_;

		tag_value_t(const pqdif_guid_t &guid)
			: guid_(guid)
			, guid_name_(GUID_2_string(guid))
		{}
	};

	template < typename T >
	struct tag_size_impl_t
	{
		T value_;
	};
	using tag_size_t = tag_size_impl_t<std::uint32_t>;

	template < typename T >
	bool operator ==(const tag_size_impl_t<T> &l, const tag_size_impl_t<T> &r)
	{
		return l.value_ == r.value_;
	}

	template < typename T >
	bool operator ==(const T &l, const tag_size_impl_t<T> &r)
	{
		return l == r.value_;
	}

	template < typename T >
	bool operator ==(const tag_size_impl_t<T> &l, const T &r)
	{
		return l.value_ == r;
	}
}


#endif