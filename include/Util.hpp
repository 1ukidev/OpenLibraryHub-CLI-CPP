#pragma once

#include <chrono>
#include <string>

namespace Util
{
    std::string greet();
    void clean();
    std::string scan();
    unsigned int uiscan();
    unsigned long ulscan();
    std::chrono::system_clock::time_point tpscan();
}
