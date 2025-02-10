#include "screens/Outros.hpp"
#include "Util.hpp"

#include <iostream>

void Outros::display()
{
    bool running = true;
    while (running) {
        std::cout << "1 - Sobre\n";
        std::cout << "2 - Sair\n";
        std::cout << "--> ";

        running = handleOption();
    }
}

bool Outros::handleOption()
{
    unsigned int option = Util::uscan();
    Util::clean();

    switch (option) {
        // 1 - Sobre
        case 1:
            about();
            break;
        // 2 - Sair
        case 2:
            return false;
        default:
            std::cerr << "Opção inválida.\n\n";
            break;
    }

    return true;
}

void Outros::about()
{
    std::cout << "OpenLibraryHub é um sistema de gerenciamento de bibliotecas.\n";
    std::cout << "Desenvolvido por: 1ukidev\n";
    std::cout << "GitHub: https://github.com/1ukidev/OpenLibraryHub-CLI-CPP\n";
    std::cout << "Licença: GPL-3.0\n\n";
}
