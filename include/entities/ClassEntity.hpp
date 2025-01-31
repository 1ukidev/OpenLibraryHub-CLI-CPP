#pragma once

#include "entities/Entity.hpp"

#include <boost/mysql/row_view.hpp>
#include <cstdint>
#include <string>
#include <unordered_map>

class ClassEntity : public Entity
{
public:
    ClassEntity() = default;
    ~ClassEntity() override = default;

    ClassEntity(const std::string& name) : name{name} {};
    ClassEntity(uint64_t id) : id{id} {};

    std::string getClassName() const override { return "ClassEntity"; }
    std::string getTable() const override { return "turmas"; }

    const std::unordered_map<std::string, std::string> getColumns() const override {
        return { {"nome", name} };
    }

    void fromRowSet(const boost::mysql::row_view& row) override {
        if (!row.empty()) {
            id = row[0].get_uint64();
            name = row[1].get_string();
        }
    }

    uint64_t getId() const override { return id; }
    void setId(uint64_t id) override { this->id = id; }

    std::string getName() const { return name; }
    void setName(const std::string& name) { this->name = name; }

    std::string toString() const override;

private:
    uint64_t id{};
    std::string name;
};
