#pragma once

#include "dao/DAO.hpp"
#include "entities/BookEntity.hpp"

#include <string>
#include <vector>

class BookDAO : public DAO<BookEntity>
{
public:
    BookDAO() = default;
    ~BookDAO() override = default;

    bool save(const BookEntity& entity) override;
    bool update(const BookEntity& entity) override;
    bool remove(const std::string& where) override;
    std::vector<BookEntity> search(const std::string& where) override;
};
