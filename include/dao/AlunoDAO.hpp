#pragma once

#include "dao/DAO.hpp"
#include "entities/AlunoEntity.hpp"

class AlunoDAO : public DAO<AlunoEntity>
{
public:
    AlunoDAO(const AlunoDAO&) = delete;
    AlunoDAO& operator=(const AlunoDAO&) = delete;
    static AlunoDAO& getInstance();

private:
    AlunoDAO() = default;
    ~AlunoDAO() = default;
};
