#pragma once

#include "entities/Entity.hpp"

#include <optional>
#include <string>
#include <string_view>

class BookEntity : public Entity
{
private:
    std::optional<unsigned long> id;
    std::string title;
    std::string author;
    std::string section;
    unsigned int pages;
    unsigned int year;
    unsigned int stock;

public:
    BookEntity(std::string title, std::string author,
               std::string section, unsigned int pages,
               unsigned int year, unsigned int stock);

    BookEntity() = default;
    ~BookEntity() = default;

    std::optional<unsigned long> getId() const override;
    void setId(unsigned long id) override;

    std::string getTitle() const;
    void setTitle(std::string_view title);

    std::string getAuthor() const;
    void setAuthor(std::string_view author);

    std::string getSection() const;
    void setSection(std::string_view section);

    unsigned int getPages() const;
    void setPages(unsigned int pages);

    unsigned int getYear() const;
    void setYear(unsigned int year);

    unsigned int getStock() const;
    void setStock(unsigned int stock);

    std::string toString() const override;
};
