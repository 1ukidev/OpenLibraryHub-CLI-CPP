#pragma once

#include "dao/LivroDAO.hpp"
#include "screens/CRUDScreen.hpp"

class Livros : public CRUDScreen
{
public:
    Livros(const Livros&) = delete;
    Livros& operator=(const Livros&) = delete;
    static Livros& getInstance();

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;

private:
    Livros() = default;
    ~Livros() override = default;

    LivroDAO& dao = LivroDAO::getInstance();
};
