#pragma once

#include "dao/DAO.hpp"
#include "entities/BookEntity.hpp"

#include <string>
#include <vector>

class BookDAO : public DAO<BookEntity>
{
public:
    BookDAO() = default;
    ~BookDAO() = default;

    bool save(const BookEntity& entity) override;
    bool update(const BookEntity& entity) override;
    bool _delete(const std::string& where) override;
    std::vector<BookEntity> search(const std::string& where) override;
};
