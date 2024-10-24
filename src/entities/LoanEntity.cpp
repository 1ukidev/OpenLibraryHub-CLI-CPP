#include "entities/LoanEntity.hpp"
#include "entities/BookEntity.hpp"
#include "entities/StudentEntity.hpp"

#include <chrono>
#include <optional>

LoanEntity::LoanEntity(const BookEntity& bookEntity, const StudentEntity& studentEntity,
                       const std::chrono::system_clock::time_point& loanDate,
                       const std::chrono::system_clock::time_point& returnDate)
    : bookEntity(bookEntity), studentEntity(studentEntity),
      loanDate(loanDate), returnDate(returnDate) {}

std::optional<unsigned long> LoanEntity::getId() const
{
    return id;
}

void LoanEntity::setId(unsigned long id)
{
    this->id = id;
}

BookEntity LoanEntity::getBookEntity() const
{
    return bookEntity;
}

void LoanEntity::setBookEntity(const BookEntity& bookEntity)
{
    this->bookEntity = bookEntity;
}

StudentEntity LoanEntity::getStudentEntity() const
{
    return studentEntity;
}

void LoanEntity::setStudentEntity(const StudentEntity& studentEntity)
{
    this->studentEntity = studentEntity;
}

std::chrono::system_clock::time_point LoanEntity::getLoanDate() const
{
    return loanDate;
}

void LoanEntity::setLoanDate(const std::chrono::system_clock::time_point& loanDate)
{
    this->loanDate = loanDate;
}

std::chrono::system_clock::time_point LoanEntity::getReturnDate() const
{
    return returnDate;
}

void LoanEntity::setReturnDate(const std::chrono::system_clock::time_point& returnDate)
{
    this->returnDate = returnDate;
}

std::string LoanEntity::toString() const
{
    return "Id: " + std::to_string(id.value()) + "\n" +
           "Livro: " + bookEntity.toString() + "\n" +
           "Estudante: " + studentEntity.toString() + "\n" +
           "Data de empréstimo: " + std::to_string(std::chrono::system_clock::to_time_t(loanDate)) + "\n" +
           "Data de devolução: " + std::to_string(std::chrono::system_clock::to_time_t(returnDate));
}
