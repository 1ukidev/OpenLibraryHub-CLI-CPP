#ifndef BOOK_ENTITY_H
#define BOOK_ENTITY_H

#include <optional>
#include <string>

#include "entities/entity.h"

namespace olh
{
	class book_entity : public entity
	{
	private:
		std::optional<unsigned int> id;
		std::string title;
		std::string author;
		std::string section;
		unsigned int pages;
		unsigned int year;
		unsigned int stock;

	public:
		book_entity(std::string title, std::string author,
					std::string section, unsigned int pages,
					unsigned int year, unsigned int stock);

		book_entity() = default;
		~book_entity() = default;

		std::optional<unsigned int> getId() const;
		void setId(const unsigned int& id);

		std::string getTitle() const;
		void setTitle(const std::string& title);

		std::string getAuthor() const;
		void setAuthor(const std::string& author);

		std::string getSection() const;
		void setSection(const std::string& section);

		unsigned int getPages() const;
		void setPages(const unsigned int& pages);

		unsigned int getYear() const;
		void setYear(const unsigned int& year);

		unsigned int getStock() const;
		void setStock(const unsigned int& stock);
	};
}

#endif // BOOK_ENTITY_H
