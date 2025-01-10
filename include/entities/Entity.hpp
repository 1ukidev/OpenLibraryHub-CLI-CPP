#pragma once

#include <string>

class Entity
{
public:
    virtual ~Entity() = default;
    virtual std::string toString() const = 0;
};
