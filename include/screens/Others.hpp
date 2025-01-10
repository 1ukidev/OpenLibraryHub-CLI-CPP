#pragma once

#include "screens/Screen.hpp"

class Others : public Screen
{
public:
    Others() = default;
    ~Others() = default;

    void display() override;
    bool handleOption() override;
    void about();
};
