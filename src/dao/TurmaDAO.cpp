#include "dao/TurmaDAO.hpp"

TurmaDAO& TurmaDAO::getInstance()
{
    static TurmaDAO instance;
    return instance;
}
