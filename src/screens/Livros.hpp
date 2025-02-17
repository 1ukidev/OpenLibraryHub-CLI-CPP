#pragma once

#include "dao/LivroDAO.hpp"
#include "screens/CRUDScreen.hpp"

class Livros final : public CRUDScreen
{
public:
    Livros() = default;
    ~Livros() = default;

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;

private:
    LivroDAO dao;
};
