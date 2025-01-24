cmake_minimum_required(VERSION 3.25)

project(
    openlibraryhub
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Werror -g")

add_executable(
    openlibraryhub
    "src/main.cpp"
    "src/Util.cpp"
    "src/Database.cpp"
    "src/DatabaseManager.cpp"
    "src/Config.cpp"
    "src/entities/BookEntity.cpp"
    "src/entities/ClassEntity.cpp"
    "src/entities/StudentEntity.cpp"
    "src/entities/LoanEntity.cpp"
    "src/screens/Home.cpp"
    "src/screens/Others.cpp"
    "src/screens/Books.cpp"
    "src/screens/Classes.cpp"
    "src/screens/Students.cpp"
    "src/screens/Loans.cpp"
    "src/dao/BookDAO.cpp"
    "src/dao/ClassDAO.cpp"
    "src/dao/StudentDAO.cpp"
    "src/dao/LoanDAO.cpp"
    "include/Util.hpp"
    "include/Database.hpp"
    "include/DatabaseManager.hpp"
    "include/Config.hpp"
    "include/DbConfig.hpp"
    "include/entities/Entity.hpp"
    "include/entities/BookEntity.hpp"
    "include/entities/ClassEntity.hpp"
    "include/entities/StudentEntity.hpp"
    "include/entities/LoanEntity.hpp"
    "include/screens/Screen.hpp"
    "include/screens/CRUDScreen.hpp"
    "include/screens/Home.hpp"
    "include/screens/Others.hpp"
    "include/screens/Books.hpp"
    "include/screens/Classes.hpp"
    "include/screens/Students.hpp"
    "include/screens/Loans.hpp"
    "include/dao/DAO.hpp"
    "include/dao/BookDAO.hpp"
    "include/dao/ClassDAO.hpp"
    "include/dao/StudentDAO.hpp"
    "include/dao/LoanDAO.hpp"
)

target_include_directories(openlibraryhub PRIVATE include)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost CONFIG REQUIRED COMPONENTS charconv)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)

target_link_libraries(
    openlibraryhub PRIVATE
    Boost::charconv
    Threads::Threads
    OpenSSL::SSL
    OpenSSL::Crypto
)
