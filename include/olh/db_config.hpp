#ifndef DB_CONFIG
#define DB_CONFIG

#include <string>

namespace olh {

struct db_config
{
    std::string host;
    unsigned int port;
    std::string user;
    std::string password;
    std::string database;
};

}  // namespace olh

#endif  // DB_CONFIG
