// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <filesystem>

#include "engine.hpp"


int _tmain(int argc, _TCHAR* argv[])
{
	pqdif::engine_t engine([](const std::string &msg)
	{
		std::cerr << msg << std::endl;
	});

//	std::tr2::sys::remove(std::tr2::sys::path("test.pqd"));
	if( !engine.start("pqdif.xml", "test1.pqd") )
	{
		assert(0);
		return false;
	}

	auto data_source = engine.get_data_source();

	
	pqdif::observation::xml_observation_t observation;
	observation.name_.value_ = "Group B";
	observation.create_time_.value_ = "1998-8-9";
	observation.start_time_.value_ = "2000-1-1";
	observation.trigger_method_id_.value_ = pqdif::observation::trigger::method_id_t::CHANNEL;

	pqdif::observation::one_series_instance_t one_series;
	one_series.series_offset_.value_ = 0;
	one_series.series_scale_.value_ = 1;
	one_series.series_values_.value_ = {1.1, 2.2, 3.3, 4.4, 5.5};

	pqdif::observation::series_instances_t series;
	series.one_series_inst_.value_ = {one_series, one_series, one_series};

	pqdif::observation::one_channel_instance_t one_channel;
	one_channel.defn_idx_.value_ = 106;
	one_channel.series_instances_.value_ = series;

	observation.channel_instances_.value_.one_instance_.value_ = {one_channel, one_channel};

	engine.put_observation(observation);

	auto observations = engine.get_observations();

	engine.stop();
	system("pause");
	return 0;
}

