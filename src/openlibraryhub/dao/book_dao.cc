#include <iostream>

#include "dao/book_dao.h"
#include "database.h"

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
		mysql::statement stmt = db.connection.prepare_statement(
			"INSERT INTO books (title, author, section, pages, year, stock) VALUES (?, ?, ?, ?, ?, ?)"
		);		

		mysql::results results;
		db.connection.execute(stmt.bind(entity.getTitle(), entity.getAuthor(), entity.getSection(),
							  entity.getPages(), entity.getYear(), entity.getStock()), results);

		const unsigned int new_id = results.last_insert_id();
		entity.setId(new_id);
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return;
	}
}
