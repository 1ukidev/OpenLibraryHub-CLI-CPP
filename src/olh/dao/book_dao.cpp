#include <iostream>

#include <boost/mysql/statement.hpp>
#include <boost/mysql/results.hpp>

#include "dao/book_dao.hpp"
#include "database.hpp"

void olh::book_dao::save(book_entity& entity)
{
    olh::database db;

    try {
        db.connect("127.0.0.1", 3306, "smt", "123456", "openlibraryhub");
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return;
    }

    try {
        boost::mysql::statement stmt = db.connection.prepare_statement(
            "INSERT INTO books (title, author, section, pages, year, stock) VALUES (?, ?, ?, ?, ?, ?)"
        );

        boost::mysql::results results;
        db.connection.execute(stmt.bind(entity.get_title(), entity.get_author(), entity.get_section(),
                              entity.get_pages(), entity.get_year(), entity.get_stock()), results);

        const unsigned int new_id = results.last_insert_id();
        entity.set_id(new_id);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return;
    }
}
