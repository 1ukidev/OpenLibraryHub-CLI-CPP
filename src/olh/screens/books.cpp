#include <iostream>

#include "screens/books.hpp"
#include "dao/book_dao.hpp"
#include "entities/book_entity.hpp"
#include "util.hpp"

void olh::books::display()
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

        running = handle_option();
    }
}

bool olh::books::handle_option()
{
    unsigned int option = olh::util::uiscan();
    olh::util::clean();

    switch (option) {
        // 1 - Cadastrar livro
        case 1:
            save();
            break;
        // 6 - Voltar
        case 6:
            return false;
            break;
        default:
            std::cerr << "Opção inválida...\n\n";
            break;
    }

    return true;
}

void olh::books::save()
{
    std::cout << "Digite o nome do livro: ";
    std::string title = olh::util::scan();

    std::cout << "Digite o nome do autor: ";
    std::string author = olh::util::scan();

    std::cout << "Digite a seção: ";
    std::string section = olh::util::scan();

    std::cout << "Digite o numero de páginas: ";
    unsigned int pages = olh::util::uiscan();

    std::cout << "Digite o ano de publicação: ";
    unsigned int year = olh::util::uiscan();

    std::cout << "Digite a quantidade em estoque: ";
    unsigned int stock = olh::util::uiscan();

    book_entity book(title, author, section, pages, year, stock);

    book_dao dao;
    dao.save(book);

    if (book.get_id().has_value()) {
        olh::util::clean();
        std::cout << "Livro cadastrado com sucesso!\n\n";
    } else {
        std::cerr << "Erro ao cadastrar livro...\n\n";
    }
}
