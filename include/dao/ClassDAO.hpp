#pragma once

#include "dao/DAO.hpp"
#include "entities/ClassEntity.hpp"

class ClassDAO : public DAO<ClassEntity>
{
public:
    ClassDAO(const ClassDAO&) = delete;
    ClassDAO& operator=(const ClassDAO&) = delete;
    static ClassDAO& getInstance();

private:
    ClassDAO() = default;
    ~ClassDAO() override = default;
};
