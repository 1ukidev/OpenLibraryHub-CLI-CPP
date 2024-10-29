#include "entities/BookEntity.hpp"

#include <string>
#include <string_view>

BookEntity::BookEntity(std::string_view title, std::string_view author,
                       std::string_view section, unsigned int pages,
                       unsigned int year, unsigned int stock)
    : title(title), author(author), section(section),
      pages(pages), year(year), stock(stock) {}
BookEntity::BookEntity(unsigned long id) : id(id) {}

unsigned long BookEntity::getId() const
{
    return id;
}

void BookEntity::setId(unsigned long id)
{
    this->id = id;
}

std::string BookEntity::getTitle() const
{
    return title;
}

void BookEntity::setTitle(std::string_view title)
{
    this->title = title;
}

std::string BookEntity::getAuthor() const
{
    return author;
}

void BookEntity::setAuthor(std::string_view author)
{
    this->author = author;
}

std::string BookEntity::getSection() const
{
    return section;
}

void BookEntity::setSection(std::string_view section)
{
    this->section = section;
}

unsigned int BookEntity::getPages() const
{
    return pages;
}

void BookEntity::setPages(unsigned int pages)
{
    this->pages = pages;
}

unsigned int BookEntity::getYear() const
{
    return year;
}

void BookEntity::setYear(unsigned int year)
{
    this->year = year;
}

unsigned int BookEntity::getStock() const
{
    return stock;
}

void BookEntity::setStock(unsigned int stock)
{
    this->stock = stock;
}

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
