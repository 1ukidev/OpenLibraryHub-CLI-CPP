#include "dao/StudentDAO.hpp"
#include "Database.hpp"
#include "DatabaseManager.hpp"
#include "DbConfig.hpp"
#include "entities/StudentEntity.hpp"

#include <boost/mysql/statement.hpp>
#include <boost/mysql/results.hpp>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

bool StudentDAO::save(StudentEntity& entity)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return false;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "INSERT INTO alunos (nome, turma) VALUES (?, ?)"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.getName(), entity.getClassEntity().getId().value()), results);

        if (results.affected_rows() == 0) {
            return false;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool StudentDAO::update(StudentEntity& entity)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return false;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "UPDATE alunos SET nome = ?, turma = ? WHERE id = ?"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.getName(), entity.getClassEntity().getId().value(),
                              entity.getId().value()), results);

        if (results.affected_rows() == 0) {
            return false;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool StudentDAO::_delete(const std::string& where)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return false;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "DELETE FROM alunos WHERE " + where
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

std::vector<StudentEntity> StudentDAO::search(const std::string& where)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return {};
    }

    std::vector<StudentEntity> students;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "SELECT * FROM alunos WHERE " + where
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(), results);

        for (const auto& row : results.rows()) {
            StudentEntity student;
            
            student.setId(row[0].as_uint64());
            student.setName(row[1].as_string());
            student.getClassEntity().setId(row[2].as_uint64());

            students.push_back(student);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return {};
    }

    return students;
}
