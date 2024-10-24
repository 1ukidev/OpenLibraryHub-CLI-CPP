#include "Util.hpp"

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <limits>

std::string Util::greet()
{
    auto now = std::chrono::system_clock::now();
    std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
    std::tm localTime = *std::localtime(&nowTime);

    int hours = localTime.tm_hour;

    if (hours >= 6 && hours < 12) {
        return "Bom dia!";
    } else if (hours >= 12 && hours < 18) {
        return "Boa tarde!";
    } else {
        return "Boa noite!";
    }
}

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
