#ifndef ENTITY_H
#define ENTITY_H

#include <optional>

namespace olh {

class entity
{
public:
    virtual ~entity() = default;
    virtual std::optional<unsigned int> get_id() const = 0;
    virtual void set_id(const unsigned int id) = 0;
};

}  // namespace olh

#endif  // ENTITY_H
