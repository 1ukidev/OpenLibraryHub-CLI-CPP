#pragma once

#include "Database.hpp"
#include "DatabaseManager.hpp"
#include "entities/Entity.hpp"

#include <boost/mysql/results.hpp>
#include <boost/mysql/statement.hpp>
#include <exception>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template <class T>
concept IsEntity = std::is_base_of_v<Entity, T>;

template <IsEntity T>
class DAO
{
public:
    virtual ~DAO() = default;

    virtual bool save(T& entity) {
        Database db;
        if (!DatabaseManager::initDatabase(db))
            return false;

        try {
            std::string sql = buildInsertQuery(entity);
            boost::mysql::results results;
            db.connection.execute(sql, results);

            if (results.affected_rows() == 0)
                return false;
            else
                entity.setId(results.last_insert_id());
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            return false;
        }
 
        return true;
    }

    virtual bool update(const T& entity) {
        Database db;
        if (!DatabaseManager::initDatabase(db))
            return false;

        try {
            std::string sql = buildUpdateQuery(entity);
            boost::mysql::statement stmt = db.connection.prepare_statement(sql);

            boost::mysql::results results;
            db.connection.execute(stmt.bind(entity.getId()), results);

            if (results.affected_rows() == 0)
                return false;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            return false;
        }

        return true;
    }

    virtual bool remove(const std::string& where) {
        Database db;
        if (!DatabaseManager::initDatabase(db))
            return false;

        try {
            std::string sql = "DELETE FROM " + T().getTable() + " WHERE " + where;
            boost::mysql::results results;
            db.connection.execute(sql, results);

            if (results.affected_rows() == 0)
                return false;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            return false;
        }

        return true;
    }

    virtual std::vector<T> search(const std::string& where) {
        std::vector<T> entities;

        Database db;
        if (!DatabaseManager::initDatabase(db))
            return entities;

        try {
            std::string sql = "SELECT * FROM " + T().getTable() + " WHERE " + where;
            boost::mysql::results results;
            db.connection.execute(sql, results);
            
            if (!results.empty()) {
                for (const auto& row : results.rows()) {
                    T entity;
                    entity.fromRowSet(row);
                    entities.push_back(entity);
                }
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            return entities;
        }

        return entities;
    }

private:
    std::string buildInsertQuery(const T& entity) {
        std::string sql = "INSERT INTO " + entity.getTable() + " (";
        for (const auto& [column, _] : entity.getColumns()) {
            sql += column + ", ";
        }
        sql.pop_back(); sql.pop_back();

        sql += ") VALUES (";
        for (const auto& [_, value] : entity.getColumns()) {
            sql += "'" + value + "', ";
        }
        sql.pop_back(); sql.pop_back();
        sql += ")";

        return sql;
    }

    std::string buildUpdateQuery(const T& entity) {
        std::string sql = "UPDATE " + entity.getTable() + " SET ";
        for (const auto& [column, value] : entity.getColumns()) {
            sql += column + " = '" + value + "', ";
        }
        sql.pop_back(); sql.pop_back();
        sql += " WHERE id = ?";

        return sql;
    }
};
