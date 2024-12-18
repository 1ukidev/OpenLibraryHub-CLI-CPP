#pragma once

#include "DbConfig.hpp"

#include <map>
#include <string>

class Config
{
public:
    bool load();
    std::string get(const std::string& key, const std::string& defaultValue = "") const;
    void putDatabase(DbConfig& dbc);

private:
    std::map<std::string, std::string> config;
    std::string trim(const std::string& str);
};
