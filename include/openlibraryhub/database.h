#ifndef DATABASE_H
#define DATABASE_H

#include <boost/asio/io_context.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/mysql/tcp_ssl.hpp>

using namespace boost;

namespace olh
{
	class database
	{
	private:
		asio::io_context ioContext;
		asio::ssl::context sslContext{asio::ssl::context::tls_client};

	public:
		mysql::tcp_ssl_connection connection;

		database() : connection(ioContext, sslContext) {}

		void connect(const std::string& host, const unsigned int port, const std::string& user,
					 const std::string& password, const std::string& schema);

		~database() {
			connection.close();
		}
	};
}

#endif // DATABASE_H
