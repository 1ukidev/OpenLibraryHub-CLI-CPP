#pragma once

#include <optional>
#include <string>

class Entity
{
public:
    virtual ~Entity() = default;
    virtual std::optional<unsigned long> getId() const = 0;
    virtual void setId(unsigned long id) = 0;
    virtual std::string toString() const = 0;
};
