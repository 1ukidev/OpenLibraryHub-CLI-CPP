cmake_minimum_required(VERSION 3.25)

project(openlibraryhub LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Werror -g")

add_executable(
    openlibraryhub
    "src/main.cpp"
    "src/Util.cpp"
    "src/Database.cpp"
    "src/Config.cpp"
    "src/entities/LivroEntity.cpp"
    "src/entities/TurmaEntity.cpp"
    "src/entities/AlunoEntity.cpp"
    "src/entities/EmprestimoEntity.cpp"
    "src/screens/Home.cpp"
    "src/screens/Outros.cpp"
    "src/screens/Livros.cpp"
    "src/screens/Turmas.cpp"
    "src/screens/Alunos.cpp"
    "src/screens/Emprestimos.cpp"
    "src/dao/LivroDAO.cpp"
    "src/dao/TurmaDAO.cpp"
    "src/dao/AlunoDAO.cpp"
    "src/dao/EmprestimoDAO.cpp"
    "include/Util.hpp"
    "include/Database.hpp"
    "include/Config.hpp"
    "include/DbConfig.hpp"
    "include/entities/Entity.hpp"
    "include/entities/LivroEntity.hpp"
    "include/entities/TurmaEntity.hpp"
    "include/entities/AlunoEntity.hpp"
    "include/entities/EmprestimoEntity.hpp"
    "include/screens/Screen.hpp"
    "include/screens/CRUDScreen.hpp"
    "include/screens/Home.hpp"
    "include/screens/Outros.hpp"
    "include/screens/Livros.hpp"
    "include/screens/Turmas.hpp"
    "include/screens/Alunos.hpp"
    "include/screens/Emprestimos.hpp"
    "include/dao/DAO.hpp"
    "include/dao/LivroDAO.hpp"
    "include/dao/TurmaDAO.hpp"
    "include/dao/AlunoDAO.hpp"
    "include/dao/EmprestimoDAO.hpp"
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
