#ifndef DATABASE_H
#define DATABASE_H

#include <boost/asio/io_context.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/mysql/tcp_ssl.hpp>

namespace olh {

class database
{
private:
    boost::asio::io_context ioContext_;
    boost::asio::ssl::context sslContext_{boost::asio::ssl::context::tls_client};

public:
    boost::mysql::tcp_ssl_connection connection;

    database() : connection(ioContext_, sslContext_) {}

    void connect(const std::string& host, const unsigned int port, const std::string& user,
                 const std::string& password, const std::string& schema);

    ~database() {
        connection.close();
    }
};

}  // namespace olh

#endif  // DATABASE_H
