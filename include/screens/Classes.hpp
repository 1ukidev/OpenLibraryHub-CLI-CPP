#pragma once

#include "dao/ClassDAO.hpp"
#include "screens/CRUDScreen.hpp"

class Classes : public CRUDScreen
{
public:
    Classes(const Classes&) = delete;
    Classes& operator=(const Classes&) = delete;
    static Classes& getInstance();

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;

private:
    Classes() = default;
    ~Classes() override = default;

    ClassDAO& dao = ClassDAO::getInstance();
};
