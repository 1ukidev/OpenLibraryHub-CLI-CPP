#pragma once

#include "entities/Entity.hpp"

#include <string>
#include <string_view>

class BookEntity : public Entity
{
public:
    BookEntity(std::string_view title, std::string_view author,
               std::string_view section, unsigned int pages,
               unsigned int year, unsigned int stock);
    BookEntity(unsigned long id);

    BookEntity() = default;
    ~BookEntity() override = default;

    std::string toString() const override;

    unsigned long id;
    std::string title;
    std::string author;
    std::string section;
    unsigned int pages;
    unsigned int year;
    unsigned int stock;
};
