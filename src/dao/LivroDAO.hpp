#pragma once

#include "dao/DAO.hpp"
#include "entities/LivroEntity.hpp"

class LivroDAO final : public DAO<LivroEntity>
{
public:
    LivroDAO() = default;
    ~LivroDAO() = default;
};
