#pragma once

#include "screens/Screen.hpp"

class Home : public Screen
{
public:
    Home(const Home&) = delete;
    Home& operator=(const Home&) = delete;
    static Home& getInstance();

    void display() override;
    bool handleOption() override;

private:
    Home() = default;
    ~Home() override = default;
};
