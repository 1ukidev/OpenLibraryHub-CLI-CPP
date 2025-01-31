#include "entities/ClassEntity.hpp"

#include <string>

std::string ClassEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Nome: " + name + '\n';
}
