#pragma once

#include "dao/DAO.hpp"
#include "entities/TurmaEntity.hpp"

class TurmaDAO final : public DAO<TurmaEntity>
{
public:
    TurmaDAO() = default;
    ~TurmaDAO() = default;
};
