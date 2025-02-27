#pragma once

#include "dao/TurmaDAO.hpp"
#include "screens/CRUDScreen.hpp"

class Turmas final : public CRUDScreen
{
public:
    Turmas() = default;
    ~Turmas() = default;

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;

private:
    TurmaDAO dao;
};
