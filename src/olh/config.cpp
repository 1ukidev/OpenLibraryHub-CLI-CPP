#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>

#include "config.hpp"
#include "db_config.hpp"

std::string olh::config::trim(const std::string& str)
{
    const size_t first = str.find_first_not_of(" \t\n\r");
    const size_t last = str.find_last_not_of(" \t\n\r");
    return first == std::string::npos || last == std::string::npos ? "" : str.substr(first, last - first + 1);
}

bool olh::config::load()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    const std::string home_path = std::getenv("HOMEPATH");
#else
    const std::string home_path = std::getenv("HOME");
#endif

    const std::string file_path = home_path + "/olh.properties";

    if (!std::filesystem::exists(file_path)) {
        std::ofstream new_file(file_path);
        if (!new_file) {
            std::cerr << "Falha ao criar arquivo: " << file_path << '\n';
            return false;
        }
        new_file.close();
    }

    std::ifstream file(file_path);
    if (!file.is_open()) {
        return false;
    }

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

std::string olh::config::get(const std::string& key, const std::string& default_value) const
{
    const auto it = config.find(key);
    return it != config.end() ? it->second : default_value;
}

void olh::config::put_database(db_config& dbc)
{
    const std::string host = get("db.host");
    const std::string port = get("db.port");
    const std::string user = get("db.user");
    const std::string password = get("db.password");
    const std::string database = get("db.database");

    if (host.empty() || port.empty() || user.empty() || password.empty() || database.empty()) {
        std::cerr << "Configurações de banco de dados inválida\n";
        return;
    }

    dbc.host = host;
    dbc.port = static_cast<unsigned int>(std::stoul(port));
    dbc.user = user;
    dbc.password = password;
    dbc.database = database;
}
