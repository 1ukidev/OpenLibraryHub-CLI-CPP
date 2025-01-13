#pragma once

#include "screens/CRUDScreen.hpp"

class Books : public CRUDScreen
{
public:
    Books() = default;
    ~Books() override = default;

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;
};
