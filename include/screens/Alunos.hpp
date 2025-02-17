#pragma once

#include "dao/AlunoDAO.hpp"
#include "screens/CRUDScreen.hpp"

class Alunos : public CRUDScreen
{
public:
    Alunos() = default;
    ~Alunos() = default;

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;

private:    
    AlunoDAO dao;
};
