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

    void save(BookEntity& entity) override;
    void update(BookEntity& entity) override;
    bool _delete(const std::string& where) override;
    std::vector<BookEntity> search(const std::string& where) override;
};
