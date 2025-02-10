#include "entities/AlunoEntity.hpp"

#include <boost/mysql/row_view.hpp>
#include <string>
#include <unordered_map>

std::string AlunoEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Nome: " + nome + '\n' +
           "Turma: " + std::to_string(turmaEntity.id) + '\n';
}

const std::unordered_map<std::string, std::string> AlunoEntity::getColumns() const
{
    return {
        {"nome", nome},
        {"turma", std::to_string(turmaEntity.id)}
    };
}

void AlunoEntity::fromRowSet(const boost::mysql::row_view& row)
{
    if (!row.empty()) {
        id = row[0].get_uint64();
        nome = row[1].get_string();
        turmaEntity.id = row[2].get_uint64();
    }
}
