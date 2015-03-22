#ifndef __PQDIF_ENGINE_HPP
#define __PQDIF_ENGINE_HPP

#include "config.hpp"

#include "data_source.hpp"
#include "observation.hpp"



namespace pqdif {

	class engine_t
	{
		struct impl;
		std::unique_ptr<impl> impl_;

	public:
		engine_t(const error_handler_t &);
		~engine_t();

		engine_t(const engine_t &) = delete;
		engine_t &operator=(const engine_t &) = delete;

		bool start(const std::string &xml_path, const std::string &pqdif_path);
		bool stop();

		const data_source::xml_data_source_t &get_data_source() const;
		const std::vector<observation::xml_observation_t> &get_observations() const;

		void put_observation(const observation::xml_observation_t &);
	};
}

#endif