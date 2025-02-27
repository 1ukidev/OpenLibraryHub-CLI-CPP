#pragma once

#include "dao/DAO.hpp"
#include "entities/EmprestimoEntity.hpp"

class EmprestimoDAO final : public DAO<EmprestimoEntity>
{
public:
    EmprestimoDAO() = default;
    ~EmprestimoDAO() = default;
};
