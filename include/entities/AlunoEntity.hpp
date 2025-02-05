#pragma once

#include "entities/TurmaEntity.hpp"
#include "entities/Entity.hpp"

#include <boost/mysql/row_view.hpp>
#include <cstdint>
#include <string>

class AlunoEntity : public Entity
{
public:
    AlunoEntity() = default;
    ~AlunoEntity() = default;

    AlunoEntity(const std::string& nome, const TurmaEntity& turmaEntity)
        : nome_{nome}, turmaEntity_{turmaEntity} {};
    AlunoEntity(uint64_t id) : id_{id} {};

    std::string getClassName() const override { return "AlunoEntity"; }
    std::string getTable() const override { return "alunos"; }

    const std::unordered_map<std::string, std::string> getColumns() const override;

    void fromRowSet(const boost::mysql::row_view& row) override;

    uint64_t getId() const override { return id_; }
    void setId(uint64_t id) override { this->id_ = id; }

    std::string getName() const { return nome_; }
    void setNome(const std::string& nome) { this->nome_ = nome; }

    const TurmaEntity& getTurmaEntity() const { return turmaEntity_; }
    void setTurmaEntity(const TurmaEntity& turmaEntity_) { this->turmaEntity_ = turmaEntity_; }

    std::string toString() const override;

private:
    uint64_t id_{};
    std::string nome_;
    TurmaEntity turmaEntity_;
};
