#pragma once

#include "dao/DAO.hpp"
#include "entities/ClassEntity.hpp"

#include <string>
#include <vector>

class ClassDAO : public DAO<ClassEntity>
{
public:
    ClassDAO() = default;
    ~ClassDAO() = default;

    bool save(const ClassEntity& entity) override;
    bool update(const ClassEntity& entity) override;
    bool _delete(const std::string& where) override;
    std::vector<ClassEntity> search(const std::string& where) override;
};
