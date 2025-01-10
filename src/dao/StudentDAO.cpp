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

bool StudentDAO::save(const StudentEntity& entity)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc))
        return false;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "INSERT INTO alunos (nome, turma) VALUES (?, ?)"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.name, entity.classEntity.id), results);

        if (results.affected_rows() == 0)
            return false;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool StudentDAO::update(const StudentEntity& entity)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc))
        return false;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "UPDATE alunos SET nome = ?, turma = ? WHERE id = ?"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.name, entity.classEntity.id, entity.id), results);

        if (results.affected_rows() == 0)
            return false;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool StudentDAO::remove(const std::string& where)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc))
        return false;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "DELETE FROM alunos WHERE " + where
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

std::vector<StudentEntity> StudentDAO::search(const std::string& where)
{
    std::vector<StudentEntity> students;

    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc))
        return students;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "SELECT * FROM alunos WHERE " + where
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(), results);

        for (const auto& row : results.rows()) {
            StudentEntity student;
            
            student.id = row[0].as_uint64();
            student.name = row[1].as_string();
            student.classEntity = ClassEntity(row[2].as_uint64());

            students.push_back(student);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return students;
    }

    return students;
}
