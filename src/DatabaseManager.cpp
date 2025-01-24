#include "DatabaseManager.hpp"
#include "Config.hpp"
#include "DbConfig.hpp"

#include <exception>
#include <iostream>

bool DatabaseManager::initDatabase(Database& db)
{
    Config config;
    DbConfig dbc;

    if (!config.load()) {
        std::cerr << "Erro ao carregar arquivo de configuração.\n";
        return false;
    }

    if (!config.putDatabase(dbc))
        return false;

    try {
        db.connect(dbc.host, dbc.port, dbc.user, dbc.password, dbc.database);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}
