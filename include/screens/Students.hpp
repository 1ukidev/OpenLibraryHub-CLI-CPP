#pragma once

#include "screens/CRUDScreen.hpp"

class Students : public CRUDScreen
{
public:
    Students() = default;
    ~Students() = default;

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;
};
