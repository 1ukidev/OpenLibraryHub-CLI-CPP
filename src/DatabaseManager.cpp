#include "DatabaseManager.hpp"
#include "Config.hpp"

#include <exception>
#include <iostream>

bool DatabaseManager::initDatabase(Database& db)
{
    auto& config = Config::getInstance();

    try {
        db.connect(
            config.dbc.host, config.dbc.port,
            config.dbc.user, config.dbc.password,
            config.dbc.database
        );
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}
