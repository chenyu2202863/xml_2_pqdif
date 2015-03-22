#include "config.hpp"

#include "impl/algorithm.hpp"

namespace pqdif {

	pqdif_multi_value_t string_2_id(convert_t<pqdif_multi_value_t> &c, const std::string &val)
	{
		std::vector<std::string> vals;
		stdex::split(vals, val, '|');

		pqdif_multi_value_t ret;
		std::for_each(vals.cbegin(), vals.cend(),
			[&ret, &c](const std::string &v)
		{
			ret |= c.string_to_id_[v];
		});

		return ret;
	}

#define DEFINE_TAG(id) {string_2_guid_[#id] = id; guid_2_string_[id] = #id;};
	struct guid_string_convert_t
	{
		std::map<std::string, pqdif_guid_t> string_2_guid_;
		std::map<pqdif_guid_t, std::string> guid_2_string_;
	
		guid_string_convert_t()
		{
			// 公共部分
			DEFINE_TAG(guidRecordSignaturePQDIF)
			DEFINE_TAG(tagBlank)
			
			// 暂定的文档结构
			DEFINE_TAG(tagContainer)
				DEFINE_TAG(tagVersionInfo)
				DEFINE_TAG(tagCreation)
				DEFINE_TAG(tagFileName)
				DEFINE_TAG(tagCompressionStyleID)
				DEFINE_TAG(tagCompressionAlgorithmID)
				DEFINE_TAG(tagCompressionChecksum)
				
			DEFINE_TAG(tagRecDataSource)
				DEFINE_TAG(tagDataSourceTypeID)
				DEFINE_TAG(tagVendorID)
				DEFINE_TAG(tagEquipmentID)
				DEFINE_TAG(tagEffective)
				DEFINE_TAG(tagChannelDefns)
					DEFINE_TAG(tagOneChannelDefn)
						DEFINE_TAG(tagChannelName)
						DEFINE_TAG(tagPhaseID)
						DEFINE_TAG(tagQuantityTypeID)
						DEFINE_TAG(tagQuantityMeasuredID)
						DEFINE_TAG(tagSeriesDefns)
							DEFINE_TAG(tagOneSeriesDefn)
								DEFINE_TAG(tagValueTypeID)
								DEFINE_TAG(tagQuantityUnitsID)
								DEFINE_TAG(tagQuantityCharacteristicID)
								DEFINE_TAG(tagStorageMethodID)
								DEFINE_TAG(tagHintGreekPrefixID)
								DEFINE_TAG(tagQuantityCharacteristicID)
								

			DEFINE_TAG(tagRecMonitorSettings)
				DEFINE_TAG(tagTimeInstalled)
				DEFINE_TAG(tagUseCalibration)
				DEFINE_TAG(tagUseTransducer)
				DEFINE_TAG(tagNominalFrequency)
				DEFINE_TAG(tagSettingPhysicalConnection)

				DEFINE_TAG(tagChannelSettingsArray)
					DEFINE_TAG(tagOneChannelSetting)
					DEFINE_TAG(tagChannelDefnIdx)
				
			DEFINE_TAG(tagRecObservation)
				DEFINE_TAG(tagObservationName)				
				DEFINE_TAG(tagTimeCreate)
				DEFINE_TAG(tagTimeStart)
				DEFINE_TAG(tagTriggerMethodID)
				DEFINE_TAG(tagTimeTriggered)
				DEFINE_TAG(tagChannelTriggerIdx)
				DEFINE_TAG(tagChannelInstances)
					DEFINE_TAG(tagOneChannelInst)
						DEFINE_TAG(tagChannelDefnIdx)
						DEFINE_TAG(tagCharactFrequency)
						DEFINE_TAG(tagChannelFrequency)
						DEFINE_TAG(tagSeriesInstances)
							DEFINE_TAG(tagOneSeriesInstance)
								DEFINE_TAG(tagSeriesOffset)
								DEFINE_TAG(tagSeriesScale)
								DEFINE_TAG(tagSeriesBaseQuantity)
								DEFINE_TAG(tagSeriesValues)

	
				// 备用的可选的标签
				DEFINE_TAG(tagLastSaved)
				DEFINE_TAG(tagTimesSaved)
				DEFINE_TAG(tagLanguage)
				DEFINE_TAG(tagTitle)
				DEFINE_TAG(tagSubject)
				DEFINE_TAG(tagAuthor)
				DEFINE_TAG(tagKeywords)
				DEFINE_TAG(tagComments)
				DEFINE_TAG(tagLastSavedBy)
				DEFINE_TAG(tagApplication)
				DEFINE_TAG(tagSecurity)
				DEFINE_TAG(tagOwner)
				DEFINE_TAG(tagCopyright)
				DEFINE_TAG(tagTrademarks)
				DEFINE_TAG(tagNotes)
				DEFINE_TAG(tagName)
				DEFINE_TAG(tagAddress1)
				DEFINE_TAG(tagAddress2)
				DEFINE_TAG(tagCity)
				DEFINE_TAG(tagState)
				DEFINE_TAG(tagPostalCode)
				DEFINE_TAG(tagCountry)
				DEFINE_TAG(tagPhoneVoice)
				DEFINE_TAG(tagPhoneFAX)
				DEFINE_TAG(tagEMail)
				DEFINE_TAG(tagCustomSourceInfo)
				DEFINE_TAG(tagSerialNumberDS)
				DEFINE_TAG(tagVersionDS)
				DEFINE_TAG(tagNameDS)
				DEFINE_TAG(tagOwnerDS)
				DEFINE_TAG(tagLocationDS)
				DEFINE_TAG(tagTimeZoneDS)
				DEFINE_TAG(tagCoordinatesDS)
				DEFINE_TAG(tagInstrumentTypeID)
				DEFINE_TAG(tagInstrumentModelName)
				DEFINE_TAG(tagInstrumentModelNumber)
				DEFINE_TAG(tagOtherChannelIdentifier)
				DEFINE_TAG(tagGroupName)
				DEFINE_TAG(tagPhysicalChannel)
				DEFINE_TAG(tagQuantityName)
				DEFINE_TAG(tagPrimarySeriesIdx)
				DEFINE_TAG(tagSeriesDefns)
				DEFINE_TAG(tagOneSeriesDefn)
				DEFINE_TAG(tagValueTypeID)
				DEFINE_TAG(tagQuantityUnitsID)
				DEFINE_TAG(tagQuantityCharacteristicID)
				DEFINE_TAG(tagQuantitySignificantDigitsID)
				DEFINE_TAG(tagQuantityResolutionID)
				DEFINE_TAG(tagStorageMethodID)
				DEFINE_TAG(tagValueTypeName)
				DEFINE_TAG(tagHintGreekPrefixID)
				DEFINE_TAG(tagHintPreferredUnitsID)
				DEFINE_TAG(tagHintDefaultDisplayID)
				DEFINE_TAG(tagProbInterval)
				DEFINE_TAG(tagProbPercentile)
				DEFINE_TAG(tagSeriesNominalQuantity)
				DEFINE_TAG(tagTimeInstalled)
				DEFINE_TAG(tagTimeRemoved)
				DEFINE_TAG(tagUseCalibration)
				DEFINE_TAG(tagUseTransducer)
				DEFINE_TAG(tagChannelSettingsArray)
				DEFINE_TAG(tagTriggerTypeID)
				DEFINE_TAG(tagFullScale)
				DEFINE_TAG(tagNoiseFloor)
				DEFINE_TAG(tagTriggerShapeParam)
				DEFINE_TAG(tagXDTransformerTypeID)
				DEFINE_TAG(tagXDSystemSideRatio)
				DEFINE_TAG(tagXDMonitorSideRatio)
				DEFINE_TAG(tagXDFrequencyResponse)
				DEFINE_TAG(tagCalTimeSkew)
				DEFINE_TAG(tagCalOffset)
				DEFINE_TAG(tagCalRatio)
				DEFINE_TAG(tagCalMustUseARCal)
				DEFINE_TAG(tagCalApplied)
				DEFINE_TAG(tagCalRecorded)
				DEFINE_TAG(tagTriggerHighHigh)
				DEFINE_TAG(tagTriggerHigh)
				DEFINE_TAG(tagTriggerLow)
				DEFINE_TAG(tagTriggerLowLow)
				DEFINE_TAG(tagTriggerDeadBand)
				DEFINE_TAG(tagTriggerRate)
				DEFINE_TAG(tagObservationSerial)
				DEFINE_TAG(tagObservationAggregationSerial)
				DEFINE_TAG(tagDisturbanceCategoryID)
				DEFINE_TAG(tagCharactDisturbDirection)
				DEFINE_TAG(tagCharactDisturbDirectionQuality)
				DEFINE_TAG(tagCharactDuration)			
				DEFINE_TAG(tagCharactMagnitude)	
				DEFINE_TAG(tagChanTriggerModuleInfo)
				DEFINE_TAG(tagChanTriggerModuleName)
				DEFINE_TAG(tagCrossTriggerDeviceName)
				DEFINE_TAG(tagCrossTriggerChanIdx)
				DEFINE_TAG(tagChanTriggerTypeID)
				
				DEFINE_TAG(tagChannelGroupID)
				DEFINE_TAG(tagSeriesShareChannelIdx)
				DEFINE_TAG(tagSeriesShareSeriesIdx)
				
		}
	};

	static const guid_string_convert_t convert;

	const pqdif_guid_t &string_2_GUID(const std::string &tag_name)
	{
		auto iter = convert.string_2_guid_.find(tag_name);
		if( iter == convert.string_2_guid_.end() )
		{
			throw std::logic_error("not found this tag name: " + tag_name);
		}

		return iter->second;
	}

	const std::string &GUID_2_string(const pqdif_guid_t &guid)
	{
		auto iter = convert.guid_2_string_.find(guid);
		if( iter == convert.guid_2_string_.end() )
		{
			throw std::logic_error("not found this guid");
		}

		return iter->second;
	}
}