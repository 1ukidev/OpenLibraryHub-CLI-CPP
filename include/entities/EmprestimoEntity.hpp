#pragma once

#include "Util.hpp"
#include "entities/LivroEntity.hpp"
#include "entities/Entity.hpp"
#include "entities/AlunoEntity.hpp"

#include <boost/mysql/row_view.hpp>
#include <chrono>
#include <cstdint>
#include <string>
#include <unordered_map>

class EmprestimoEntity : public Entity
{
public:
    EmprestimoEntity() = default;
    ~EmprestimoEntity() override = default;

    EmprestimoEntity(const LivroEntity& livroEntity, const AlunoEntity& alunoEntity,
               const std::chrono::system_clock::time_point& dataEmpresitmo,
               const std::chrono::system_clock::time_point& dataDevolucao)
        : livroEntity(livroEntity), alunoEntity(alunoEntity),
          dataEmpresitmo(dataEmpresitmo), dataDevolucao(dataDevolucao) {};

    std::string getClassName() const override { return "EmprestimoEntity"; }
    std::string getTable() const override { return "emprestimos"; }

    const std::unordered_map<std::string, std::string> getColumns() const override {
        return {
            {"livro", std::to_string(livroEntity.getId())},
            {"aluno", std::to_string(alunoEntity.getId())},
            {"data_emprestimo", Util::timePointToString(dataEmpresitmo, "{:%Y-%m-%d}")},
            {"data_devolucao", Util::timePointToString(dataDevolucao, "{:%Y-%m-%d}")}
        };
    }

    void fromRowSet(const boost::mysql::row_view& row) override {
        if (!row.empty()) {
            id = row[0].get_uint64();
            livroEntity.setId(row[1].get_uint64());
            alunoEntity.setId(row[2].get_uint64());
            dataEmpresitmo = row[3].get_date().get_time_point();
            dataDevolucao = row[4].get_date().get_time_point();
        }
    }

    uint64_t getId() const override { return id; }
    void setId(uint64_t id) override { this->id = id; }

    const LivroEntity& getLivroEntity() const { return livroEntity; }
    void setLivroEntity(const LivroEntity& livroEntity) { this->livroEntity = livroEntity; }

    const AlunoEntity& getAlunoEntity() const { return alunoEntity; }
    void setAlunoEntity(const AlunoEntity& alunoEntity) { this->alunoEntity = alunoEntity; }

    const std::chrono::system_clock::time_point& getDataEmprestimo() const { return dataEmpresitmo; }
    void setDataEmprestimo(const std::chrono::system_clock::time_point& dataEmpresitmo) {
        this->dataEmpresitmo = dataEmpresitmo;
    }

    const std::chrono::system_clock::time_point& getDataDevolucao() const { return dataDevolucao; }
    void setDataDevolucao(const std::chrono::system_clock::time_point& dataDevolucao) {
        this->dataDevolucao = dataDevolucao;
    }

    std::string toString() const override;

private:
    uint64_t id{};
    LivroEntity livroEntity;
    AlunoEntity alunoEntity;
    std::chrono::system_clock::time_point dataEmpresitmo;
    std::chrono::system_clock::time_point dataDevolucao;
};
