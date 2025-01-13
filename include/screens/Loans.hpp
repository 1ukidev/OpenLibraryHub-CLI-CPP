#pragma once

#include "screens/CRUDScreen.hpp"

class Loans : public CRUDScreen
{
public:
    Loans() = default;
    ~Loans() override = default;

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;
};
