#pragma once

#include "entities/ClassEntity.hpp"
#include "entities/Entity.hpp"

#include <string>
#include <string_view>

class StudentEntity : public Entity
{
public:
    StudentEntity(std::string_view name, const ClassEntity& classEntity);
    StudentEntity(unsigned long id);

    StudentEntity() = default;
    ~StudentEntity() override = default;

    std::string toString() const override;

    unsigned long id;
    std::string name;
    ClassEntity classEntity;
};
