#include "BookEntity.h"

int BookEntity::getId() const
{
	return this->id;
}

BookEntity& BookEntity::setId(int id)
{
	this->id = id;
	return *this;
}

std::string BookEntity::getTitle() const
{
	return this->title;
}

BookEntity& BookEntity::setTitle(std::string title)
{
	this->title = title;
	return *this;
}

std::string BookEntity::getAuthor() const
{
	return this->author;
}

BookEntity& BookEntity::setAuthor(std::string author)
{
	this->author = author;
	return *this;
}

std::string BookEntity::getSection() const
{
	return this->section;
}

BookEntity& BookEntity::setSection(std::string section)
{
	this->section = section;
	return *this;
}

unsigned int BookEntity::getPages() const
{
	return this->pages;
}

BookEntity& BookEntity::setPages(unsigned int pages)
{
	this->pages = pages;
	return *this;
}

unsigned int BookEntity::getYear() const
{
	return this->year;
}

BookEntity& BookEntity::setYear(unsigned int year)
{
	this->year = year;
	return *this;
}

unsigned int BookEntity::getStock() const
{
	return this->stock;
}

BookEntity& BookEntity::setStock(unsigned int stock)
{
	this->stock = stock;
	return *this;
}
