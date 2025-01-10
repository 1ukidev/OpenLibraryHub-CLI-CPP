#include "entities/StudentEntity.hpp"
#include "entities/ClassEntity.hpp"

#include <string>
#include <string_view>

StudentEntity::StudentEntity(std::string_view name, const ClassEntity& classEntity)
    : name(name), classEntity(classEntity) {}
StudentEntity::StudentEntity(unsigned long id) : id(id) {}

std::string StudentEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Nome: " + name + '\n' +
           "Turma: " + std::to_string(classEntity.id) + '\n';
}
