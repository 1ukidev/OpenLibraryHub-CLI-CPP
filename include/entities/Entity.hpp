#pragma once

#include <boost/mysql/row_view.hpp>
#include <cstdint>
#include <string>
#include <unordered_map>

class Entity
{
public:
    virtual ~Entity() = default;

    virtual std::string getClassName() const = 0;
    virtual std::string getTable() const = 0;
    virtual const std::unordered_map<std::string, std::string> getColumns() const = 0;
    virtual void fromRowSet(const boost::mysql::row_view& row) = 0;

    virtual uint64_t getId() const = 0;
    virtual void setId(uint64_t id) = 0;

    virtual std::string toString() const = 0;
};
