#pragma once

#include "dao/AlunoDAO.hpp"
#include "screens/CRUDScreen.hpp"

class Alunos : public CRUDScreen
{
public:
    Alunos(const Alunos&) = delete;
    Alunos& operator=(const Alunos&) = delete;
    static Alunos& getInstance();

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;

private:
    Alunos() = default;
    ~Alunos() override = default;

    AlunoDAO& dao = AlunoDAO::getInstance();
};
