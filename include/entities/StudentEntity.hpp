#pragma once

#include "entities/ClassEntity.hpp"
#include "entities/Entity.hpp"

#include <boost/mysql/row_view.hpp>
#include <cstdint>
#include <string>

class StudentEntity : public Entity
{
public:
    StudentEntity() = default;
    ~StudentEntity() override = default;

    StudentEntity(const std::string& name, const ClassEntity& classEntity)
        : name{name}, classEntity{classEntity} {};
    StudentEntity(uint64_t id) : id{id} {};

    std::string getClassName() const override { return "StudentEntity"; }
    std::string getTable() const override { return "alunos"; }

    const std::unordered_map<std::string, std::string> getColumns() const override {
        return {
            {"nome", name},
            {"turma", std::to_string(classEntity.getId())}
        };
    }

    void fromRowSet(const boost::mysql::row_view& row) override {
        if (!row.empty()) {
            id = row[0].get_uint64();
            name = row[1].get_string();
            classEntity.setId(row[2].get_uint64());
        }
    }

    uint64_t getId() const override { return id; }
    void setId(uint64_t id) override { this->id = id; }

    std::string getName() const { return name; }
    void setName(const std::string& name) { this->name = name; }

    const ClassEntity& getClassEntity() const { return classEntity; }
    void setClassEntity(const ClassEntity& classEntity) { this->classEntity = classEntity; }

    std::string toString() const override;

private:
    uint64_t id{};
    std::string name;
    ClassEntity classEntity;
};
