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
    ~AlunoEntity() override = default;

    AlunoEntity(const std::string& nome, const TurmaEntity& turmaEntity)
        : nome{nome}, turmaEntity{turmaEntity} {};
    AlunoEntity(uint64_t id) : id{id} {};

    std::string getClassName() const override { return "AlunoEntity"; }
    std::string getTable() const override { return "alunos"; }

    const std::unordered_map<std::string, std::string> getColumns() const override {
        return {
            {"nome", nome},
            {"turma", std::to_string(turmaEntity.getId())}
        };
    }

    void fromRowSet(const boost::mysql::row_view& row) override {
        if (!row.empty()) {
            id = row[0].get_uint64();
            nome = row[1].get_string();
            turmaEntity.setId(row[2].get_uint64());
        }
    }

    uint64_t getId() const override { return id; }
    void setId(uint64_t id) override { this->id = id; }

    std::string getName() const { return nome; }
    void setNome(const std::string& nome) { this->nome = nome; }

    const TurmaEntity& getTurmaEntity() const { return turmaEntity; }
    void setTurmaEntity(const TurmaEntity& turmaEntity) { this->turmaEntity = turmaEntity; }

    std::string toString() const override;

private:
    uint64_t id{};
    std::string nome;
    TurmaEntity turmaEntity;
};
