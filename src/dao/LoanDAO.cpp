#include "dao/LoanDAO.hpp"
#include "Database.hpp"
#include "DatabaseManager.hpp"
#include "DbConfig.hpp"
#include "entities/LoanEntity.hpp"

#include <boost/mysql/statement.hpp>
#include <boost/mysql/results.hpp>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

// TODO
bool LoanDAO::save(const LoanEntity& entity)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return false;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "INSERT INTO emprestimos (aluno, livro, data_emprestimo, data_devolucao) VALUES (?, ?, ?, ?)"
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

// TODO
bool LoanDAO::update(const LoanEntity& entity)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return false;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "UPDATE emprestimos SET aluno = ?, livro = ?, data_emprestimo = ?, data_devolucao = ? WHERE id = ?"
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

bool LoanDAO::_delete(const std::string& where)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return false;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "DELETE FROM emprestimos WHERE " + where
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(), results);

        if (results.affected_rows() == 0) {
            return false;
        }
    } catch (const std::exception& e) {
        return false;
    }

    return true;
}

// TODO
std::vector<LoanEntity> LoanDAO::search(const std::string& where)
{
    std::vector<LoanEntity> loans;

    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return loans;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "SELECT * FROM emprestimos WHERE " + where
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(), results);

        for (const auto& row : results.rows()) {
            LoanEntity loan;

            loan.setId(row[0].get_uint64());

            loans.push_back(loan);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return loans;
    }

    return loans;
}
