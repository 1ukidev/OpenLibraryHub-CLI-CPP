#pragma once

#include "entities/Entity.hpp"

#include <boost/mysql/row_view.hpp>
#include <cstdint>
#include <string>
#include <unordered_map>

class TurmaEntity : public Entity
{
public:
    TurmaEntity() = default;
    ~TurmaEntity() override = default;

    TurmaEntity(const std::string& nome) : nome{nome} {};
    TurmaEntity(uint64_t id) : id{id} {};

    std::string getClassName() const override { return "TurmaEntity"; }
    std::string getTable() const override { return "turmas"; }

    const std::unordered_map<std::string, std::string> getColumns() const override {
        return { {"nome", nome} };
    }

    void fromRowSet(const boost::mysql::row_view& row) override {
        if (!row.empty()) {
            id = row[0].get_uint64();
            nome = row[1].get_string();
        }
    }

    uint64_t getId() const override { return id; }
    void setId(uint64_t id) override { this->id = id; }

    std::string getNome() const { return nome; }
    void setNome(const std::string& nome) { this->nome = nome; }

    std::string toString() const override;

private:
    uint64_t id{};
    std::string nome;
};
