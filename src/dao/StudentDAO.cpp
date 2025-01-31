#include "dao/StudentDAO.hpp"

StudentDAO& StudentDAO::getInstance()
{
    static StudentDAO instance;
    return instance;
}
