#include "dao/ClassDAO.hpp"
#include "Database.hpp"
#include "DatabaseManager.hpp"

#include <boost/mysql/statement.hpp>
#include <boost/mysql/results.hpp>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

bool ClassDAO::save(const ClassEntity& entity)
{
    Database db;
    if (!DatabaseManager::initDatabase(db))
        return false;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "INSERT INTO turmas (nome) VALUES (?)"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.name), results);

        if (results.affected_rows() == 0)
            return false;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool ClassDAO::update(const ClassEntity& entity)
{
    Database db;
    if (!DatabaseManager::initDatabase(db))
        return false;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "UPDATE turmas SET nome = ? WHERE id = ?"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.name, entity.id), results);

        if (results.affected_rows() == 0)
            return false;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool ClassDAO::remove(const std::string& where)
{
    Database db;
    if (!DatabaseManager::initDatabase(db))
        return false;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "DELETE FROM turmas WHERE " + where
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(), results);

        if (results.affected_rows() == 0)
            return false;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

std::vector<ClassEntity> ClassDAO::search(const std::string& where)
{
    std::vector<ClassEntity> classes;

    Database db;
    if (!DatabaseManager::initDatabase(db))
        return classes;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "SELECT * FROM turmas WHERE " + where
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(), results);

        for (const auto& row : results.rows()) {
            ClassEntity classEntity;

            classEntity.id = row[0].as_uint64();
            classEntity.name = row[1].as_string();

            classes.push_back(classEntity);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return classes;
    }

    return classes;
}
