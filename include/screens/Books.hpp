#pragma once

#include "dao/BookDAO.hpp"
#include "screens/CRUDScreen.hpp"

class Books : public CRUDScreen
{
public:
    Books(const Books&) = delete;
    Books& operator=(const Books&) = delete;
    static Books& getInstance();

    void display() override;
    bool handleOption() override;
    void save() override;
    void update() override;
    void remove() override;
    void search() override;
    void list() override;

private:
    Books() = default;
    ~Books() override = default;

    BookDAO& dao = BookDAO::getInstance();
};
