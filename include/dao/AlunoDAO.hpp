#pragma once

#include "dao/DAO.hpp"
#include "entities/AlunoEntity.hpp"

class AlunoDAO : public DAO<AlunoEntity>
{
public:
    AlunoDAO() = default;
    ~AlunoDAO() = default;
};
