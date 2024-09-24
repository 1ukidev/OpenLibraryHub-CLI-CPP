cmake_minimum_required(VERSION 3.25)

project(openlibraryhub
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_executable(openlibraryhub
    "src/main.cc"
    "src/openlibraryhub/util.cc"
    "src/openlibraryhub/database.cc"
    "src/openlibraryhub/entities/book_entity.cc"
    "src/openlibraryhub/screens/home.cc"
    "src/openlibraryhub/screens/others.cc"
    "src/openlibraryhub/screens/books.cc"
    "src/openlibraryhub/dao/book_dao.cc"
    "include/openlibraryhub/util.h"
    "include/openlibraryhub/database.h"
    "include/openlibraryhub/entities/entity.h"
    "include/openlibraryhub/entities/book_entity.h"
    "include/openlibraryhub/screens/home.h"
    "include/openlibraryhub/screens/others.h"
    "include/openlibraryhub/screens/books.h"
    "include/openlibraryhub/dao/dao.h"
    "include/openlibraryhub/dao/book_dao.h"
)

target_include_directories(openlibraryhub PRIVATE include/openlibraryhub)

find_package(Boost CONFIG REQUIRED COMPONENTS headers charconv)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)

target_link_libraries(openlibraryhub PRIVATE
    Boost::headers
    Boost::charconv
    Threads::Threads
    OpenSSL::SSL
    OpenSSL::Crypto
)
