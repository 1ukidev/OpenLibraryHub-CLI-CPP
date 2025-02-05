#include "entities/AlunoEntity.hpp"

#include <boost/mysql/row_view.hpp>
#include <string>
#include <unordered_map>

std::string AlunoEntity::toString() const
{
    return "Id: " + std::to_string(id_) + '\n' +
           "Nome: " + nome_ + '\n' +
           "Turma: " + std::to_string(turmaEntity_.getId()) + '\n';
}

const std::unordered_map<std::string, std::string> AlunoEntity::getColumns() const
{
    return {
        {"nome", nome_},
        {"turma", std::to_string(turmaEntity_.getId())}
    };
}

void AlunoEntity::fromRowSet(const boost::mysql::row_view& row)
{
    if (!row.empty()) {
        id_ = row[0].get_uint64();
        nome_ = row[1].get_string();
        turmaEntity_.setId(row[2].get_uint64());
    }
}
