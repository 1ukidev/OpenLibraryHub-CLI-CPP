#pragma once

#include "dao/DAO.hpp"
#include "entities/StudentEntity.hpp"

class StudentDAO : public DAO<StudentEntity>
{
public:
    StudentDAO(const StudentDAO&) = delete;
    StudentDAO& operator=(const StudentDAO&) = delete;
    static StudentDAO& getInstance();

private:
    StudentDAO() = default;
    ~StudentDAO() override = default;
};
