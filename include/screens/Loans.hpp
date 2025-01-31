#pragma once

#include "dao/LoanDAO.hpp"
#include "screens/CRUDScreen.hpp"

class Loans : public CRUDScreen
{
public:
    Loans(const Loans&) = delete;
    Loans& operator=(const Loans&) = delete;
    static Loans& getInstance();

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;

private:
    Loans() = default;
    ~Loans() override = default;

    LoanDAO& dao = LoanDAO::getInstance();
};
