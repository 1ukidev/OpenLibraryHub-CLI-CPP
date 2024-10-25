#pragma once

#include "dao/DAO.hpp"
#include "entities/StudentEntity.hpp"

#include <string>
#include <vector>

class StudentDAO : public DAO<StudentEntity>
{
public:
    StudentDAO() = default;
    ~StudentDAO() = default;

    bool save(const StudentEntity& entity) override;
    bool update(const StudentEntity& entity) override;
    bool _delete(const std::string& where) override;
    std::vector<StudentEntity> search(const std::string& where) override;
};
