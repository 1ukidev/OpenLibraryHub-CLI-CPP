#pragma once

#include <chrono>
#include <string>

class Util
{
public:
    Util() = delete;
    static std::string greet();
    static void clean();

    static std::string scan();
    template <typename T = unsigned int> static T uscan();

    static std::chrono::system_clock::time_point tpscan();
    static std::string timePointToString(const std::chrono::system_clock::time_point& tp,
                                         const std::string& format = "{:%d/%m/%Y}");
};
