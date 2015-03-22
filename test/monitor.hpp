#ifndef __PQDIF_MONITOR_SETTING_HPP
#define __PQDIF_MONITOR_SETTING_HPP

#include "config.hpp"

namespace pqdif { namespace monitor {

	namespace physical 
	{
		enum class type_t
			: std::uint32_t
		{
			SINGLE_PHASE = ID_SINGLE_PHASE,
			_2ELEMENT_DELTA = ID_2ELEMENT_DELTA,
			_2_5ELEMENT_WYE = ID_2_5ELEMENT_WYE,
			_3ELMENT_WYE = ID_3ELMENT_WYE,
			_3ELEMENT_DELTA = ID_3ELEMENT_DELTA,
			SPLIT_PHASE = ID_SPLIT_PHASE,
			_2ELEMENT_2PHASE = ID_2ELEMENT_2PHASE
		};

		
		inline auto &static_convert()
		{
			static convert_t<type_t> convert(
				DEFINE_ID(type_t::SINGLE_PHASE, ID_TO_STRING(ID_SINGLE_PHASE)),
				DEFINE_ID(type_t::_2ELEMENT_DELTA, ID_TO_STRING(ID_2ELEMENT_DELTA)),
				DEFINE_ID(type_t::_2_5ELEMENT_WYE, ID_TO_STRING(ID_2_5ELEMENT_WYE)),
				DEFINE_ID(type_t::_3ELMENT_WYE, ID_TO_STRING(ID_3ELMENT_WYE)),
				DEFINE_ID(type_t::_3ELEMENT_DELTA, ID_TO_STRING(ID_3ELEMENT_DELTA)),
				DEFINE_ID(type_t::SPLIT_PHASE, ID_TO_STRING(ID_SPLIT_PHASE)),
				DEFINE_ID(type_t::_2ELEMENT_2PHASE, ID_TO_STRING(ID_2ELEMENT_2PHASE))
				);
			return convert;
		}
	}

	struct xml_monitor_setting_t
	{
		static const std::uint32_t TagValueSize = 6;

		tag_value_t<std::string> effective_			= {tagEffective};
		tag_value_t<std::string> time_installed_	= {tagTimeInstalled};
		tag_value_t<std::uint32_t> use_calibration_	= {tagUseCalibration};
		tag_value_t<std::uint32_t> use_trasducer_	= {tagUseTransducer};
		tag_value_t<double> nominal_frequency_		= {tagNominalFrequency};
		tag_value_t<physical::type_t> connection_type_ = {tagSettingPhysicalConnection};

		std::pair<std::uint32_t, std::uint32_t> element_cnt() const
		{
			return{ 1, TagValueSize };
		}
	};


	template < typename StreamT >
	StreamT &operator<<(StreamT &os, const xml_monitor_setting_t &val)
	{
		os << tag_size_t{ xml_monitor_setting_t::TagValueSize }
			<< val.effective_
			<< val.time_installed_
			<< val.use_calibration_
			<< val.use_trasducer_
			<< val.nominal_frequency_
			<< val.connection_type_;

		return os;
	}

	template < typename StreamT >
	StreamT &operator>>(StreamT &os, xml_monitor_setting_t &val)
	{
		tag_size_t size = {0};
		os >> size
			>> val.effective_
			>> val.time_installed_
			>> val.use_calibration_
			>> val.use_trasducer_
			>> val.nominal_frequency_
			>> val.connection_type_;

		assert(size == xml_monitor_setting_t::TagValueSize);
		return os;
	}
}}


#endif