#pragma once

#include <boost/mysql/row_view.hpp>
#include <string>
#include <unordered_map>

#define DECLARE_ENTITY(class_name, table_name)                                      \
    std::string getClassName() const override { return #class_name; }               \
    std::string getTable() const override { return #table_name; }                   \
    const std::unordered_map<std::string, std::string> getColumns() const override; \
    void fromRowSet(const boost::mysql::row_view& row) override;                    \
    std::string toString() const override;

class Entity
{
public:
    virtual ~Entity() = default;

    virtual std::string getClassName() const = 0;
    virtual std::string getTable() const = 0;
    virtual const std::unordered_map<std::string, std::string> getColumns() const = 0;
    virtual void fromRowSet(const boost::mysql::row_view& row) = 0;

    virtual std::string toString() const = 0;
};
