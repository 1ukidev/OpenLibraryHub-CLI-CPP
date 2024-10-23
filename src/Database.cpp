#include "Database.hpp"

#include <boost/asio/ip/tcp.hpp>
#include <boost/mysql/handshake_params.hpp>
#include <string_view>

void Database::connect(std::string_view host, std::string_view port, std::string_view user,
                       std::string_view password, std::string_view schema)
{
    boost::asio::ip::tcp::resolver resolver(connection.get_executor());
    auto endpoints = resolver.resolve(host, port);
    boost::mysql::handshake_params params(user, password, schema);
    connection.connect(*endpoints.begin(), params);
}
