#include "entities/LivroEntity.hpp"
#include "screens/Livros.hpp"
#include "Util.hpp"

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

Livros& Livros::getInstance()
{
    static Livros instance;
    return instance;
}

void Livros::display()
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

bool Livros::handleOption()
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

void Livros::save()
{
    std::cout << "Digite o nome do livro: ";
    std::string titulo = Util::scan();

    std::cout << "Digite o nome do autor: ";
    std::string autor = Util::scan();

    std::cout << "Digite a seção: ";
    std::string secao = Util::scan();

    std::cout << "Digite o número de páginas: ";
    uint64_t paginas = Util::uscan();

    std::cout << "Digite o ano de publicação: ";
    uint64_t ano = Util::uscan();

    std::cout << "Digite a quantidade em estoque: ";
    uint64_t estoque = Util::uscan();

    LivroEntity livro(titulo, autor, secao, paginas, ano, estoque);

    if (!dao.save(livro)) {
        std::cerr << "Erro ao cadastrar livro...\n\n";
    } else {
        Util::clean();
        std::cout << "Livro cadastrado com sucesso!\n\n";
    }
}

void Livros::update()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<LivroEntity> livros = dao.search(where);

    if (livros.empty()) {
        std::cerr << "Livro não encontrado...\n\n";
        return;
    } else if (livros.size() > 1) {
        std::cerr << "Mais de um livro encontrado...\n\n";
        return;
    }

    LivroEntity livro = livros[0];

    std::cout << "Digite o novo nome do livro: ";
    std::string titulo = Util::scan();

    std::cout << "Digite o novo nome do autor: ";
    std::string autor = Util::scan();

    std::cout << "Digite a nova seção: ";
    std::string secao = Util::scan();

    std::cout << "Digite o novo número de páginas: ";
    uint64_t paginas = Util::uscan();

    std::cout << "Digite o novo ano de publicação: ";
    uint64_t ano = Util::uscan();

    std::cout << "Digite a nova quantidade em estoque: ";
    uint64_t estoque = Util::uscan();

    livro.setTitulo(titulo);
    livro.setAutor(autor);
    livro.setSecao(secao);
    livro.setPaginas(paginas);
    livro.setAno(ano);
    livro.setEstoque(estoque);

    if (!dao.update(livro)) {
        std::cerr << "Erro ao atualizar livro...\n\n";
    } else {
        Util::clean();
        std::cout << "Livro atualizado com sucesso!\n\n";
    }
}

void Livros::remove()
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

void Livros::search()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<LivroEntity> livros = dao.search(where);

    if (livros.empty()) {
        std::cerr << "Nenhum livro encontrado...\n\n";
        return;
    }

    Util::clean();
    for (const auto& book : livros)
        std::cout << book.toString() << '\n';
}

void Livros::list()
{
    std::vector<LivroEntity> livros = dao.search("1=1");

    if (livros.empty()) {
        std::cerr << "Nenhum livro cadastrado...\n\n";
        return;
    }

    for (const auto& book : livros)
        std::cout << book.toString() << '\n';
}
