#include "book_dao.h"

using namespace mysqlx;

void BookDAO::save(BookEntity& book)
{
	try {
		Session session(db_url, db_port, db_user, db_password);
		Schema schema = session.getSchema(db_schema);
		Table table = schema.getTable("books");

		table.insert("title", "author", "section", "pages", "year", "stock")
			.values(book.getTitle(), book.getAuthor(),
				book.getSection(), book.getPages(),
				book.getYear(), book.getStock());

		std::cout << "Livro salvo com sucesso!\n";
	}
	catch (const Error& err) {
		std::cerr << "Ocorreu um erro ao salvar: " << err.what() << "\n\n";
	}
	catch (std::exception& ex) {
		std::cerr << "STD Exception: " << ex.what() << "\n\n";
	}
	catch (const char* ex) {
		std::cerr << "Exception: " << ex << "\n\n";
	}
}
