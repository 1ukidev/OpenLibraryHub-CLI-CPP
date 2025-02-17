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
    "src/Util.hpp"
    "src/Database.hpp"
    "src/Config.hpp"
    "src/DbConfig.hpp"
    "src/entities/Entity.hpp"
    "src/entities/LivroEntity.hpp"
    "src/entities/TurmaEntity.hpp"
    "src/entities/AlunoEntity.hpp"
    "src/entities/EmprestimoEntity.hpp"
    "src/screens/Screen.hpp"
    "src/screens/CRUDScreen.hpp"
    "src/screens/Home.hpp"
    "src/screens/Outros.hpp"
    "src/screens/Livros.hpp"
    "src/screens/Turmas.hpp"
    "src/screens/Alunos.hpp"
    "src/screens/Emprestimos.hpp"
    "src/dao/DAO.hpp"
    "src/dao/LivroDAO.hpp"
    "src/dao/TurmaDAO.hpp"
    "src/dao/AlunoDAO.hpp"
    "src/dao/EmprestimoDAO.hpp"
)

target_include_directories(openlibraryhub PRIVATE src)

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
