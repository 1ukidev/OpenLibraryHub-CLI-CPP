#include "dao/ClassDAO.hpp"

ClassDAO& ClassDAO::getInstance()
{
    static ClassDAO instance;
    return instance;
}
