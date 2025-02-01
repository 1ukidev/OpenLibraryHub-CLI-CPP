#pragma once

#include "dao/EmprestimoDAO.hpp"
#include "screens/CRUDScreen.hpp"

class Emprestimos : public CRUDScreen
{
public:
    Emprestimos(const Emprestimos&) = delete;
    Emprestimos& operator=(const Emprestimos&) = delete;
    static Emprestimos& getInstance();

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;

private:
    Emprestimos() = default;
    ~Emprestimos() override = default;

    EmprestimoDAO& dao = EmprestimoDAO::getInstance();
};
