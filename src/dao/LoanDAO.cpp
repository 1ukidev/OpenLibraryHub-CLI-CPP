#include "dao/LoanDAO.hpp"
#include "Database.hpp"
#include "DatabaseManager.hpp"
#include "Util.hpp"
#include "entities/BookEntity.hpp"
#include "entities/LoanEntity.hpp"
#include "entities/StudentEntity.hpp"

#include <boost/mysql/statement.hpp>
#include <boost/mysql/results.hpp>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

bool LoanDAO::save(const LoanEntity& entity)
{
    Database db;
    if (!DatabaseManager::initDatabase(db))
        return false;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "INSERT INTO emprestimos (aluno, livro, data_emprestimo, data_devolucao) VALUES (?, ?, ?, ?)"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(
            entity.studentEntity.id,
            entity.bookEntity.id,
            Util::timePointToString(entity.loanDate, "{:%Y-%m-%d}"),
            Util::timePointToString(entity.returnDate, "{:%Y-%m-%d}")
        ), results);

        if (results.affected_rows() == 0)
            return false;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool LoanDAO::update(const LoanEntity& entity)
{
    Database db;
    if (!DatabaseManager::initDatabase(db))
        return false;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "UPDATE emprestimos SET aluno = ?, livro = ?, data_emprestimo = ?, data_devolucao = ? WHERE id = ?"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(
            entity.studentEntity.id,
            entity.bookEntity.id,
            Util::timePointToString(entity.loanDate, "{:%Y-%m-%d}"),
            Util::timePointToString(entity.returnDate, "{:%Y-%m-%d}"),
            entity.id
        ), results);

        if (results.affected_rows() == 0)
            return false;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool LoanDAO::remove(const std::string& where)
{
    Database db;
    if (!DatabaseManager::initDatabase(db))
        return false;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "DELETE FROM emprestimos WHERE " + where
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(), results);

        if (results.affected_rows() == 0)
            return false;
    } catch (const std::exception& e) {
        return false;
    }

    return true;
}

std::vector<LoanEntity> LoanDAO::search(const std::string& where)
{
    std::vector<LoanEntity> loans;

    Database db;
    if (!DatabaseManager::initDatabase(db))
        return loans;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "SELECT * FROM emprestimos WHERE " + where
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(), results);

        for (const auto& row : results.rows()) {
            LoanEntity loan;

            loan.id = row[0].get_uint64();
            loan.bookEntity = BookEntity(row[1].get_uint64());
            loan.studentEntity = StudentEntity(row[2].get_uint64());
            loan.loanDate = row[3].get_date().as_time_point();
            loan.returnDate = row[4].get_date().as_time_point();

            loans.push_back(loan);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return loans;
    }

    return loans;
}
