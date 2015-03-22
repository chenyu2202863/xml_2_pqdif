#ifndef __PQDIF_IMPL_BUFFER_TO_ELEMENT_HPP
#define __PQDIF_IMPL_BUFFER_TO_ELEMENT_HPP

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

	void buffer_to_container(const buffer_t &, container::xml_container_t &);
	void buffer_to_data_source(const buffer_t &, data_source::xml_data_source_t &);
	void buffer_to_monitor_setting(const buffer_t &, monitor::xml_monitor_setting_t &);
	void buffer_to_observation(const buffer_t &, observation::xml_observation_t &);
}
}

#endif