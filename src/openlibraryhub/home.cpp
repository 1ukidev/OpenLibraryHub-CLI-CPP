#include "home.h"

void Home::welcome()
{
	bool running = true;
	while (running) {
		std::cout << "Bem-vindo ao OpenLibraryHub!\n";
		std::cout << "O que deseja fazer?\n";
		std::cout << "1 - Livros\n";
		std::cout << "2 - Turmas\n";
		std::cout << "3 - Alunos\n";
		std::cout << "4 - Emprestimo\n";
		std::cout << "5 - Outros\n";
		std::cout << "6 - Sair\n";
		std::cout << "--> ";

		running = handleOption();
	}
}

bool Home::handleOption()
{
	unsigned int opcao = Util::iscan();
	Util::clean();

	switch (opcao) {
	case 1:
		Books::welcome();
		break;
	case 6:
		std::cout << "Ate mais!\n";
		return false;
		break;
	default:
		std::cout << "Opcao desconhecida...\n\n";
	}

	return true;
}
