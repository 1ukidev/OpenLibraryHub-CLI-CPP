#include "entities/BookEntity.hpp"
#include "screens/Books.hpp"
#include "Util.hpp"

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

Books& Books::getInstance()
{
    static Books instance;
    return instance;
}

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
    unsigned int option = Util::uscan();
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
            remove();
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

    std::cout << "Digite o número de páginas: ";
    uint64_t pages = Util::uscan();

    std::cout << "Digite o ano de publicação: ";
    uint64_t year = Util::uscan();

    std::cout << "Digite a quantidade em estoque: ";
    uint64_t stock = Util::uscan();

    BookEntity book(title, author, section, pages, year, stock);

    if (!dao.save(book)) {
        std::cerr << "Erro ao cadastrar livro...\n\n";
    } else {
        Util::clean();
        std::cout << "Livro cadastrado com sucesso!\n\n";
    }
}

void Books::update()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<BookEntity> books = dao.search(where);

    if (books.empty()) {
        std::cerr << "Livro não encontrado...\n\n";
        return;
    } else if (books.size() > 1) {
        std::cerr << "Mais de um livro encontrado...\n\n";
        return;
    }

    BookEntity book = books[0];

    std::cout << "Digite o novo nome do livro: ";
    std::string title = Util::scan();

    std::cout << "Digite o novo nome do autor: ";
    std::string author = Util::scan();

    std::cout << "Digite a nova seção: ";
    std::string section = Util::scan();

    std::cout << "Digite o novo número de páginas: ";
    uint64_t pages = Util::uscan();

    std::cout << "Digite o novo ano de publicação: ";
    uint64_t year = Util::uscan();

    std::cout << "Digite a nova quantidade em estoque: ";
    uint64_t stock = Util::uscan();

    book.setTitle(title);
    book.setAuthor(author);
    book.setSection(section);
    book.setPages(pages);
    book.setYear(year);
    book.setStock(stock);

    if (!dao.update(book)) {
        std::cerr << "Erro ao atualizar livro...\n\n";
    } else {
        Util::clean();
        std::cout << "Livro atualizado com sucesso!\n\n";
    }
}

void Books::remove()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    if (!dao.remove(where)) {
        std::cerr << "Erro ao excluir livro...\n\n";
    } else {
        Util::clean();
        std::cout << "Livro excluído com sucesso!\n\n";
    }
}

void Books::search()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<BookEntity> books = dao.search(where);

    if (books.empty()) {
        std::cerr << "Nenhum livro encontrado...\n\n";
        return;
    }

    Util::clean();
    for (const auto& book : books)
        std::cout << book.toString() << '\n';
}

void Books::list()
{
    std::vector<BookEntity> books = dao.search("1=1");

    if (books.empty()) {
        std::cerr << "Nenhum livro cadastrado...\n\n";
        return;
    }

    for (const auto& book : books)
        std::cout << book.toString() << '\n';
}
