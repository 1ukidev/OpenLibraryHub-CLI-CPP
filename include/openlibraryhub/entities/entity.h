#ifndef ENTITY_H
#define ENTITY_H

#include <optional>

namespace olh
{
	class entity
	{
	public:
		virtual std::optional<unsigned int> getId() const = 0;
		virtual void setId(const unsigned int& id) = 0;
	};
}

#endif // ENTITY_H
