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

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return false;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "INSERT INTO livros (titulo, autor, secao, paginas, ano, estoque) VALUES (?, ?, ?, ?, ?, ?)"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.getTitle(), entity.getAuthor(), entity.getSection(),
                              entity.getPages(), entity.getYear(), entity.getStock()), results);

        if (results.affected_rows() == 0) {
            return false;
        }
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

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return false;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "UPDATE livros SET titulo = ?, autor = ?, secao = ?, paginas = ?, ano = ?, estoque = ? WHERE id = ?"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.getTitle(), entity.getAuthor(), entity.getSection(),
                              entity.getPages(), entity.getYear(), entity.getStock(), entity.getId()), results);

        if (results.affected_rows() == 0) {
            return false;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool BookDAO::_delete(const std::string& where)
{
    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return false;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "DELETE FROM livros WHERE " + where
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

std::vector<BookEntity> BookDAO::search(const std::string& where)
{
    std::vector<BookEntity> books;

    Database db;
    DbConfig dbc;

    if (!DatabaseManager::initDatabase(db, dbc)) {
        return books;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "SELECT id, titulo, autor, secao, paginas, ano, estoque FROM livros WHERE " + where
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(), results);

        for (const auto& row : results.rows()) {
            BookEntity book;

            book.setId(row[0].as_uint64());
            book.setTitle(row[1].as_string());
            book.setAuthor(row[2].as_string());
            book.setSection(row[3].as_string());
            book.setPages(row[4].as_uint64());
            book.setYear(row[5].as_uint64());
            book.setStock(row[6].as_uint64());

            books.push_back(book);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return books;
    }

    return books;
}
