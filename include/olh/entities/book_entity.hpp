#ifndef BOOK_ENTITY_H
#define BOOK_ENTITY_H

#include <optional>
#include <string>

#include "entities/entity.hpp"

namespace olh {

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

    std::optional<unsigned int> get_id() const override;
    void set_id(const unsigned int id) override;

    std::string get_title() const;
    void set_title(const std::string& title);

    std::string get_author() const;
    void set_author(const std::string& author);

    std::string get_section() const;
    void set_section(const std::string& section);

    unsigned int get_pages() const;
    void set_pages(const unsigned int pages);

    unsigned int get_year() const;
    void set_year(const unsigned int year);

    unsigned int get_stock() const;
    void set_stock(const unsigned int stock);
};

}  // namespace olh

#endif  // BOOK_ENTITY_H
