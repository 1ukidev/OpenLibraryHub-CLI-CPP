#include "dao/ClassDAO.hpp"
#include "Database.hpp"
#include "DatabaseManager.hpp"
#include "DbConfig.hpp"

#include <boost/mysql/statement.hpp>
#include <boost/mysql/results.hpp>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

bool ClassDAO::save(ClassEntity& entity)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return false;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "INSERT INTO turmas (nome) VALUES (?)"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.getName()), results);

        if (results.affected_rows() == 0) {
            return false;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool ClassDAO::update(ClassEntity& entity)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return false;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "UPDATE turmas SET nome = ? WHERE id = ?"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.getName(), entity.getId()), results);

        if (results.affected_rows() == 0) {
            return false;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool ClassDAO::_delete(const std::string& where)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return false;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "DELETE FROM turmas WHERE " + where
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(), results);

        if (results.affected_rows() == 0) {
            return false;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

std::vector<ClassEntity> ClassDAO::search(const std::string& where)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return {};
    }

    std::vector<ClassEntity> entities;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "SELECT * FROM turmas WHERE " + where
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(), results);

        for (const auto& row : results.rows()) {
            ClassEntity _class;

            _class.setId(row[0].as_uint64());
            _class.setName(row[1].as_string());

            entities.push_back(_class);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return {};
    }

    return entities;
}
