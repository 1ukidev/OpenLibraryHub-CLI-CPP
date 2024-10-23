#include "Util.hpp"

#include <iostream>
#include <string>
#include <limits>

void Util::clean()
{
    std::cout << "\033c" << std::flush;
}

std::string Util::scan()
{
    std::string input;
    while (true) {
        if (!std::getline(std::cin, input)) {
            std::cerr << "Erro ao ler a entrada.\n";
        }

        if (input.empty()) {
            std::cerr << "Tente novamente: ";
        } else {
            return input;
        }
    }
}

unsigned int Util::uiscan()
{
    int input;
    while (true) {
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Entrada inválida. Tente novamente: ";
        } else if (input < 0) {
            std::cerr << "O número não pode ser negativo. Tente novamente: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return static_cast<unsigned int>(input);
        }
    }
}