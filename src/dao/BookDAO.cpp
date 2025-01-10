#include "dao/BookDAO.hpp"
#include "Database.hpp"
#include "DatabaseManager.hpp"
#include "DbConfig.hpp"
#include "entities/BookEntity.hpp"

#include <boost/mysql/statement.hpp>
#include <boost/mysql/results.hpp>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

bool BookDAO::save(const BookEntity& entity)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc))
        return false;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "INSERT INTO livros (titulo, autor, secao, paginas, ano, estoque) VALUES (?, ?, ?, ?, ?, ?)"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.title, entity.author, entity.section,
                              entity.pages, entity.year, entity.stock), results);

        if (results.affected_rows() == 0)
            return false;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool BookDAO::update(const BookEntity& entity)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc))
        return false;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "UPDATE livros SET titulo = ?, autor = ?, secao = ?, paginas = ?, ano = ?, estoque = ? WHERE id = ?"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.title, entity.author, entity.section,
                              entity.pages, entity.year, entity.stock, entity.id), results);

        if (results.affected_rows() == 0)
            return false;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool BookDAO::remove(const std::string& where)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc))
        return false;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "DELETE FROM livros WHERE " + where
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

std::vector<BookEntity> BookDAO::search(const std::string& where)
{
    std::vector<BookEntity> books;

    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc))
        return books;

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "SELECT id, titulo, autor, secao, paginas, ano, estoque FROM livros WHERE " + where
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(), results);

        for (const auto& row : results.rows()) {
            BookEntity book;

            book.id = row[0].as_uint64();
            book.title = row[1].as_string();
            book.author = row[2].as_string();
            book.section = row[3].as_string();
            book.pages = row[4].as_uint64();
            book.year = row[5].as_uint64();
            book.stock = row[6].as_uint64();

            books.push_back(book);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return books;
    }

    return books;
}
