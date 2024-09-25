#include <optional>

#include "entities/book_entity.hpp"

olh::book_entity::book_entity(std::string title, std::string author,
                              std::string section, unsigned int pages,
                              unsigned int year, unsigned int stock)
    : title(title), author(author), section(section),
      pages(pages), year(year), stock(stock) {}

std::optional<unsigned int> olh::book_entity::get_id() const
{
    return id;
}

void olh::book_entity::set_id(const unsigned int id)
{
    this->id = id;
}

std::string olh::book_entity::get_title() const
{
    return title;
}

void olh::book_entity::set_title(const std::string& title)
{
    this->title = title;
}

std::string olh::book_entity::get_author() const
{
    return author;
}

void olh::book_entity::set_author(const std::string& author)
{
    this->author = author;
}

std::string olh::book_entity::get_section() const
{
    return section;
}

void olh::book_entity::set_section(const std::string& section)
{
    this->section = section;
}

unsigned int olh::book_entity::get_pages() const
{
    return pages;
}

void olh::book_entity::set_pages(const unsigned int pages)
{
    this->pages = pages;
}

unsigned int olh::book_entity::get_year() const
{
    return year;
}

void olh::book_entity::set_year(const unsigned int year)
{
    this->year = year;
}

unsigned int olh::book_entity::get_stock() const
{
    return stock;
}

void olh::book_entity::set_stock(const unsigned int stock)
{
    this->stock = stock;
}
