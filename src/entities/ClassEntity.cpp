#include "entities/ClassEntity.hpp"

#include <string>
#include <string_view>

ClassEntity::ClassEntity(std::string_view name) : name(name) {}
ClassEntity::ClassEntity(unsigned long id) : id(id) {}

unsigned long ClassEntity::getId() const
{
    return id;
}

void ClassEntity::setId(unsigned long id)
{
    this->id = id;
}

std::string ClassEntity::getName() const
{
    return name;
}

void ClassEntity::setName(std::string_view name)
{
    this->name = name;
}

std::string ClassEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Nome: " + name + '\n';
}
