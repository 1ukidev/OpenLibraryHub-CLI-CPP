#pragma once

#include "dao/DAO.hpp"
#include "entities/LivroEntity.hpp"

class LivroDAO : public DAO<LivroEntity>
{
public:
    LivroDAO() = default;
    ~LivroDAO() = default;
};
