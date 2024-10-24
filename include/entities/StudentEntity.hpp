#pragma once

#include "entities/ClassEntity.hpp"
#include "entities/Entity.hpp"

#include <optional>
#include <string>
#include <string_view>

class StudentEntity : public Entity
{
private:
    std::optional<unsigned long> id;
    std::string name;
    ClassEntity classEntity;

public:
    StudentEntity(std::string_view name, const ClassEntity& classEntity);

    StudentEntity() = default;
    ~StudentEntity() = default;

    std::optional<unsigned long> getId() const override;
    void setId(unsigned long id) override;

    std::string getName() const;
    void setName(std::string_view name);

    ClassEntity getClassEntity() const;
    void setClassEntity(const ClassEntity& classEntity);

    std::string toString() const override;
};
