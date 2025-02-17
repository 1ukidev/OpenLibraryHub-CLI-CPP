#pragma once

#include "dao/EmprestimoDAO.hpp"
#include "screens/CRUDScreen.hpp"

class Emprestimos : public CRUDScreen
{
public:
    Emprestimos() = default;
    ~Emprestimos() = default;

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;

private:
    EmprestimoDAO dao;
};
