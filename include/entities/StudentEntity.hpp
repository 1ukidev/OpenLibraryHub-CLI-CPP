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
    ~StudentEntity() = default;

    unsigned long getId() const override;
    void setId(unsigned long id) override;

    std::string getName() const;
    void setName(std::string_view name);

    ClassEntity getClassEntity() const;
    void setClassEntity(const ClassEntity& classEntity);

    std::string toString() const override;

private:
    unsigned long id;
    std::string name;
    ClassEntity classEntity;
};
