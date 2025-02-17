#pragma once

#include "DbConfig.hpp"
#include "Util.hpp"

#include <map>
#include <string>

class Config final
{
public:
    DECLARE_SINGLETON(Config)

    bool load();
    std::string get(const std::string& key, const std::string& defaultValue = "") const;

    DbConfig dbc;

private:
    Config() = default;
    ~Config() = default;

    std::map<std::string, std::string> config;
    std::string trim(const std::string& str);
    bool initDbConfig();
};
