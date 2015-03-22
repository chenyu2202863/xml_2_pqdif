#ifndef __PQDIF_IMPL_BUFFER_HPP
#define __PQDIF_IMPL_BUFFER_HPP

#include <cstdint>
#include <memory>
#include <vector>

namespace pqdif { namespace impl {

	using buffer_t = std::pair<std::shared_ptr<char>, std::uint32_t>;

	inline buffer_t make_buffer(std::uint32_t size)
	{
		auto p = ::operator new(size);
		std::memset(p, 0, size);

		return std::make_pair(std::shared_ptr<char>(reinterpret_cast<char *>(p), [](char *p)
			{
				::operator delete(p);
			}), size
		);
	}

	/*struct buffer_t
		: std::vector<char>
		{
		buffer_t(std::uint32_t size)
		: std::vector<char>(size)
		{}

		buffer_t() = default;
		buffer_t(buffer_t &&rhs) = default;
		buffer_t &operator=(buffer_t &&rhs) = default;

		buffer_t(const buffer_t &) = delete;
		buffer_t &operator=(const buffer_t &) = delete;
		};

		inline buffer_t make_buffer(std::uint32_t size)
		{
		return buffer_t(size);
		}*/
}
}

#endif