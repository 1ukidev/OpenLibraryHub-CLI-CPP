#include "screens/Home.hpp"
#include "screens/Books.hpp"
#include "screens/Others.hpp"
#include "Util.hpp"

#include <iostream>

void Home::display()
{
    bool running = true;
    while (running) {
        std::cout << "Bem-vindo ao OpenLibraryHub!\n\n";
        std::cout << "O que deseja fazer?\n\n";
        std::cout << "1 - Livros\n";
        std::cout << "2 - Turmas\n";
        std::cout << "3 - Alunos\n";
        std::cout << "4 - Empréstimo\n";
        std::cout << "5 - Outros\n";
        std::cout << "6 - Sair\n";
        std::cout << "--> ";

        running = handleOption();
    }
}

bool Home::handleOption()
{
    unsigned int option = Util::uiscan();
    Util::clean();

    switch (option) {
        // 1 - Livros
        case 1:
            Books::display();
            break;
        // 5 - Outros
        case 5:
            Others::display();
            break;
        // 6 - Sair
        case 6:
            std::cout << "Até mais!\n";
            return false;
            break;
        default:
            std::cerr << "Opção inválida.\n\n";
            break;
    }

    return true;
}
