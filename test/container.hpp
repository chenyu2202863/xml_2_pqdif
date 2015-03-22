#ifndef __PQDIF_CONTAINER_HPP
#define __PQDIF_CONTAINER_HPP

#include "config.hpp"


namespace pqdif { namespace container {



	namespace compress_style
	{
		enum class type_t
			: std::uint32_t
		{
			NONE = ID_COMP_STYLE_NONE,
			RECORDLEVEL = ID_COMP_STYLE_RECORDLEVEL,
			TOTALFILE = ID_COMP_STYLE_TOTALFILE
		};

		using type_convert = convert_t<type_t>;

		inline auto &static_convert()
		{
			static type_convert convert(
				DEFINE_ID(type_t::NONE, ID_TO_STRING(ID_COMP_STYLE_NONE)),
				DEFINE_ID(type_t::RECORDLEVEL, ID_TO_STRING(ID_COMP_STYLE_RECORDLEVEL)),
				DEFINE_ID(type_t::TOTALFILE, ID_TO_STRING(ID_COMP_STYLE_TOTALFILE))
				);

			return convert;
		}
	}


	namespace compress_algorithm
	{
		enum class type_t
			: std::uint32_t
		{
			NONE = ID_COMP_ALG_NONE,
			ZLIB = ID_COMP_ALG_ZLIB,
			PKZIPCL = ID_COMP_ALG_PKZIPCL
		};

		using type_convert = convert_t<type_t>;

		inline auto &static_convert()
		{
			static type_convert convert(
				DEFINE_ID(type_t::NONE, ID_TO_STRING(ID_COMP_ALG_NONE)),
				DEFINE_ID(type_t::ZLIB, ID_TO_STRING(ID_COMP_ALG_ZLIB)),
				DEFINE_ID(type_t::PKZIPCL, ID_TO_STRING(ID_COMP_ALG_PKZIPCL))
				);
			return convert;
		}
	}


	struct xml_container_t
	{
		static const std::uint32_t TagValueSize = 6;

		tag_value_t<std::string> version_info_				= {tagVersionInfo};
		tag_value_t<std::string> create_time_				= {tagCreation};
		tag_value_t<std::string> file_name_					= {tagFileName};
		tag_value_t<std::string> language_					= {tagLanguage};
		tag_value_t<compress_style::type_t> compr_style_	= {tagCompressionStyleID};
		tag_value_t<compress_algorithm::type_t> compr_algorithm_ = {tagCompressionAlgorithmID};


		std::pair<std::uint32_t, std::uint32_t> element_cnt() const
		{
			return {1, TagValueSize};
		}
	};

	template < typename StreamT >
	StreamT &operator<<(StreamT &os, const xml_container_t &val)
	{
		os << tag_size_t{xml_container_t::TagValueSize}
			<< val.version_info_
			<< val.create_time_
			<< val.file_name_
			<< val.language_
			<< val.compr_style_
			<< val.compr_algorithm_;

		return os;
	}

	template < typename StreamT >
	StreamT &operator>>(StreamT &os, xml_container_t &val)
	{
		tag_size_t size = {0};

		os >> size
			>> val.version_info_
			>> val.create_time_
			>> val.file_name_
			>> val.language_
			>> val.compr_style_
			>> val.compr_algorithm_;

		assert(size == xml_container_t::TagValueSize);
		return os;
	}
}}

#endif