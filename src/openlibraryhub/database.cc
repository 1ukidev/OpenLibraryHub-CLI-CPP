#include <boost/asio/ip/tcp.hpp>
#include <boost/mysql/handshake_params.hpp>

#include "database.h"

using namespace boost;

void olh::database::connect(const std::string& host, const unsigned int port, const std::string& user,
							const std::string& password, const std::string& schema)
{
	asio::ip::tcp::resolver resolver(connection.get_executor());
	auto endpoints = resolver.resolve(host, std::to_string(port));
	mysql::handshake_params params(user, password, schema);
	connection.connect(*endpoints.begin(), params);
}
