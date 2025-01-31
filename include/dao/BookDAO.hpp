#pragma once

#include "dao/DAO.hpp"
#include "entities/BookEntity.hpp"

class BookDAO : public DAO<BookEntity>
{
public:
    BookDAO(const BookDAO&) = delete;
    BookDAO& operator=(const BookDAO&) = delete;
    static BookDAO& getInstance();

private:
    BookDAO() = default;
    ~BookDAO() override = default;
};
