#include "dao/LivroDAO.hpp"

LivroDAO& LivroDAO::getInstance()
{
    static LivroDAO instance;
    return instance;
}
