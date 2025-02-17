#include "entities/LivroEntity.hpp"

#include <boost/mysql/row_view.hpp>
#include <string>
#include <unordered_map>

std::string LivroEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Título: " + titulo + '\n' +
           "Autor: " + autor + '\n' +
           "Seção: " + secao + '\n' +
           "Páginas: " + std::to_string(paginas) + '\n' +
           "Ano: " + std::to_string(ano) + '\n' +
           "Estoque: " + std::to_string(estoque) + '\n';
}

const std::unordered_map<std::string, std::string> LivroEntity::getColumns() const
{
    return {
        {"titulo", titulo},
        {"autor", autor},
        {"secao", secao},
        {"paginas", std::to_string(paginas)},
        {"ano", std::to_string(ano)},
        {"estoque", std::to_string(estoque)}
    };
}

void LivroEntity::fromRowSet(const boost::mysql::row_view& row)
{
    if (!row.empty()) {
        id = row[0].get_uint64();
        titulo = row[1].get_string();
        autor = row[2].get_string();
        secao = row[3].get_string();
        paginas = row[4].get_uint64();
        ano = row[5].get_uint64();
        estoque = row[6].get_uint64();
    }
}
