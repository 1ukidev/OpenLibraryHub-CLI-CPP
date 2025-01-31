#include "dao/LoanDAO.hpp"

LoanDAO& LoanDAO::getInstance()
{
    static LoanDAO instance;
    return instance;
}
