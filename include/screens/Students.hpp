#pragma once

#include "dao/StudentDAO.hpp"
#include "screens/CRUDScreen.hpp"

class Students : public CRUDScreen
{
public:
    Students(const Students&) = delete;
    Students& operator=(const Students&) = delete;
    static Students& getInstance();

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;

private:
    Students() = default;
    ~Students() override = default;

    StudentDAO& dao = StudentDAO::getInstance();
};
