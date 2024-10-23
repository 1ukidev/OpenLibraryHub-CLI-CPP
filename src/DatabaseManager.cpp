#include "DatabaseManager.hpp"
#include "Config.hpp"

#include <iostream>

bool DatabaseManager::initDatabase(Database& db, DbConfig& dbc)
{
    Config config;

    if (!config.load()) {
        std::cerr << "Erro ao carregar arquivo de configuração.\n";
        return false;
    }

    config.putDatabase(dbc);

    try {
        db.connect(dbc.host, dbc.port, dbc.user, dbc.password, dbc.database);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}
