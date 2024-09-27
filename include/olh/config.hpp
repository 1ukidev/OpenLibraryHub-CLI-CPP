#ifndef CONFIG_H
#define CONFIG_H

#include <map>
#include <string>

#include "db_config.hpp"

namespace olh {

class config
{
private:
    std::map<std::string, std::string> config;
    std::string trim(const std::string& str);

public:
    bool load();
    std::string get(const std::string& key, const std::string& default_value = "") const;
    void put_database(db_config& dbc);
};

}  // namespace olh

#endif  // CONFIG_H
