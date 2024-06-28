#include "BookDAO.h"

using namespace mysqlx;

BookEntity& BookDAO::save(BookEntity& book)
{
	try {
		Session session(db_url, db_port, db_user, db_password);
		Schema schema = session.getSchema(db_schema);
		Table table = schema.getTable("books");

		Result result = table.insert("title", "author", "section", "pages", "year", "stock")
							 .values(book.getTitle(), book.getAuthor(),
									 book.getSection(), book.getPages(),
									 book.getYear(), book.getStock())
							 .execute();

		RowResult rowResult = session.sql("SELECT LAST_INSERT_ID()").execute();
		Row row = rowResult.fetchOne();
		if (!row.isNull()) {
			book.setId(row[0]);
		}

		std::cout << "Livro salvo com sucesso!\n";

		session.close();
	}
	catch (const Error& err) {
		std::cerr << "\nOcorreu um erro ao salvar: " << err.what() << "\n\n";
	}
	catch (std::exception& ex) {
		std::cerr << "\nSTD Exception: " << ex.what() << "\n\n";
	}
	catch (const char* ex) {
		std::cerr << "\nException: " << ex << "\n\n";
	}

	return book;
}
