#include <boost/asio/ip/tcp.hpp>
#include <boost/mysql/handshake_params.hpp>

#include "database.hpp"

void olh::database::connect(const std::string& host, const unsigned int port, const std::string& user,
                            const std::string& password, const std::string& schema)
{
    boost::asio::ip::tcp::resolver resolver(connection.get_executor());
    auto endpoints = resolver.resolve(host, std::to_string(port));
    boost::mysql::handshake_params params(user, password, schema);
    connection.connect(*endpoints.begin(), params);
}
