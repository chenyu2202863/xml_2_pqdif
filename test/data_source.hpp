#ifndef __PQDIF_DATA_SOURCE_HPP
#define __PQDIF_DATA_SOURCE_HPP

#include "config.hpp"


namespace pqdif { namespace data_source {
	
	namespace data_source_type
	{
		using type_convert = convert_t<pqdif_guid_t>;

		inline auto &static_convert()
		{
			static type_convert convert(
				DEFINE_GUID(ID_DS_TYPE_MEASURE),
				DEFINE_GUID(ID_DS_TYPE_MANUAL),
				DEFINE_GUID(ID_DS_TYPE_SIMULATE),
				DEFINE_GUID(ID_DS_TYPE_BENCHMARK),
				DEFINE_GUID(ID_DS_TYPE_DEBUG)
				);
			return convert;
		}
	}

	namespace vendor
	{
		using type_convert = convert_t<pqdif_guid_t>;

		inline auto &static_convert()
		{
			static type_convert convert(
				DEFINE_GUID(ID_VENDOR_PMI),
				DEFINE_GUID(ID_VENDOR_METONE),
				DEFINE_GUID(ID_VENDOR_TRINERGI),
				DEFINE_GUID(ID_VENDOR_GE),
				DEFINE_GUID(ID_VENDOR_LEM),
				DEFINE_GUID(ID_VENDOR_ACTL),
				DEFINE_GUID(ID_VENDOR_ADVANTECH),
				DEFINE_GUID(ID_VENDOR_ELCOM),
				DEFINE_GUID(ID_VENDOR_PML)
				);
			return convert;
		}
	}

	namespace equipment 
	{
		using type_convert = convert_t<pqdif_guid_t>;

		inline auto &static_convert()
		{
			static type_convert convert(
				DEFINE_GUID(ID_EQUIP_PML_VIP),
				DEFINE_GUID(ID_EQUIP_PML_LOGSERVER),
				DEFINE_GUID(ID_EQUIP_METONE_ELT15),
				DEFINE_GUID(ID_EQUIP_PMI_SCANNER),
				DEFINE_GUID(ID_EQUIP_ADVANTECH_ADAM4017),
				DEFINE_GUID(ID_EQUIP_ETK_DSS),
				DEFINE_GUID(ID_EQUIP_ADVANTECH_ADAM4018),
				DEFINE_GUID(ID_EQUIP_ADVANTECH_ADAM4018M),
				DEFINE_GUID(ID_EQUIP_ADVANTECH_ADAM4052),
				DEFINE_GUID(ID_EQUIP_BMI_8800),
				DEFINE_GUID(ID_EQUIP_TRINERGI_PQM),
				DEFINE_GUID(ID_EQUIP_MEDCAL),
				DEFINE_GUID(ID_EQUIP_GE_KV),
				DEFINE_GUID(ID_EQUIP_GE_KV2),
				DEFINE_GUID(ID_EQUIP_ACUMENTRICS_CONTROL),
				DEFINE_GUID(ID_EQUIP_ETK_TEXTPQDIF),
				DEFINE_GUID(ID_EQUIP_ETK_PQWEB),
				DEFINE_GUID(ID_EQUIP_QWAVE_POWER_DISTRIBUTION),
				DEFINE_GUID(ID_EQUIP_QWAVE_POWER_TRANSMISSION),
				DEFINE_GUID(ID_EQUIP_QWAVE_MICRO),
				DEFINE_GUID(ID_EQUIP_QWAVE_TWIN),
				DEFINE_GUID(ID_EQUIP_QWAVE_PREMIUM),
				DEFINE_GUID(ID_EQUIP_QWAVE_LIGHT),
				DEFINE_GUID(ID_EQUIP_QWAVE_NOMAD),
				DEFINE_GUID(ID_EQUIP_EWON_4000),
				DEFINE_GUID(ID_EQUIP_QUALIMETRE),
				DEFINE_GUID(ID_EQUIP_LEM_ANALYST3Q),
				DEFINE_GUID(ID_EQUIP_LEM_ANALYST1Q),
				DEFINE_GUID(ID_EQUIP_LEM_ANALYST2050),
				DEFINE_GUID(ID_EQUIP_LEM_ANALYST2060),
				DEFINE_GUID(ID_EQUIP_LEM_MIDGET200),
				DEFINE_GUID(ID_EQUIP_LEM_MBX300),
				DEFINE_GUID(ID_EQUIP_LEM_MBX800),
				DEFINE_GUID(ID_EQUIP_LEM_MBX601),
				DEFINE_GUID(ID_EQUIP_LEM_MBX602),
				DEFINE_GUID(ID_EQUIP_LEM_MBX603),
				DEFINE_GUID(ID_EQUIP_LEM_MBX686)
				);
			return convert;
		}
	}


	namespace channel
	{
		enum class phase_id_t
			: std::uint32_t
		{
			NONE = ID_PHASE_NONE,
			AN =  ID_PHASE_AN ,
			BN =  ID_PHASE_BN,
			CN =  ID_PHASE_CN,
			NG =  ID_PHASE_NG,
			AB =  ID_PHASE_AB,
			BC =  ID_PHASE_BC,
			CA =  ID_PHASE_CA,
			TOTAL = ID_PHASE_TOTAL,
		};

		
		inline auto &phase_convert()
		{
			static convert_t<phase_id_t> convert(
				DEFINE_ID(phase_id_t::NONE, ID_TO_STRING(ID_PHASE_NONE)),
				DEFINE_ID(phase_id_t::NONE, ID_TO_STRING(ID_PHASE_AN)),
				DEFINE_ID(phase_id_t::NONE, ID_TO_STRING(ID_PHASE_BN)),
				DEFINE_ID(phase_id_t::NONE, ID_TO_STRING(ID_PHASE_CN)),
				DEFINE_ID(phase_id_t::NONE, ID_TO_STRING(ID_PHASE_NG)),
				DEFINE_ID(phase_id_t::NONE, ID_TO_STRING(ID_PHASE_AB)),
				DEFINE_ID(phase_id_t::NONE, ID_TO_STRING(ID_PHASE_BC)),
				DEFINE_ID(phase_id_t::NONE, ID_TO_STRING(ID_PHASE_CA)),
				DEFINE_ID(phase_id_t::NONE, ID_TO_STRING(ID_PHASE_TOTAL))
				);
			return convert;
		}


		inline auto &quantity_type_convert()
		{
			static convert_t<pqdif_guid_t> convert(
				DEFINE_GUID(ID_QT_VALUELOG),
				DEFINE_GUID(ID_QT_WAVEFORM),
				DEFINE_GUID(ID_QT_PHASOR)
				);
			return convert;
		}
		
		enum class quantity_measure_id_t
			: std::uint32_t
		{
			NONE = ID_QM_NONE,
			VOLTAGE = ID_QM_VOLTAGE,
			CURRENT = ID_QM_CURRENT,
			POWER = ID_QM_POWER,
			ENERGY = ID_QM_ENERGY,
			TEMPERATURE = ID_QM_TEMPERATURE
		};

		inline auto &quantity_measure_convert()
		{
			static convert_t<quantity_measure_id_t> convert(
				DEFINE_ID(quantity_measure_id_t::NONE, ID_TO_STRING(ID_QM_NONE)),
				DEFINE_ID(quantity_measure_id_t::VOLTAGE, ID_TO_STRING(ID_QM_VOLTAGE)),
				DEFINE_ID(quantity_measure_id_t::CURRENT, ID_TO_STRING(ID_QM_CURRENT)),
				DEFINE_ID(quantity_measure_id_t::POWER, ID_TO_STRING(ID_QM_POWER)),
				DEFINE_ID(quantity_measure_id_t::ENERGY, ID_TO_STRING(ID_QM_ENERGY)),
				DEFINE_ID(quantity_measure_id_t::TEMPERATURE, ID_TO_STRING(ID_QM_TEMPERATURE))
				);
			return convert;
		}

		namespace series
		{
			inline auto &value_type_convert()
			{
				static convert_t<pqdif_guid_t> convert(
					DEFINE_GUID(ID_SERIES_VALUE_TYPE_TIME),
					DEFINE_GUID(ID_SERIES_VALUE_TYPE_VAL),
					DEFINE_GUID(ID_SERIES_VALUE_TYPE_MIN),
					DEFINE_GUID(ID_SERIES_VALUE_TYPE_MAX),
					DEFINE_GUID(ID_SERIES_VALUE_TYPE_AVG),
					DEFINE_GUID(ID_SERIES_VALUE_TYPE_INST),
					DEFINE_GUID(ID_SERIES_VALUE_TYPE_P95),
					DEFINE_GUID(ID_SERIES_VALUE_TYPE_FREQUENCY),
					DEFINE_GUID(ID_SERIES_VALUE_TYPE_STATUS),
					DEFINE_GUID(ID_SERIES_VALUE_TYPE_INTERVAL),
					DEFINE_GUID(ID_SERIES_VALUE_TYPE_COUNT)					
					);
				return convert;
			}
			

			enum class quantity_units_id_t
				: std::uint32_t
			{
				NONE = ID_QU_NONE,
				SECONDS = ID_QU_SECONDS,
				TIMESTAMP = ID_QU_TIMESTAMP,
				VOLTS = ID_QU_VOLTS,
				AMPS = ID_QU_AMPS,
				VA = ID_QU_VA,
				WATTS = ID_QU_WATTS,
				VARS = ID_QU_VARS,
				HERTZ = ID_QU_HERTZ,
				PERCENT = ID_QU_PERCENT,
				VARHOURS = ID_QU_VARHOURS,
				WATTHOURS = ID_QU_WATTHOURS,
				VAHOURS = ID_QU_VAHOURS,
				
			};

			inline auto &quantity_units_convert()
			{
				static convert_t<quantity_units_id_t> convert(
					DEFINE_ID(quantity_units_id_t::NONE, ID_TO_STRING(ID_QU_NONE)),
					DEFINE_ID(quantity_units_id_t::SECONDS, ID_TO_STRING(ID_QU_SECONDS)),
					DEFINE_ID(quantity_units_id_t::TIMESTAMP, ID_TO_STRING(ID_QU_TIMESTAMP)),
					DEFINE_ID(quantity_units_id_t::VOLTS, ID_TO_STRING(ID_QU_VOLTS)),
					DEFINE_ID(quantity_units_id_t::AMPS, ID_TO_STRING(ID_QU_AMPS)),
					DEFINE_ID(quantity_units_id_t::VA, ID_TO_STRING(ID_QU_VA)),
					DEFINE_ID(quantity_units_id_t::WATTS, ID_TO_STRING(ID_QU_WATTS)),
					DEFINE_ID(quantity_units_id_t::VARS, ID_TO_STRING(ID_QU_VARS)),
					DEFINE_ID(quantity_units_id_t::HERTZ, ID_TO_STRING(ID_QU_HERTZ)),
					DEFINE_ID(quantity_units_id_t::PERCENT, ID_TO_STRING(ID_QU_PERCENT)),
					DEFINE_ID(quantity_units_id_t::VARHOURS, ID_TO_STRING(ID_QU_VARHOURS)),
					DEFINE_ID(quantity_units_id_t::WATTHOURS, ID_TO_STRING(ID_QU_WATTHOURS)),
					DEFINE_ID(quantity_units_id_t::VAHOURS, ID_TO_STRING(ID_QU_VAHOURS))
					);
				return convert;
			}

			inline auto &quantity_character_convert()
			{
				static convert_t<pqdif_guid_t> convert(
					DEFINE_GUID(ID_QC_NONE),
					DEFINE_GUID(ID_QC_INSTANTANEOUS),
					DEFINE_GUID(ID_QC_PEAK),
					DEFINE_GUID(ID_QC_RMS),
					DEFINE_GUID(ID_QC_HRMS),
					DEFINE_GUID(ID_QC_FREQUENCY),
					DEFINE_GUID(ID_QC_TOTAL_THD),
					DEFINE_GUID(ID_QC_EVEN_THD),
					DEFINE_GUID(ID_QC_ODD_THD),
					DEFINE_GUID(ID_QC_PEAK),
					DEFINE_GUID(ID_QC_RMS),
					DEFINE_GUID(ID_QC_HRMS),
					DEFINE_GUID(ID_QC_FREQUENCY),
					DEFINE_GUID(ID_QC_TOTAL_THD),
					DEFINE_GUID(ID_QC_IHRMS),
					DEFINE_GUID(ID_QC_FLKR_PST),
					DEFINE_GUID(ID_QC_FLKR_PLT),
					DEFINE_GUID(ID_QC_IHRMS),
					DEFINE_GUID(ID_QC_P),
					DEFINE_GUID(ID_QC_Q),
					DEFINE_GUID(ID_QC_S),
					DEFINE_GUID(ID_QC_DF),
					DEFINE_GUID(ID_QC_STATUS)				
					);
				return convert;
			}
	
			using storage_method_id_t = pqdif_multi_value_t;

			inline auto &storage_method_convert()
			{
				static convert_t<storage_method_id_t> convert(
					std::make_pair(pqdif_multi_value_t{ID_SERIES_METHOD_VALUES}, std::string("ID_SERIES_METHOD_VALUES")),
					std::make_pair(pqdif_multi_value_t{ID_SERIES_METHOD_SCALED}, std::string("ID_SERIES_METHOD_SCALED")),
					std::make_pair(pqdif_multi_value_t{ID_SERIES_METHOD_INCREMENT}, std::string("ID_SERIES_METHOD_INCREMENT"))
					);
				return convert;
			}

			
			enum class hint_greek_prefix_id_t
				: std::uint32_t
			{
				DONTCARE = ID_GREEK_DONTCARE
			};

			inline auto &hint_greek_convert()
			{
				static convert_t<hint_greek_prefix_id_t> convert(
					DEFINE_ID(hint_greek_prefix_id_t::DONTCARE, ID_TO_STRING(ID_GREEK_DONTCARE))
					);
				return convert;
			}
		}
	}

	// --------
	struct one_series_defn_t
	{
		static const std::uint32_t TagValueSize = 5;

		std::uint32_t attribute_ = 0;
		tag_value_t<pqdif_guid_t> value_type_ = {tagValueTypeID};
		tag_value_t<channel::series::quantity_units_id_t> quantity_units_id_ = {tagQuantityUnitsID};
		tag_value_t<pqdif_guid_t> quantity_character_id_ = {tagQuantityCharacteristicID};
		tag_value_t<channel::series::storage_method_id_t> storage_method_id_ = {tagStorageMethodID};
		tag_value_t<channel::series::hint_greek_prefix_id_t> greek_prefix_id_ = {tagHintGreekPrefixID};

		std::pair<std::uint32_t, std::uint32_t> element_cnt() const
		{
			return { 1, TagValueSize };
		}
	};

	template < typename StreamT >
	StreamT &operator<<(StreamT &os, const one_series_defn_t &val)
	{
		os << tag_size_t{one_series_defn_t::TagValueSize}
			<< val.value_type_
			<< val.quantity_units_id_
			<< val.quantity_character_id_
			<< val.storage_method_id_
			<< val.greek_prefix_id_;

		return os;
	}

	template < typename StreamT >
	StreamT &operator>>(StreamT &os, one_series_defn_t &val)
	{
		tag_size_t size = {0};

		os >> size
			>> val.value_type_
			>> val.quantity_units_id_
			>> val.quantity_character_id_
			>> val.storage_method_id_
			>> val.greek_prefix_id_;

		assert(size == one_series_defn_t::TagValueSize);
		return os;
	}

	// --------
	struct series_defns_t
	{
		tag_value_t<std::vector<one_series_defn_t>> one_series_defn_ = {tagOneSeriesDefn};


		std::pair<std::uint32_t, std::uint32_t> element_cnt() const
		{
			std::uint32_t list_cnt = 1;
			std::uint32_t element_size = one_series_defn_.value_.size();

			std::for_each(one_series_defn_.value_.cbegin(), one_series_defn_.value_.cend(),
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
	StreamT &operator<<(StreamT &os, const series_defns_t &val)
	{
		os << val.one_series_defn_;

		return os;
	}

	template < typename StreamT >
	StreamT &operator>>(StreamT &os, series_defns_t &val)
	{
		os >> val.one_series_defn_;

		return os;
	}

	// --------
	struct one_channel_defn_t
	{
		static const std::uint32_t TagValueSize = 5;

		std::uint32_t attr_ = {0};
		std::uint32_t cls_ = {0};

		tag_value_t<std::string> name_ = {tagChannelName};
		tag_value_t<channel::phase_id_t> phase_id_ = {tagPhaseID};
		tag_value_t<pqdif_guid_t> quantity_type_ = {tagQuantityTypeID};
		tag_value_t<channel::quantity_measure_id_t> quantity_measure_id_ = {tagQuantityMeasuredID};
		tag_value_t<series_defns_t> seires_defns_ = {tagSeriesDefns};

		std::pair<std::uint32_t, std::uint32_t> element_cnt() const
		{
			std::uint32_t list_cnt = 1;
			std::uint32_t element_size = TagValueSize;

			auto ret = seires_defns_.value_.element_cnt();
			list_cnt += ret.first;
			element_size += ret.second;

			return{ list_cnt, element_size };
		}
	};

	template < typename StreamT >
	StreamT &operator<<(StreamT &os, const one_channel_defn_t &val)
	{
		os << tag_size_t{one_channel_defn_t::TagValueSize}
			<< val.name_
			<< val.phase_id_
			<< val.quantity_type_
			<< val.quantity_measure_id_
			<< val.seires_defns_;

		return os;
	}

	template < typename StreamT >
	StreamT &operator>>(StreamT &os, one_channel_defn_t &val)
	{
		tag_size_t size;
		os >> size
			>> val.name_
			>> val.phase_id_
			>> val.quantity_type_
			>> val.quantity_measure_id_
			>> val.seires_defns_;

		assert(size == one_channel_defn_t::TagValueSize);
		return os;
	}

	// --------
	struct channel_defns_t
	{
		tag_value_t<std::vector<one_channel_defn_t>> one_channel_defn_ = {tagOneChannelDefn};

		std::pair<std::uint32_t, std::uint32_t> element_cnt() const
		{
			std::uint32_t list_cnt = 1;
			std::uint32_t element_size = one_channel_defn_.value_.size();

			std::for_each(one_channel_defn_.value_.cbegin(), one_channel_defn_.value_.cend(),
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
	StreamT &operator<<(StreamT &os, const channel_defns_t &val)
	{
		os << val.one_channel_defn_;

		return os;
	}

	template < typename StreamT >
	StreamT &operator>>(StreamT &os, channel_defns_t &val)
	{
		os >> val.one_channel_defn_;

		return os;
	}
	
	// --------
	struct xml_data_source_t
	{
		static const std::uint32_t TagValueSize = 5;

		tag_value_t<pqdif_guid_t> type_id_ = {tagDataSourceTypeID};
		tag_value_t<pqdif_guid_t> vendor_id_ = {tagVendorID};
		tag_value_t<pqdif_guid_t> equipment_id_ = {tagEquipmentID};
		tag_value_t<std::string> effective_ = {tagEffective};
		tag_value_t<channel_defns_t> channel_defns_ = {tagChannelDefns};

		std::pair<std::uint32_t, std::uint32_t> element_cnt() const
		{
			std::uint32_t list_cnt = 1;
			std::uint32_t element_size = TagValueSize;

			auto ret = channel_defns_.value_.element_cnt();
			list_cnt += ret.first;
			element_size += ret.second;

			return {list_cnt, element_size}; 
		}
	};

	template < typename StreamT >
	StreamT &operator<<(StreamT &os, const xml_data_source_t &val)
	{
		os << tag_size_t{xml_data_source_t::TagValueSize}
			<< val.type_id_
			<< val.vendor_id_
			<< val.equipment_id_
			<< val.effective_
			<< val.channel_defns_;

		return os;
	}

	template < typename StreamT >
	StreamT &operator>>(StreamT &os, xml_data_source_t &val)
	{
		tag_size_t size = {0};
		os >> size
			>> val.type_id_
			>> val.vendor_id_
			>> val.equipment_id_
			>> val.effective_
			>> val.channel_defns_;

		assert(size == xml_data_source_t::TagValueSize);
		return os;
	}
}
}
#endif