#include "entities/TurmaEntity.hpp"

#include <string>

std::string TurmaEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Nome: " + nome + '\n';
}
