#include "entities/EmprestimoEntity.hpp"
#include "Util.hpp"

#include <string>

std::string EmprestimoEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Livro: " + std::to_string(livroEntity.getId()) + '\n' +
           "Estudante: " + std::to_string(alunoEntity.getId()) + '\n' +
           "Data de empréstimo: " + Util::timePointToString(dataEmpresitmo) + '\n' +
           "Data de devolução: " + Util::timePointToString(dataDevolucao) + '\n';
}
