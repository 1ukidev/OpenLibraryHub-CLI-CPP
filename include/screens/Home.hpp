#pragma once

#include "screens/Screen.hpp"

class Home : public Screen
{
public:
    Home() = default;
    ~Home() override = default;

    void display() override;
    bool handleOption() override;
};
