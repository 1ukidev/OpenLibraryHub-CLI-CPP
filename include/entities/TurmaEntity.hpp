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
    ~TurmaEntity() = default;

    TurmaEntity(const std::string& nome) : nome_{nome} {};
    TurmaEntity(uint64_t id) : id_{id} {};

    std::string getClassName() const override { return "TurmaEntity"; }
    std::string getTable() const override { return "turmas"; }

    const std::unordered_map<std::string, std::string> getColumns() const override;

    void fromRowSet(const boost::mysql::row_view& row) override;

    uint64_t getId() const override { return id_; }
    void setId(uint64_t id) override { this->id_ = id; }

    std::string getNome() const { return nome_; }
    void setNome(const std::string& nome) { this->nome_ = nome; }

    std::string toString() const override;

private:
    uint64_t id_{};
    std::string nome_;
};
