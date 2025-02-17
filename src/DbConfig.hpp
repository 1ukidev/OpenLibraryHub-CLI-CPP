#pragma once

#include <string>

struct DbConfig final
{
    std::string host;
    std::string port;
    std::string user;
    std::string password;
    std::string database;
};
