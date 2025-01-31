#pragma once

#include "dao/DAO.hpp"
#include "entities/LoanEntity.hpp"

class LoanDAO : public DAO<LoanEntity>
{
public:
    LoanDAO(const LoanDAO&) = delete;
    LoanDAO& operator=(const LoanDAO&) = delete;
    static LoanDAO& getInstance();

private:
    LoanDAO() = default;
    ~LoanDAO() override = default;
};
