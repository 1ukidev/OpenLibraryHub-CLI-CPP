#pragma once

#include "Database.hpp"

class DatabaseManager
{
public:
    DatabaseManager() = delete;

    static bool initDatabase(Database& db);
};
