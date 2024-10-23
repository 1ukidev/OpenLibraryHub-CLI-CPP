#pragma once

#include <string>
#include <vector>

template <class T>
class DAO
{
public:
    virtual ~DAO() = default;
    virtual void save(T& entity) = 0;
    virtual void update(T& entity) = 0;
    virtual bool _delete(const std::string& where) = 0;
    virtual std::vector<T> search(const std::string& where) = 0;
};
