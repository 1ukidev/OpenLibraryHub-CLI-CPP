// Copyright (c) 1ukidev <leo.monteiro06@live.com>. Licensed under the GPL-3.0 Licence.
// See the LICENCE file in the repository root for full licence text.

#include <iostream>
#include <cstdlib>
#include <string>

#include "main.h"
#include "util.h"
#include "dao.h"
#include "entities.h"

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
		// 1 - Cadastrar livro
		case 1:
			Books::save();
			break;
		// 4 - Buscar livro
		case 4:
			Books::search();
			break;
		// 5 - Listar livros
		case 5:
			Books::list();
			break;
		// 6 - Voltar
		case 6:
			return false;
			break;
		default:
			std::cerr << "Opção desconhecida...\n\n";
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

	std::cout << "Digite a seção: ";
	std::string section = Util::scan();

	std::cout << "Digite o numero de páginas: ";
	unsigned int pages = Util::iscan();

	std::cout << "Digite o ano de publicação: ";
	unsigned int year = Util::iscan();

	std::cout << "Digite a quantidade em estoque: ";
	unsigned int stock = Util::iscan();

	BookEntity book(title, author, section, pages, year, stock);

	BookDAO::save(book);

	if (book.getId() != 0) {
		Util::clean();
		std::cout << "Livro cadastrado com sucesso!\n\n";
	} else {
		std::cerr << "Erro ao cadastrar livro...\n\n";
	}
}

void Books::search()
{
	std::cout << "Digite o id do livro: ";
	unsigned int id = Util::iscan();
	auto bookOpt = BookDAO::getBookById(id);

	if (bookOpt.has_value()) {
		Util::clean();
		std::cout << bookOpt.value().toString() << '\n';
	} else {
		std::cerr << "\nLivro não encontrado...\n\n";
	}
}

void Books::list()
{
	auto books = BookDAO::getAll();

	if (books.size() > 0) {
		Util::clean();
		for (const auto& book : books) {
			std::cout << book.toString() << '\n';
		}
	} else {
		std::cerr << "\nNenhum livro cadastrado...\n\n";
	}
}

void Classes::welcome()
{
	bool running = true;
	while (running) {
		std::cout << "1 - Cadastrar turma\n";
		std::cout << "2 - Atualizar turma\n";
		std::cout << "3 - Excluir turma\n";
		std::cout << "4 - Buscar turma\n";
		std::cout << "5 - Listar turmas\n";
		std::cout << "6 - Voltar\n";
		std::cout << "--> ";

		running = handleOption();
	}
}

bool Classes::handleOption()
{
	unsigned int opcao = Util::iscan();
	Util::clean();

	switch (opcao) {
		// 6 - Voltar
		case 6:
			return false;
			break;
		default:
			std::cerr << "Opção desconhecida...\n\n";
			break;
	}

	return true;
}

void Students::welcome()
{
	bool running = true;
	while (running) {
		std::cout << "1 - Cadastrar aluno\n";
		std::cout << "2 - Atualizar aluno\n";
		std::cout << "3 - Excluir aluno\n";
		std::cout << "4 - Buscar aluno\n";
		std::cout << "5 - Listar alunos\n";
		std::cout << "6 - Voltar\n";
		std::cout << "--> ";

		running = handleOption();
	}
}

bool Students::handleOption()
{
	unsigned int opcao = Util::iscan();
	Util::clean();

	switch (opcao) {
		// 6 - Voltar
		case 6:
			return false;
			break;
		default:
			std::cerr << "Opção desconhecida...\n\n";
			break;
	}

	return true;
}

void Loans::welcome()
{
	bool running = true;
	while (running) {
		std::cout << "1 - Cadastrar empréstimo\n";
		std::cout << "2 - Atualizar empréstimo\n";
		std::cout << "3 - Excluir empréstimo\n";
		std::cout << "4 - Buscar empréstimo\n";
		std::cout << "5 - Listar empréstimos\n";
		std::cout << "6 - Voltar\n";
		std::cout << "--> ";

		running = handleOption();
	}
}

bool Loans::handleOption()
{
	unsigned int opcao = Util::iscan();
	Util::clean();

	switch (opcao) {
		// 6 - Voltar
		case 6:
			return false;
			break;
		default:
			std::cerr << "Opção desconhecida...\n\n";
			break;
	}

	return true;
}

void Others::welcome()
{
	bool running = true;
	while (running) {
		std::cout << "1 - Sobre\n";
		std::cout << "2 - Sair\n";
		std::cout << "--> ";

		running = handleOption();
	}
}

bool Others::handleOption()
{
	unsigned int opcao = Util::iscan();
	Util::clean();

	switch (opcao) {
		// 1 - Sobre
		case 1:
			Others::about();
			break;
		// 2 - Sair
		case 2:
			return false;
			break;
		default:
			std::cerr << "Opção desconhecida...\n\n";
			break;
	}

	return true;
}

void Others::about()
{
	std::cout << "OpenLibraryHub é um sistema de gerenciamento de bibliotecas.\n";
	std::cout << "Desenvolvido por: 1ukidev\n";
	std::cout << "GitHub: https://github.com/1ukidev/OpenLibraryHub-CLI-CPP\n";
	std::cout << "Licença: GPL-3.0\n";
	std::cout << "Versão: " << VERSION << "\n\n";
}

void Home::welcome()
{
	bool running = true;
	while (running) {
		std::cout << "Bem-vindo ao OpenLibraryHub!\n\n";
		std::cout << "O que deseja fazer?\n\n";
		std::cout << "1 - Livros\n";
		std::cout << "2 - Turmas\n";
		std::cout << "3 - Alunos\n";
		std::cout << "4 - Empréstimo\n";
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
		// 1 - Livros
		case 1:
			Books::welcome();
			break;
		// 2 - Turmas
		case 2:
			Classes::welcome();
			break;
		// 3 - Alunos
		case 3:
			Students::welcome();
			break;
		// 4 - Empréstimos
		case 4:
			Loans::welcome();
			break;
		// 5 - Outros
		case 5:
			Others::welcome();
			break;
		// 6 - Sair
		case 6:
			std::cout << "Até mais!\n";
			return false;
			break;
		default:
			std::cerr << "Opção desconhecida...\n\n";
			break;
	}

	return true;
}

int main()
{
	Util::clean();
	Home::welcome();
	return EXIT_SUCCESS;
}
