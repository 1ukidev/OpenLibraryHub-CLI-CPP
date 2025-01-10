#include "entities/LoanEntity.hpp"
#include "Util.hpp"
#include "entities/BookEntity.hpp"
#include "entities/StudentEntity.hpp"

#include <chrono>

LoanEntity::LoanEntity(const BookEntity& bookEntity, const StudentEntity& studentEntity,
                       const std::chrono::system_clock::time_point& loanDate,
                       const std::chrono::system_clock::time_point& returnDate)
    : bookEntity(bookEntity), studentEntity(studentEntity),
      loanDate(loanDate), returnDate(returnDate) {}

std::string LoanEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Livro: " + std::to_string(bookEntity.id) + '\n' +
           "Estudante: " + std::to_string(studentEntity.id) + '\n' +
           "Data de empréstimo: " + Util::timePointToString(loanDate) + '\n' +
           "Data de devolução: " + Util::timePointToString(returnDate) + '\n';
}
