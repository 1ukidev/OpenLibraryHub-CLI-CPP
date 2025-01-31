#pragma once

#include "screens/Screen.hpp"

class Others : public Screen
{
public:
    Others(const Others&) = delete;
    Others& operator=(const Others&) = delete;
    static Others& getInstance();

    void display() override;
    bool handleOption() override;

private:
    Others() = default;
    ~Others() = default;

    void about();
};
