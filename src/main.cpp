// Copyright (c) 1ukidev <leo.monteiro06@live.com>. Licensed under the GPL-3.0 Licence.
// See the LICENCE file in the repository root for full licence text.

#include "Config.hpp"
#include "Util.hpp"
#include "screens/Home.hpp"

#include <cstdlib>
#include <iostream>

int main()
{
    Util::clean();

    auto& config = Config::getInstance();
    if (!config.load()) {
        std::cerr << "Erro ao carregar configurações.\n";
        return EXIT_FAILURE;
    }

    Home home;
    home.display();

    return EXIT_SUCCESS;
}
