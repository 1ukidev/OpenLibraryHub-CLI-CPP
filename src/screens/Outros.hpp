#pragma once

#include "screens/Screen.hpp"

class Outros final : public Screen
{
public:
    Outros() = default;
    ~Outros() = default;

    void display() override;
    bool handleOption() override;

private:
    void about();
};
