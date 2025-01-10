#pragma once

class CRUDScreen
{
public:
    virtual ~CRUDScreen() = default;
    virtual void display() = 0;
    virtual bool handleOption() = 0;
    virtual void save() = 0;
    virtual void update() = 0;
    virtual void remove() = 0;
    virtual void search() = 0;
    virtual void list() = 0;
};
