#include "entities/ClassEntity.hpp"

#include <string>
#include <string_view>

ClassEntity::ClassEntity(std::string_view name) : name(name) {}
ClassEntity::ClassEntity(unsigned long id) : id(id) {}

std::string ClassEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Nome: " + name + '\n';
}
