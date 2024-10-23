cmake_minimum_required(VERSION 3.25)

project(openlibraryhub
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_executable(openlibraryhub
    "src/main.cpp"
    "src/Util.cpp"
    "src/Database.cpp"
    "src/DatabaseManager.cpp"
    "src/Config.cpp"
    "src/entities/BookEntity.cpp"
    "src/screens/Home.cpp"
    "src/screens/Others.cpp"
    "src/screens/Books.cpp"
    "src/dao/BookDAO.cpp"
    "include/Util.hpp"
    "include/Database.hpp"
    "include/DatabaseManager.hpp"
    "include/Config.hpp"
    "include/DbConfig.hpp"
    "include/entities/Entity.hpp"
    "include/entities/BookEntity.hpp"
    "include/screens/Home.hpp"
    "include/screens/Others.hpp"
    "include/screens/Books.hpp"
    "include/dao/DAO.hpp"
    "include/dao/BookDAO.hpp"
)

target_include_directories(openlibraryhub PRIVATE include)

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
