#include "screens/Home.hpp"
#include "screens/Books.hpp"
#include "screens/Classes.hpp"
#include "screens/Loans.hpp"
#include "screens/Others.hpp"
#include "Util.hpp"
#include "screens/Students.hpp"

#include <iostream>

void Home::display()
{
    bool running = true;
    while (running) {
        std::cout << "Bem-vindo ao OpenLibraryHub!\n\n";
        std::cout << Util::greet() << "\n\n";
        std::cout << "O que deseja fazer?\n\n";
        std::cout << "1 - Livros\n";
        std::cout << "2 - Turmas\n";
        std::cout << "3 - Alunos\n";
        std::cout << "4 - Empréstimos\n";
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
        // 2 - Turmas
        case 2:
            Classes::display();
            break;
        // 3 - Alunos
        case 3:
            Students::display();
            break;
        // 4- Empréstimos
        case 4:
            Loans::display();
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
