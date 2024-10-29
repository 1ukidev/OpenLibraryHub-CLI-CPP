#pragma once

#include <string>

class Entity
{
public:
    virtual ~Entity() = default;
    virtual unsigned long getId() const = 0;
    virtual void setId(unsigned long id) = 0;
    virtual std::string toString() const = 0;
};
