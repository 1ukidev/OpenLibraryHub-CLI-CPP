#pragma once

#include "Util.h"

class BookEntity
{
private:
	int id = empty;
	std::string title;
	std::string author;
	std::string section;
	unsigned int pages;
	unsigned int year;
	unsigned int stock;
public:
	BookEntity(std::string title, std::string author,
			   std::string section, unsigned int pages,
			   unsigned int year, unsigned int stock) {
		this->title = title;
		this->author = author;
		this->section = section;
		this->pages = pages;
		this->year = year;
		this->stock = stock;
	}

	int getId() const;
	BookEntity& setId(int id);

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
