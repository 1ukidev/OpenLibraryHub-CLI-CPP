#include "Config.hpp"
#include "DbConfig.hpp"

#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>

Config& Config::getInstance()
{
    static Config instance;
    return instance;
}

bool Config::load()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    std::string path  = std::getenv("HOMEPATH");
#else
    std::string path = std::getenv("HOME");
#endif
    path += "/olh.properties";

    if (!std::filesystem::exists(path)) {
        std::cerr << "Arquivo de configuração não encontrado.\n";
        return false;
    }

    std::ifstream file(path);
    if (!file.is_open())
        return false;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;

        std::stringstream ss(line);
        std::string key, value;

        if (std::getline(ss, key, '=') && std::getline(ss, value)) {
            key = trim(key);
            value = trim(value);
            config[key] = value;
        }
    }

    if (!initDbConfig())
        return false;

    file.close();
    return true;
}

std::string Config::get(const std::string& key, const std::string& defaultValue) const
{
    const auto it = config.find(key);
    return it != config.end() ? it->second : defaultValue;
}

bool Config::initDbConfig()
{
    dbc.port = get("db.port");
    dbc.host = get("db.host");
    dbc.user = get("db.user");
    dbc.password = get("db.password");
    dbc.database = get("db.database");

    if (dbc.host.empty() || dbc.port.empty() || dbc.user.empty()
            || dbc.password.empty() || dbc.database.empty()) {
        std::cerr << "Arquivo de configuracao incompleto\n";
        return false;
    }

    return true;
}

std::string Config::trim(const std::string& str)
{
    const size_t first = str.find_first_not_of(" \t\n\r");
    const size_t last = str.find_last_not_of(" \t\n\r");
    return first == std::string::npos || last == std::string::npos ? "" : str.substr(first, last - first + 1);
}
