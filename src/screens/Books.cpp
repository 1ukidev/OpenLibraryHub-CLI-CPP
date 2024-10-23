#include "dao/BookDAO.hpp"
#include "entities/BookEntity.hpp"
#include "screens/Books.hpp"
#include "Util.hpp"

#include <iostream>
#include <string>
#include <vector>

void Books::display()
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
    unsigned int option = Util::uiscan();
    Util::clean();

    switch (option) {
        // 1 - Cadastrar livro
        case 1:
            save();
            break;
        // 2 - Atualizar livro
        case 2:
            update();
            break;
        // 3 - Excluir livro
        case 3:
            _delete();
            break;
        // 4 - Buscar livro
        case 4:
            search();
            break;
        // 5 - Listar livros
        case 5:
            list();
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

void Books::save()
{
    std::cout << "Digite o nome do livro: ";
    std::string title = Util::scan();

    std::cout << "Digite o nome do autor: ";
    std::string author = Util::scan();

    std::cout << "Digite a seção: ";
    std::string section = Util::scan();

    std::cout << "Digite o numero de páginas: ";
    unsigned int pages = Util::uiscan();

    std::cout << "Digite o ano de publicação: ";
    unsigned int year = Util::uiscan();

    std::cout << "Digite a quantidade em estoque: ";
    unsigned int stock = Util::uiscan();

    BookEntity book(title, author, section, pages, year, stock);

    BookDAO dao;
    dao.save(book);

    if (book.getId().has_value()) {
        Util::clean();
        std::cout << "Livro cadastrado com sucesso!\n\n";
    } else {
        std::cerr << "Erro ao cadastrar livro...\n\n";
    }
}

void Books::update()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    BookDAO dao;
    std::vector<BookEntity> books = dao.search(where);

    Util::clean();
    if (books.empty()) {
        std::cerr << "Livro não encontrado...\n\n";
        return;
    } else if (books.size() > 1) {
        std::cerr << "Mais de um livro encontrado...\n\n";
        return;
    }

    BookEntity book = books[0];

    std::cout << "Digite o nome do livro: ";
    std::string title = Util::scan();

    std::cout << "Digite o nome do autor: ";
    std::string author = Util::scan();

    std::cout << "Digite a seção: ";
    std::string section = Util::scan();

    std::cout << "Digite o numero de páginas: ";
    unsigned int pages = Util::uiscan();

    std::cout << "Digite o ano de publicação: ";
    unsigned int year = Util::uiscan();

    std::cout << "Digite a quantidade em estoque: ";
    unsigned int stock = Util::uiscan();

    book.setTitle(title);
    book.setAuthor(author);
    book.setSection(section);
    book.setPages(pages);
    book.setYear(year);
    book.setStock(stock);

    dao.update(book);

    Util::clean();
    std::cout << "Livro atualizado com sucesso!\n\n";
}

void Books::_delete()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    BookDAO dao;

    Util::clean();
    if (!dao._delete(where)) {
        std::cerr << "Erro ao excluir livro...\n\n";
        return;
    } else {
        std::cout << "Livro excluído com sucesso!\n\n";
    }
}

void Books::search()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    BookDAO dao;
    std::vector<BookEntity> books = dao.search(where);

    Util::clean();
    if (books.empty()) {
        std::cerr << "Nenhum livro encontrado...\n\n";
        return;
    }

    for (const auto& book : books) {
        std::cout << book.toString() << '\n';
    }
}

void Books::list()
{
    BookDAO dao;
    std::vector<BookEntity> books = dao.search("1=1");

    if (books.empty()) {
        std::cerr << "Nenhum livro cadastrado...\n\n";
        return;
    }

    for (const auto& book : books) {
        std::cout << book.toString() << '\n';
    }
}
