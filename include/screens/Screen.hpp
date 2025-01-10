#pragma once

class Screen
{
public:
    virtual ~Screen() = default;
    virtual void display() = 0;
    virtual bool handleOption() = 0;
};
