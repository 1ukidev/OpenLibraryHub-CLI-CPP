#include <iostream>
#include <optional>
#include <string>

#include <mysqlx/xdevapi.h>

#include "dao.h"
#include "config.h"
#include "entities.h"

using namespace mysqlx;

BookEntity& BookDAO::save(BookEntity& book)
{
	try {
		Session session(DB_URL, DB_PORT, DB_USER, DB_PASSWORD);
		Schema schema = session.getSchema(DB_SCHEMA);
		Table table = schema.getTable("books");

		Result result = table.insert("title", "author", "section",
									 "pages", "year", "stock")
							 .values(book.getTitle(), book.getAuthor(),
									 book.getSection(), book.getPages(),
									 book.getYear(), book.getStock())
							 .execute();

		RowResult rowResult = session.sql("SELECT LAST_INSERT_ID()").execute();
		Row row = rowResult.fetchOne();
		if (!row.isNull()) {
			book.setId(row[0].get<unsigned int>());
		}

		session.close();
	} catch (const Error& err) {
		std::cerr << "\nOcorreu um erro ao salvar: " << err.what() << "\n\n";
	} catch (const std::exception& ex) {
		std::cerr << "\nSTD Exception: " << ex.what() << "\n\n";
	} catch (const char* ex) {
		std::cerr << "\nException: " << ex << "\n\n";
	}

	return book;
}

std::optional<BookEntity> BookDAO::getBookById(unsigned int id)
{
	try {
		Session session(DB_URL, DB_PORT, DB_USER, DB_PASSWORD);
		Schema schema = session.getSchema(DB_SCHEMA);
		Table table = schema.getTable("books");

		RowResult rowResult = table.select("id", "title", "author",
										   "section", "pages", "year",
										   "stock")
								   .where("id = :id")
								   .bind("id", id)
								   .execute();

		Row row = rowResult.fetchOne();
		if (!row.isNull()) {
			BookEntity book;
			book.setId(row[0].get<unsigned int>())
				.setTitle(row[1].get<std::string>())
				.setAuthor(row[2].get<std::string>())
				.setSection(row[3].get<std::string>())
				.setPages(row[4].get<unsigned int>())
				.setYear(row[5].get<unsigned int>())
				.setStock(row[6].get<unsigned int>());
			session.close();
			return book;
		}

		session.close();
	} catch (const Error& err) {
		std::cerr << "\nOcorreu um erro ao buscar: " << err.what() << "\n\n";
	} catch (const std::exception& ex) {
		std::cerr << "\nSTD Exception: " << ex.what() << "\n\n";
	} catch (const char* ex) {
		std::cerr << "\nException: " << ex << "\n\n";
	}

	return std::nullopt;
}

std::vector<BookEntity> BookDAO::getAll()
{
	std::vector<BookEntity> books;

	try {
		Session session(DB_URL, DB_PORT, DB_USER, DB_PASSWORD);
		Schema schema = session.getSchema(DB_SCHEMA);
		Table table = schema.getTable("books");

		RowResult rowResult = table.select("id", "title", "author",
										   "section", "pages", "year",
										   "stock")
								   .execute();

		Row row;
		while ((row = rowResult.fetchOne())) {
			BookEntity book;
			book.setId(row[0].get<unsigned int>())
				.setTitle(row[1].get<std::string>())
				.setAuthor(row[2].get<std::string>())
				.setSection(row[3].get<std::string>())
				.setPages(row[4].get<unsigned int>())
				.setYear(row[5].get<unsigned int>())
				.setStock(row[6].get<unsigned int>());
			books.push_back(book);
		}

		session.close();
	} catch (const Error& err) {
		std::cerr << "\nOcorreu um erro ao buscar: " << err.what() << "\n\n";
	} catch (const std::exception& ex) {
		std::cerr << "\nSTD Exception: " << ex.what() << "\n\n";
	} catch (const char* ex) {
		std::cerr << "\nException: " << ex << "\n\n";
	}

	return books;
}
