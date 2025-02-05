#pragma once

#include "dao/DAO.hpp"
#include "entities/EmprestimoEntity.hpp"

class EmprestimoDAO : public DAO<EmprestimoEntity>
{
public:
    EmprestimoDAO(const EmprestimoDAO&) = delete;
    EmprestimoDAO& operator=(const EmprestimoDAO&) = delete;
    static EmprestimoDAO& getInstance();

private:
    EmprestimoDAO() = default;
    ~EmprestimoDAO() = default;
};
