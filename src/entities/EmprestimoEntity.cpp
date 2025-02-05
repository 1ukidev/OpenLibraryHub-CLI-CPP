#include "entities/EmprestimoEntity.hpp"
#include "Util.hpp"

#include <boost/mysql/row_view.hpp>
#include <string>
#include <unordered_map>

std::string EmprestimoEntity::toString() const
{
    return "Id: " + std::to_string(id_) + '\n' +
           "Livro: " + std::to_string(livroEntity_.getId()) + '\n' +
           "Estudante: " + std::to_string(alunoEntity_.getId()) + '\n' +
           "Data de empréstimo: " + Util::timePointToString(dataEmpresitmo_) + '\n' +
           "Data de devolução: " + Util::timePointToString(dataDevolucao_) + '\n';
}

const std::unordered_map<std::string, std::string> EmprestimoEntity::getColumns() const
{
    return {
        {"livro", std::to_string(livroEntity_.getId())},
        {"aluno", std::to_string(alunoEntity_.getId())},
        {"data_emprestimo", Util::timePointToString(dataEmpresitmo_, "{:%Y-%m-%d}")},
        {"data_devolucao", Util::timePointToString(dataDevolucao_, "{:%Y-%m-%d}")}
    };
}

void EmprestimoEntity::fromRowSet(const boost::mysql::row_view& row)
{
    if (!row.empty()) {
        id_ = row[0].get_uint64();
        livroEntity_.setId(row[1].get_uint64());
        alunoEntity_.setId(row[2].get_uint64());
        dataEmpresitmo_ = row[3].get_date().get_time_point();
        dataDevolucao_ = row[4].get_date().get_time_point();
    }
}
