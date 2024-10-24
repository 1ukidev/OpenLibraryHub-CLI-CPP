#pragma once

#include "entities/BookEntity.hpp"
#include "entities/Entity.hpp"
#include "entities/StudentEntity.hpp"

#include <chrono>
#include <optional>

class LoanEntity : public Entity
{
private:
    std::optional<unsigned long> id;
    BookEntity bookEntity;
    StudentEntity studentEntity;
    std::chrono::system_clock::time_point loanDate;
    std::chrono::system_clock::time_point returnDate;

public:
    LoanEntity(const BookEntity& bookEntity, const StudentEntity& studentEntity,
               const std::chrono::system_clock::time_point& loanDate,
               const std::chrono::system_clock::time_point& returnDate);

    LoanEntity() = default;
    ~LoanEntity() = default;

    std::optional<unsigned long> getId() const override;
    void setId(unsigned long id) override;

    BookEntity getBookEntity() const;
    void setBookEntity(const BookEntity& bookEntity);

    StudentEntity getStudentEntity() const;
    void setStudentEntity(const StudentEntity& studentEntity);

    std::chrono::system_clock::time_point getLoanDate() const;
    void setLoanDate(const std::chrono::system_clock::time_point& loanDate);

    std::chrono::system_clock::time_point getReturnDate() const;
    void setReturnDate(const std::chrono::system_clock::time_point& returnDate);

    std::string toString() const override;
};
