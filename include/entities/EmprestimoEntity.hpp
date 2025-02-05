#pragma once

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
    ~EmprestimoEntity() = default;

    EmprestimoEntity(const LivroEntity& livroEntity, const AlunoEntity& alunoEntity,
               const std::chrono::system_clock::time_point& dataEmpresitmo,
               const std::chrono::system_clock::time_point& dataDevolucao)
        : livroEntity_(livroEntity), alunoEntity_(alunoEntity),
          dataEmpresitmo_(dataEmpresitmo), dataDevolucao_(dataDevolucao) {};

    std::string getClassName() const override { return "EmprestimoEntity"; }
    std::string getTable() const override { return "emprestimos"; }

    const std::unordered_map<std::string, std::string> getColumns() const override;

    void fromRowSet(const boost::mysql::row_view& row) override;

    uint64_t getId() const override { return id_; }
    void setId(uint64_t id) override { this->id_ = id; }

    const LivroEntity& getLivroEntity() const { return livroEntity_; }
    void setLivroEntity(const LivroEntity& livroEntity) { this->livroEntity_ = livroEntity; }

    const AlunoEntity& getAlunoEntity() const { return alunoEntity_; }
    void setAlunoEntity(const AlunoEntity& alunoEntity) { this->alunoEntity_ = alunoEntity; }

    const std::chrono::system_clock::time_point& getDataEmprestimo() const { return dataEmpresitmo_; }
    void setDataEmprestimo(const std::chrono::system_clock::time_point& dataEmpresitmo) {
        this->dataEmpresitmo_ = dataEmpresitmo;
    }

    const std::chrono::system_clock::time_point& getDataDevolucao() const { return dataDevolucao_; }
    void setDataDevolucao(const std::chrono::system_clock::time_point& dataDevolucao) {
        this->dataDevolucao_ = dataDevolucao;
    }

    std::string toString() const override;

private:
    uint64_t id_{};
    LivroEntity livroEntity_;
    AlunoEntity alunoEntity_;
    std::chrono::system_clock::time_point dataEmpresitmo_;
    std::chrono::system_clock::time_point dataDevolucao_;
};
