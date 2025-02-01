#include "Database.hpp"
#include "Config.hpp"

#include <boost/asio/ip/tcp.hpp>
#include <boost/mysql/handshake_params.hpp>
#include <exception>
#include <iostream>
#include <string>

void Database::connect(const std::string& host, const std::string& port, const std::string& user,
                       const std::string& password, const std::string& schema)
{
    boost::asio::ip::tcp::resolver resolver(connection.get_executor());
    auto endpoints = resolver.resolve(host, port);
    boost::mysql::handshake_params params(user, password, schema);
    connection.connect(*endpoints.begin(), params);
}

bool Database::init()
{
    auto& config = Config::getInstance();

    try {
        connect(
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
