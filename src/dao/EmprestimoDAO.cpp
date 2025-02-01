#include "dao/EmprestimoDAO.hpp"

EmprestimoDAO& EmprestimoDAO::getInstance()
{
    static EmprestimoDAO instance;
    return instance;
}
