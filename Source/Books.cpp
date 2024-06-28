#include "Books.h"

void Books::welcome()
{
	bool running = true;
	while (running) {
		std::cout << "1 - Cadastrar livro\n";
		std::cout << "2 - Atualizar livro\n";
		std::cout << "3 - Excluir livro\n";
		std::cout << "4 - Buscar livro\n";
		std::cout << "5 - Listar livros\n";
		std::cout << "6 - Voltar\n";
		std::cout << "--> ";

		running = handleOption();
	}
}

bool Books::handleOption()
{
	unsigned int opcao = Util::iscan();
	Util::clean();

	switch (opcao) {
	case 1:
		save();
		break;
	case 6:
		return false;
		break;
	default:
		std::cerr << "Opcao desconhecida...\n\n";
		break;
	}

	return true;
}

void Books::save()
{
	std::cout << "Digite o nome do livro: ";
	std::string title = Util::scan();

	std::cout << "Digite o nome do autor: ";
	std::string author = Util::scan();

	std::cout << "Digite a secao: ";
	std::string section = Util::scan();

	std::cout << "Digite o numero de paginas: ";
	unsigned int pages = Util::iscan();

	std::cout << "Digite o ano de publicacao: ";
	unsigned int year = Util::iscan();

	std::cout << "Digite a quantidade em estoque: ";
	unsigned int stock = Util::iscan();

	BookEntity bookEntity(title, author,
						  section, pages,
						  year, stock);

	bookEntity = BookDAO::save(bookEntity);

	if (bookEntity.getId() != empty) {
		Util::clean();
		std::cout << "Livro cadastrado com sucesso!\n\n";
	}
}
