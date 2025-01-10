#pragma once

#include "entities/BookEntity.hpp"
#include "entities/Entity.hpp"
#include "entities/StudentEntity.hpp"

#include <chrono>

class LoanEntity : public Entity
{
public:
    LoanEntity(const BookEntity& bookEntity, const StudentEntity& studentEntity,
               const std::chrono::system_clock::time_point& loanDate,
               const std::chrono::system_clock::time_point& returnDate);

    LoanEntity() = default;
    ~LoanEntity() = default;

    std::string toString() const override;

    unsigned long id;
    BookEntity bookEntity;
    StudentEntity studentEntity;
    std::chrono::system_clock::time_point loanDate;
    std::chrono::system_clock::time_point returnDate;
};
