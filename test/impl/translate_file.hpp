#ifndef __PQDIF_TRANSLATE_FILE_IMPL_HPP
#define __PQDIF_TRANSLATE_FILE_IMPL_HPP

#include <fstream>

#include "../config.hpp"


namespace pqdif {
	namespace container {
		struct xml_container_t;
	}

	namespace data_source {
		struct xml_data_source_t;
	}

	namespace monitor {
		struct xml_monitor_setting_t;
	}

	namespace observation {
		struct xml_observation_t;
	}
}

namespace pqdif { namespace impl {

	class translate_file_t
	{
		std::fstream os_;
		std::uint32_t offset_ = 0;

	public:

		bool open(const std::string &path);
		void close();

		void read(container::xml_container_t &container, data_source::xml_data_source_t &, std::vector<observation::xml_observation_t> &);
		void translate(
			const container::xml_container_t &, 
			const data_source::xml_data_source_t &,
			const monitor::xml_monitor_setting_t &);
		void write_observation(const observation::xml_observation_t &);
	};
}}

#endif