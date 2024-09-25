#include <iostream>

#include "screens/home.hpp"
#include "screens/books.hpp"
#include "screens/others.hpp"
#include "util.hpp"

void olh::home::display()
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

        running = handle_option();
    }
}

bool olh::home::handle_option()
{
    unsigned int option = olh::util::uiscan();
    olh::util::clean();

    switch (option) {
        // 1 - Livros
        case 1:
            olh::books::display();
            break;
        // 5 - Outros
        case 5:
            olh::others::display();
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
