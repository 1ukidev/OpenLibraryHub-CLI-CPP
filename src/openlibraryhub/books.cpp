#include "books.h"

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
	case 6:
		return false;
		break;
	default:
		std::cerr << "Opcao desconhecida...\n\n";
		break;
	}

	return true;
}
