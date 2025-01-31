#include "entities/StudentEntity.hpp"
#include "entities/ClassEntity.hpp"

#include <string>

std::string StudentEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Nome: " + name + '\n' +
           "Turma: " + std::to_string(classEntity.getId()) + '\n';
}
