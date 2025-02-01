#include "dao/AlunoDAO.hpp"

AlunoDAO& AlunoDAO::getInstance()
{
    static AlunoDAO instance;
    return instance;
}
