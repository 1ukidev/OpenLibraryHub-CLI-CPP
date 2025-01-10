#include "entities/BookEntity.hpp"

#include <string>
#include <string_view>

BookEntity::BookEntity(std::string_view title, std::string_view author,
                       std::string_view section, unsigned int pages,
                       unsigned int year, unsigned int stock)
    : title(title), author(author), section(section),
      pages(pages), year(year), stock(stock) {}
BookEntity::BookEntity(unsigned long id) : id(id) {}

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
