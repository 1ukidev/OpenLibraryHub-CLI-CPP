#pragma once

#include "entities/Entity.hpp"

#include <string>
#include <string_view>

class ClassEntity : public Entity
{
public:
    ClassEntity(std::string_view name);
    ClassEntity(unsigned long id);

    ClassEntity() = default;
    ~ClassEntity() = default;

    std::string toString() const override;

    unsigned long id;
    std::string name;
};
