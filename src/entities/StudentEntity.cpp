#include "entities/StudentEntity.hpp"
#include "entities/ClassEntity.hpp"

#include <optional>
#include <string>
#include <string_view>

StudentEntity::StudentEntity(std::string_view name, const ClassEntity& classEntity)
    : name(name), classEntity(classEntity) {}

std::optional<unsigned long> StudentEntity::getId() const
{
    return id;
}

void StudentEntity::setId(unsigned long id)
{
    this->id = id;
}

std::string StudentEntity::getName() const
{
    return name;
}

void StudentEntity::setName(std::string_view name)
{
    this->name = name;
}

ClassEntity StudentEntity::getClassEntity() const
{
    return classEntity;
}

void StudentEntity::setClassEntity(const ClassEntity& classEntity)
{
    this->classEntity = classEntity;
}

std::string StudentEntity::toString() const
{
    return "Id: " + std::to_string(id.value()) + '\n' +
           "Nome: " + name + '\n' +
           "Turma: " + std::to_string(classEntity.getId().value()) + '\n';
}
