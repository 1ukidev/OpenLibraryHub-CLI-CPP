#pragma once

#include "screens/Screen.hpp"

class Outros : public Screen
{
public:
    Outros(const Outros&) = delete;
    Outros& operator=(const Outros&) = delete;
    static Outros& getInstance();

    void display() override;
    bool handleOption() override;

private:
    Outros() = default;
    ~Outros() = default;

    void about();
};
