#pragma once

#include "util.h"

class BookEntity
{
private:
	std::string title;
	std::string author;
	std::string section;
	unsigned int pages;
	unsigned int year;
	unsigned int stock;
public:
	std::string getTitle() const;
	BookEntity& setTitle(std::string title);
	std::string getAuthor() const;
	BookEntity& setAuthor(std::string author);
	std::string getSection() const;
	BookEntity& setSection(std::string section);
	unsigned int getPages() const;
	BookEntity& setPages(unsigned int pages);
	unsigned int getYear() const;
	BookEntity& setYear(unsigned int year);
	unsigned int getStock() const;
	BookEntity& setStock(unsigned int stock);
};
