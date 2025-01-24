#pragma once

#include "Database.hpp"
#include "DbConfig.hpp"

class DatabaseManager
{
public:
    DatabaseManager() = delete;
    static bool initDatabase(Database& db);
};
