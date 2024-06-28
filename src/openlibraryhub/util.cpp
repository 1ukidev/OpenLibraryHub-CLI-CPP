#include "util.h"

void Util::clean()
{
    std::cout << "\033c" << std::flush;
}

std::string Util::scan()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

unsigned int Util::iscan() {
    unsigned int input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "--> ";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }
    }
}
