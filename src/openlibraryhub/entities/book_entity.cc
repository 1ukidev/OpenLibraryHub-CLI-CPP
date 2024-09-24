#include <optional>

#include "entities/book_entity.h"

olh::book_entity::book_entity(std::string title, std::string author,
							  std::string section, unsigned int pages,
							  unsigned int year, unsigned int stock)
	: title(title), author(author), section(section),
	  pages(pages), year(year), stock(stock) {}

std::optional<unsigned int> olh::book_entity::getId() const
{
	return id;
}

void olh::book_entity::setId(const unsigned int& id)
{
	this->id = id;
}

std::string olh::book_entity::getTitle() const
{
	return title;
}

void olh::book_entity::setTitle(const std::string& title)
{
	this->title = title;
}

std::string olh::book_entity::getAuthor() const
{
	return author;
}

void olh::book_entity::setAuthor(const std::string& author)
{
	this->author = author;
}

std::string olh::book_entity::getSection() const
{
	return section;
}

void olh::book_entity::setSection(const std::string& section)
{
	this->section = section;
}

unsigned int olh::book_entity::getPages() const
{
	return pages;
}

void olh::book_entity::setPages(const unsigned int& pages)
{
	this->pages = pages;
}

unsigned int olh::book_entity::getYear() const
{
	return year;
}

void olh::book_entity::setYear(const unsigned int& year)
{
	this->year = year;
}

unsigned int olh::book_entity::getStock() const
{
	return stock;
}

void olh::book_entity::setStock(const unsigned int& stock)
{
	this->stock = stock;
}
