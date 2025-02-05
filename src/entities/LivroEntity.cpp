#include "entities/LivroEntity.hpp"

#include <boost/mysql/row_view.hpp>
#include <string>
#include <unordered_map>

std::string LivroEntity::toString() const
{
    return "Id: " + std::to_string(id_) + '\n' +
           "Título: " + titulo_ + '\n' +
           "Autor: " + autor_ + '\n' +
           "Seção: " + secao_ + '\n' +
           "Páginas: " + std::to_string(paginas_) + '\n' +
           "Ano: " + std::to_string(ano_) + '\n' +
           "Estoque: " + std::to_string(estoque_) + '\n';
}

const std::unordered_map<std::string, std::string> LivroEntity::getColumns() const
{
    return {
        {"titulo", titulo_},
        {"autor", autor_},
        {"secao", secao_},
        {"paginas", std::to_string(paginas_)},
        {"ano", std::to_string(ano_)},
        {"estoque", std::to_string(estoque_)}
    };
}

void LivroEntity::fromRowSet(const boost::mysql::row_view& row)
{
    if (!row.empty()) {
        id_ = row[0].get_uint64();
        titulo_ = row[1].get_string();
        autor_ = row[2].get_string();
        secao_ = row[3].get_string();
        paginas_ = row[4].get_uint64();
        ano_ = row[5].get_uint64();
        estoque_ = row[6].get_uint64();
    }
}
