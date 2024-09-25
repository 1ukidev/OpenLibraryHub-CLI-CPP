#include <iostream>
#include <string>
#include <limits>

#include "util.hpp"

void olh::util::clean()
{
    std::cout << "\033c" << std::flush;
}

std::string olh::util::scan()
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

unsigned int olh::util::uiscan()
{
    unsigned int input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Tente novamente: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }
    }
}
