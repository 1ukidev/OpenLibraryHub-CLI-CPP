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
            continue;
        }

        if (input.empty()) {
            std::cerr << "Tente novamente: ";
            continue;
        }

        return input;
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
            continue;
        }

        if (input < 0) {
            std::cerr << "O número não pode ser negativo. Tente novamente: ";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return static_cast<unsigned int>(input);
    }
}

unsigned long Util::ulscan()
{
    long input;
    while (true) {
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Entrada inválida. Tente novamente: ";
            continue;
        }

        if (input < 0) {
            std::cerr << "O número não pode ser negativo. Tente novamente: ";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return static_cast<unsigned long>(input);
    }
}

std::chrono::system_clock::time_point Util::tpscan()
{
    std::string input;
    while (true) {
        if (!std::getline(std::cin, input)) {
            std::cerr << "Erro ao ler a entrada.\n";
            continue;
        }

        if (input.empty()) {
            std::cerr << "Tente novamente: ";
            continue;
        }

        std::tm tm = {};
        if (strptime(input.c_str(), "%d/%m/%Y", &tm) == nullptr) {
            std::cerr << "Data inválida. Tente novamente: ";
            continue;
        }

        std::time_t t = std::mktime(&tm);
        if (t == -1) {
            std::cerr << "Data inválida. Tente novamente: ";
            continue;
        }

        return std::chrono::system_clock::from_time_t(t);
    }
}
