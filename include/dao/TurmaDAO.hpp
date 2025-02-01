#pragma once

#include "dao/DAO.hpp"
#include "entities/TurmaEntity.hpp"

class TurmaDAO : public DAO<TurmaEntity>
{
public:
    TurmaDAO(const TurmaDAO&) = delete;
    TurmaDAO& operator=(const TurmaDAO&) = delete;
    static TurmaDAO& getInstance();

private:
    TurmaDAO() = default;
    ~TurmaDAO() override = default;
};
