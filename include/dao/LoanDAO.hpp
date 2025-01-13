#pragma once

#include "dao/DAO.hpp"
#include "entities/LoanEntity.hpp"

#include <string>
#include <vector>

class LoanDAO : public DAO<LoanEntity>
{
public:
    LoanDAO() = default;
    ~LoanDAO() override = default;

    bool save(const LoanEntity& entity) override;
    bool update(const LoanEntity& entity) override;
    bool remove(const std::string& where) override;
    std::vector<LoanEntity> search(const std::string& where) override;
};
