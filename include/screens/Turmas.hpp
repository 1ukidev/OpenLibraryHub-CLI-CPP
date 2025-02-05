#pragma once

#include "dao/TurmaDAO.hpp"
#include "screens/CRUDScreen.hpp"

class Turmas : public CRUDScreen
{
public:
    Turmas(const Turmas&) = delete;
    Turmas& operator=(const Turmas&) = delete;
    static Turmas& getInstance();

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;

private:
    Turmas() = default;
    ~Turmas() = default;

    TurmaDAO& dao = TurmaDAO::getInstance();
};
