#include "entities/LoanEntity.hpp"
#include "Util.hpp"

#include <string>

std::string LoanEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Livro: " + std::to_string(bookEntity.getId()) + '\n' +
           "Estudante: " + std::to_string(studentEntity.getId()) + '\n' +
           "Data de empréstimo: " + Util::timePointToString(loanDate) + '\n' +
           "Data de devolução: " + Util::timePointToString(returnDate) + '\n';
}
