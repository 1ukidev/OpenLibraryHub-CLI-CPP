#include "Util.h"
#include "Home.h"

#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    Util::clean();
    Home::welcome();

    return EXIT_SUCCESS;
}
