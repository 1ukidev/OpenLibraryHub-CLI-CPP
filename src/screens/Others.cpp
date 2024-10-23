#include "screens/Others.hpp"
#include "Util.hpp"

#include <iostream>

void Others::display()
{
    bool running = true;
    while (running) {
        std::cout << "1 - Sobre\n";
        std::cout << "2 - Sair\n";
        std::cout << "--> ";

        running = handleOption();
    }
}

bool Others::handleOption()
{
    unsigned int option = Util::uiscan();
    Util::clean();

    switch (option) {
        // 1 - Sobre
        case 1:
            about();
            break;
        // 2 - Sair
        case 2:
            return false;
            break;
        default:
            std::cerr << "Opção inválida.\n\n";
            break;
    }

    return true;
}

void Others::about()
{
    std::cout << "OpenLibraryHub é um sistema de gerenciamento de bibliotecas.\n";
    std::cout << "Desenvolvido por: 1ukidev\n";
    std::cout << "GitHub: https://github.com/1ukidev/OpenLibraryHub-CLI-CPP\n";
    std::cout << "Licença: GPL-3.0\n\n";
}
