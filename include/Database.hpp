#pragma once

#include <boost/asio/io_context.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/mysql/tcp_ssl.hpp>
#include <string_view>

class Database
{
private:
    boost::asio::io_context ioContext_;
    boost::asio::ssl::context sslContext_{boost::asio::ssl::context::tls_client};

public:
    boost::mysql::tcp_ssl_connection connection;

    Database() : connection(ioContext_, sslContext_) {}

    void connect(std::string_view host, std::string_view port, std::string_view user,
                 std::string_view password, std::string_view schema);

    ~Database() {
        connection.close();
    }
};
