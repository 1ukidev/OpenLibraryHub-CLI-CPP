#pragma once

#include "dao/DAO.hpp"
#include "entities/LivroEntity.hpp"

class LivroDAO : public DAO<LivroEntity>
{
public:
    LivroDAO(const LivroDAO&) = delete;
    LivroDAO& operator=(const LivroDAO&) = delete;
    static LivroDAO& getInstance();

private:
    LivroDAO() = default;
    ~LivroDAO() override = default;
};
