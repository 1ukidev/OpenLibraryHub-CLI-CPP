#include "entities/AlunoEntity.hpp"
#include "entities/TurmaEntity.hpp"

#include <string>

std::string AlunoEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Nome: " + nome + '\n' +
           "Turma: " + std::to_string(turmaEntity.getId()) + '\n';
}
