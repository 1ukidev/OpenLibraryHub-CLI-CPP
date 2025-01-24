#include "Config.hpp"
#include "DbConfig.hpp"

#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>

std::string Config::trim(const std::string& str)
{
    const size_t first = str.find_first_not_of(" \t\n\r");
    const size_t last = str.find_last_not_of(" \t\n\r");
    return first == std::string::npos || last == std::string::npos ? "" : str.substr(first, last - first + 1);
}

bool Config::load()
{
    const std::string homePath = std::getenv("HOME");
    const std::string filePath = homePath + "/olh.properties";

    std::ifstream file(filePath);
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

    file.close();
    return true;
}

std::string Config::get(const std::string& key, const std::string& defaultValue) const
{
    const auto it = config.find(key);
    return it != config.end() ? it->second : defaultValue;
}

bool Config::putDatabase(DbConfig& dbc)
{
    const std::string host = get("db.host");
    const std::string port = get("db.port");
    const std::string user = get("db.user");
    const std::string password = get("db.password");
    const std::string database = get("db.database");

    if (host.empty() || port.empty() || user.empty() || password.empty() || database.empty()) {
        std::cerr << "Configuração de banco de dados inválida.\n";
        return false;
    }

    dbc.host = host;
    dbc.port = port;
    dbc.user = user;
    dbc.password = password;
    dbc.database = database;

    return true;
}
