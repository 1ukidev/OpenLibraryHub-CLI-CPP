cmake_minimum_required(VERSION 3.25)

project(openlibraryhub
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_executable(openlibraryhub
    "src/main.cpp"
    "src/olh/util.cpp"
    "src/olh/database.cpp"
    "src/olh/entities/book_entity.cpp"
    "src/olh/screens/home.cpp"
    "src/olh/screens/others.cpp"
    "src/olh/screens/books.cpp"
    "src/olh/dao/book_dao.cpp"
    "include/olh/util.hpp"
    "include/olh/database.hpp"
    "include/olh/entities/entity.hpp"
    "include/olh/entities/book_entity.hpp"
    "include/olh/screens/home.hpp"
    "include/olh/screens/others.hpp"
    "include/olh/screens/books.hpp"
    "include/olh/dao/dao.hpp"
    "include/olh/dao/book_dao.hpp"
)

target_include_directories(openlibraryhub PRIVATE include/olh)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

find_package(Boost CONFIG REQUIRED COMPONENTS charconv)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)

target_link_libraries(openlibraryhub PRIVATE
    Boost::charconv
    Threads::Threads
    OpenSSL::SSL
    OpenSSL::Crypto
)
