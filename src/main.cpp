// Copyright (c) 1ukidev <leo.monteiro06@live.com>. Licensed under the GPL-3.0 Licence.
// See the LICENCE file in the repository root for full licence text.

#include "Util.hpp"
#include "screens/Home.hpp"

#include <cstdlib>

int main()
{
    Util::clean();
    Home::display();
    return EXIT_SUCCESS;
}
