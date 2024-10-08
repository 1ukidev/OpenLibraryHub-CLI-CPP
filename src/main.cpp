// Copyright (c) 1ukidev <leo.monteiro06@live.com>. Licensed under the GPL-3.0 Licence.
// See the LICENCE file in the repository root for full licence text.

#include <cstdlib>

#include "util.hpp"
#include "screens/home.hpp"

int main()
{
    olh::util::clean();
    olh::home::display();
    return EXIT_SUCCESS;
}
