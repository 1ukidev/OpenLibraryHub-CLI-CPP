#include "dao/BookDAO.hpp"

BookDAO& BookDAO::getInstance()
{
    static BookDAO instance;
    return instance;
}
