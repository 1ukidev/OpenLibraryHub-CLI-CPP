#include "Util.hpp"

#include <chrono>
#include <ctime>
#include <format>
#include <iomanip>
#include <iostream>
#include <sstream>
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

template <typename T>
T Util::uscan()
{
    static_assert(std::is_unsigned<T>::value, "O tipo deve ser um número unsigned.");

    unsigned long long input;
    while (true) {
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Entrada inválida. Tente novamente: ";
            continue;
        }

        if (input > std::numeric_limits<T>::max()) {
            std::cerr << "O número deve estar entre 0 e " << std::numeric_limits<T>::max() << ". Tente novamente: ";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return static_cast<T>(input);
    }
}

template unsigned int Util::uscan();
template unsigned long Util::uscan<unsigned long>();

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

        std::tm tm{};
        std::istringstream ss(input);
        ss >> std::get_time(&tm, "%d/%m/%Y");
        if (ss.fail() || ss.str().empty()) {
            std::cerr << "Data inválida. Certifique-se de usar o formato DD/MM/YYYY.\nTente novamente: ";
            continue;
        }

        std::time_t t = std::mktime(&tm);
        if (t == -1) {
            std::cerr << "Erro ao converter data. Tente novamente: ";
            continue;
        }

        return std::chrono::system_clock::from_time_t(t);
    }
}

std::string Util::timePointToString(const std::chrono::system_clock::time_point& tp, const std::string& format)
{
    std::string s;

    if (format == "{:%d/%m/%Y}") {
        s = std::format("{:%d/%m/%Y}", tp);
    } else if (format == "{:%Y-%m-%d}") {
        s = std::format("{:%Y-%m-%d}", tp);
    }

    return s;
}
