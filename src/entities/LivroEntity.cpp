#include "entities/LivroEntity.hpp"

#include <string>

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
