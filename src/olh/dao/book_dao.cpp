#include <iostream>

#include <boost/mysql/statement.hpp>
#include <boost/mysql/results.hpp>

#include "config.hpp"
#include "dao/book_dao.hpp"
#include "database.hpp"
#include "db_config.hpp"
#include "entities/book_entity.hpp"

void olh::book_dao::save(book_entity& entity)
{
    config cfg;

    if (!cfg.load()) {
        std::cerr << "Erro ao carregar arquivo de configuração\n";
        return;
    }

    db_config dbc;
    cfg.put_database(dbc);

    database db;

    try {
        db.connect(dbc.host, dbc.port, dbc.user, dbc.password, dbc.database);
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
