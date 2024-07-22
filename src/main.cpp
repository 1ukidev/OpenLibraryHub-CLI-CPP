// Copyright (c) 1ukidev <leo.monteiro06@live.com>. Licensed under the GPL-3.0 Licence.
// See the LICENCE file in the repository root for full licence text.

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

#include <mysqlx/xdevapi.h>

#include "main.h"
#include "config.h"

using namespace mysqlx;

inline void Util::clean()
{
    std::cout << "\033c" << std::flush;
}

std::string Util::scan()
{
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cerr << "Tente novamente: ";
        } else {
            return input;
        }
    }
}

unsigned int Util::iscan()
{
    unsigned int input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Tente novamente: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }
    }
}

int BookEntity::getId() const
{
    return this->id;
}

BookEntity& BookEntity::setId(int id)
{
    this->id = id;
    return *this;
}

std::string BookEntity::getTitle() const
{
    return this->title;
}

BookEntity& BookEntity::setTitle(std::string title)
{
    this->title = title;
    return *this;
}

std::string BookEntity::getAuthor() const
{
    return this->author;
}

BookEntity& BookEntity::setAuthor(std::string author)
{
    this->author = author;
    return *this;
}

std::string BookEntity::getSection() const
{
    return this->section;
}

BookEntity& BookEntity::setSection(std::string section)
{
    this->section = section;
    return *this;
}

unsigned int BookEntity::getPages() const
{
    return this->pages;
}

BookEntity& BookEntity::setPages(unsigned int pages)
{
    this->pages = pages;
    return *this;
}

unsigned int BookEntity::getYear() const
{
    return this->year;
}

BookEntity& BookEntity::setYear(unsigned int year)
{
    this->year = year;
    return *this;
}

unsigned int BookEntity::getStock() const
{
    return this->stock;
}

BookEntity& BookEntity::setStock(unsigned int stock)
{
    this->stock = stock;
    return *this;
}

BookEntity& BookDAO::save(BookEntity& book)
{
    try {
        Session session(db_url, db_port, db_user, db_password);
        Schema schema = session.getSchema(db_schema);
        Table table = schema.getTable("books");

        Result result = table.insert("title", "author", "section",
                                     "pages", "year", "stock")
                             .values(book.getTitle(), book.getAuthor(),
                                     book.getSection(), book.getPages(),
                                     book.getYear(), book.getStock())
                             .execute();

        RowResult rowResult = session.sql("SELECT LAST_INSERT_ID()").execute();
        Row row = rowResult.fetchOne();
        if (!row.isNull()) {
            book.setId(row[0]);
        }

        session.close();
    } catch (const Error& err) {
        std::cerr << "\nOcorreu um erro ao salvar: " << err.what() << "\n\n";
    } catch (const std::exception& ex) {
        std::cerr << "\nSTD Exception: " << ex.what() << "\n\n";
    } catch (const char* ex) {
        std::cerr << "\nException: " << ex << "\n\n";
    }

    return book;
}

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

    BookEntity bookEntity(title, author,
                          section, pages,
                          year, stock);

    bookEntity = BookDAO::save(bookEntity);

    if (bookEntity.getId() != EMPTY) {
        Util::clean();
        std::cout << "Livro cadastrado com sucesso!\n\n";
    }
}

int ClassEntity::getId() const
{
    return this->id;
}

ClassEntity& ClassEntity::setId(int id)
{
    this->id = id;
    return *this;
}

std::string ClassEntity::getName() const
{
    return this->name;
}

ClassEntity& ClassEntity::setName(std::string name)
{
    this->name = name;
    return *this;
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

int StudentEntity::getId() const
{
    return this->id;
}

StudentEntity& StudentEntity::setId(int id)
{
    this->id = id;
    return *this;
}

std::string StudentEntity::getName() const
{
    return this->name;
}

StudentEntity& StudentEntity::setName(std::string name)
{
    this->name = name;
    return *this;
}

ClassEntity* StudentEntity::getClassEntity() const
{
    return this->classEntity;
}

StudentEntity& StudentEntity::setClassEntity(ClassEntity* classEntity)
{
    this->classEntity = classEntity;
    return *this;
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

int LoanEntity::getId() const
{
    return this->id;
}

LoanEntity& LoanEntity::setId(int id)
{
    this->id = id;
    return *this;
}

BookEntity* LoanEntity::getBookEntity() const
{
    return this->bookEntity;
}

LoanEntity& LoanEntity::setBookEntity(BookEntity* bookEntity)
{
    this->bookEntity = bookEntity;
    return *this;
}

StudentEntity* LoanEntity::getStudentEntity() const
{
    return this->studentEntity;
}

LoanEntity& LoanEntity::setStudentEntity(StudentEntity* studentEntity)
{
    this->studentEntity = studentEntity;
    return *this;
}

std::string LoanEntity::getLoanDate() const
{
    return this->loanDate;
}

LoanEntity& LoanEntity::setLoanDate(std::string loanDate)
{
    this->loanDate = loanDate;
    return *this;
}

std::string LoanEntity::getReturnDate() const
{
    return this->returnDate;
}

LoanEntity& LoanEntity::setReturnDate(std::string returnDate)
{
    this->returnDate = returnDate;
    return *this;
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
    std::cout << "Versão: " << version << "\n\n";
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
