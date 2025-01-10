#pragma once

#include "screens/CRUDScreen.hpp"

class Classes : public CRUDScreen
{
public:
    Classes() = default;
    ~Classes() = default;

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;
};
