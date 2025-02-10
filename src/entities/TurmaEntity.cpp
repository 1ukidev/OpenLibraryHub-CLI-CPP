#include "entities/TurmaEntity.hpp"

#include <boost/mysql/row_view.hpp>
#include <string>
#include <unordered_map>

std::string TurmaEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Nome: " + nome + '\n';
}

const std::unordered_map<std::string, std::string> TurmaEntity::getColumns() const
{
    return { {"nome", nome} };
}

void TurmaEntity::fromRowSet(const boost::mysql::row_view& row)
{
    if (!row.empty()) {
        id = row[0].get_uint64();
        nome = row[1].get_string();
    }
}
