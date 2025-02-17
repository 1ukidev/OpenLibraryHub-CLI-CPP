#pragma once

#include <boost/asio/io_context.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/mysql/tcp_ssl.hpp>
#include <string>

class Database final
{
private:
    boost::asio::io_context ioContext_;
    boost::asio::ssl::context sslContext_{boost::asio::ssl::context::tls_client};

    void connect(const std::string& host, const std::string& port, const std::string& user,
                 const std::string& password, const std::string& schema);

public:
    boost::mysql::tcp_ssl_connection connection;

    Database() : connection(ioContext_, sslContext_) {}

    bool init();

    ~Database() {
        connection.close();
    }
};
