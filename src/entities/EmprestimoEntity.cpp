#include "entities/EmprestimoEntity.hpp"
#include "Util.hpp"

#include <boost/mysql/row_view.hpp>
#include <string>
#include <unordered_map>

std::string EmprestimoEntity::toString() const
{
    return "Id: " + std::to_string(id) + '\n' +
           "Livro: " + std::to_string(livroEntity.id) + '\n' +
           "Estudante: " + std::to_string(alunoEntity.id) + '\n' +
           "Data de empréstimo: " + Util::timePointToString(dataEmpresitmo) + '\n' +
           "Data de devolução: " + Util::timePointToString(dataDevolucao) + '\n';
}

const std::unordered_map<std::string, std::string> EmprestimoEntity::getColumns() const
{
    return {
        {"livro", std::to_string(livroEntity.id)},
        {"aluno", std::to_string(alunoEntity.id)},
        {"data_emprestimo", Util::timePointToString(dataEmpresitmo, "{:%Y-%m-%d}")},
        {"data_devolucao", Util::timePointToString(dataDevolucao, "{:%Y-%m-%d}")}
    };
}

void EmprestimoEntity::fromRowSet(const boost::mysql::row_view& row)
{
    if (!row.empty()) {
        id = row[0].get_uint64();
        livroEntity.id = row[1].get_uint64();
        alunoEntity.id = row[2].get_uint64();
        dataEmpresitmo = row[3].get_date().get_time_point();
        dataDevolucao = row[4].get_date().get_time_point();
    }
}
