#pragma once

#include "screens/Screen.hpp"

class Home final : public Screen
{
public:
    Home() = default;
    ~Home() = default;

    void display() override;
    bool handleOption() override;
};
