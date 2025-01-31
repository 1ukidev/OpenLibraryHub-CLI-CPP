#include "entities/BookEntity.hpp"

#include <string>

std::string BookEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Título: " + title + '\n' +
           "Autor: " + author + '\n' +
           "Seção: " + section + '\n' +
           "Páginas: " + std::to_string(pages) + '\n' +
           "Ano: " + std::to_string(year) + '\n' +
           "Estoque: " + std::to_string(stock) + '\n';
}
