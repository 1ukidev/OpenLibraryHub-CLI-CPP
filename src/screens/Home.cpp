#include "screens/Home.hpp"
#include "screens/Livros.hpp"
#include "screens/Turmas.hpp"
#include "screens/Emprestimos.hpp"
#include "screens/Outros.hpp"
#include "Util.hpp"
#include "screens/Alunos.hpp"

#include <iostream>

Home& Home::getInstance()
{
    static Home instance;
    return instance;
}

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
    unsigned int option = Util::uscan();
    Util::clean();

    switch (option) {
        // 1 - Livros
        case 1: {
            auto& Livros = Livros::getInstance();
            Livros.display();
            break;
        }
        // 2 - Turmas
        case 2: {
            auto& Turmas = Turmas::getInstance();
            Turmas.display();
            break;
        }
        // 3 - Alunos
        case 3: {
            auto& Alunos = Alunos::getInstance();
            Alunos.display();
            break;
        }
        // 4- Empréstimos
        case 4: {
            auto& Emprestimos = Emprestimos::getInstance();
            Emprestimos.display();
            break;
        }
        // 5 - Outros
        case 5: {
            auto& outros = Outros::getInstance();
            outros.display();
            break;
        }
        // 6 - Sair
        case 6:
            std::cout << "Até mais!\n";
            return false;
        default:
            std::cerr << "Opção inválida.\n\n";
            break;
    }

    return true;
}
