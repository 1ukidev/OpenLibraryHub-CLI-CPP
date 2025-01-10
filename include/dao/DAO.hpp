#pragma once

#include <string>
#include <vector>

template <class T>
class DAO
{
public:
    virtual ~DAO() = default;
    virtual bool save(const T& entity) = 0;
    virtual bool update(const T& entity) = 0;
    virtual bool remove(const std::string& where) = 0;
    virtual std::vector<T> search(const std::string& where) = 0;
};
