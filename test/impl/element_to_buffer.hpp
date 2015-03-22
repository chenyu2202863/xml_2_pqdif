#ifndef __PQDIF_IMPL_ELEMENT_TO_BUFFER_HPP
#define __PQDIF_IMPL_ELEMENT_TO_BUFFER_HPP

#include "buffer.hpp"


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

	std::pair<buffer_t, buffer_t> container_to_buffer(const container::xml_container_t &);
	std::pair<buffer_t, buffer_t> data_source_to_buffer(const data_source::xml_data_source_t &);
	std::pair<buffer_t, buffer_t> monitor_setting_to_buffer(const monitor::xml_monitor_setting_t &);
	std::pair<buffer_t, buffer_t> observation_to_buffer(const observation::xml_observation_t &);
}
}

#endif