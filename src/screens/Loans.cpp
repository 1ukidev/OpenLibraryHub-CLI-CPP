#include "screens/Loans.hpp"
#include "Util.hpp"
#include "entities/BookEntity.hpp"
#include "entities/LoanEntity.hpp"
#include "entities/StudentEntity.hpp"

#include <cstdint>
#include <iostream>
#include <vector>

Loans& Loans::getInstance()
{
    static Loans instance;
    return instance;
}

void Loans::display()
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
    unsigned int option = Util::uscan();
    Util::clean();

    switch (option) {
        // 1 - Cadastrar empréstimo
        case 1:
            save();
            break;
        // 2 - Atualizar empréstimo
        case 2:
            update();
            break;
        // 3 - Excluir empréstimo
        case 3:
            remove();
            break;
        // 4 - Buscar empréstimo
        case 4:
            search();
            break;
        // 5 - Listar empréstimos
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

void Loans::save()
{
    std::cout << "Digite o id do livro: ";
    uint64_t bookId = Util::uscan<uint64_t>();

    std::cout << "Digite o id do aluno: ";
    uint64_t studentId = Util::uscan<uint64_t>();

    std::cout << "Digite a data de empréstimo [DD/MM/YYYY]: ";
    auto loanDate = Util::tpscan();

    std::cout << "Digite a data de devolução [DD/MM/YYYY]: ";
    auto returnDate = Util::tpscan();

    LoanEntity loan(BookEntity(bookId), StudentEntity(studentId), loanDate, returnDate);
    
    if (!dao.save(loan)) {
        std::cerr << "Erro ao salvar empréstimo...\n\n";
    } else {
        Util::clean();
        std::cout << "Empréstimo salvo com sucesso!\n\n";
    }
}

void Loans::update()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<LoanEntity> loans = dao.search(where);

    if (loans.empty()) {
        std::cerr << "Nenhum empréstimo encontrado...\n\n";
        return;
    } else if (loans.size() > 1) {
        std::cerr << "Mais de um empréstimo encontrado...\n\n";
        return;
    }

    LoanEntity loan = loans[0];

    std::cout << "Digite o novo id do livro: ";
    uint64_t bookId = Util::uscan<uint64_t>();

    std::cout << "Digite o novo id do aluno: ";
    uint64_t studentId = Util::uscan<uint64_t>();

    std::cout << "Digite a nova data de empréstimo [DD/MM/YYYY]: ";
    auto loanDate = Util::tpscan();

    std::cout << "Digite a nova data de devolução [DD/MM/YYYY]: ";
    auto returnDate = Util::tpscan();

    loan.setBookEntity(BookEntity(bookId));
    loan.setStudentEntity(StudentEntity(studentId));
    loan.setLoanDate(loanDate);
    loan.setReturnDate(returnDate);

    if (!dao.update(loan)) {
        std::cerr << "Erro ao atualizar empréstimo...\n\n";
    } else {
        Util::clean();
        std::cout << "Empréstimo atualizado com sucesso!\n\n";
    }
}

void Loans::remove()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    if (!dao.remove(where)) {
        std::cerr << "Erro ao remover empréstimo...\n\n";
    } else {
        Util::clean();
        std::cout << "Empréstimo removido com sucesso!\n\n";
    }
}

void Loans::search()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<LoanEntity> loans = dao.search(where);

    if (loans.empty()) {
        std::cerr << "Nenhum empréstimo encontrado...\n\n";
        return;
    }

    Util::clean();
    for (const auto& loan : loans)
        std::cout << loan.toString() << '\n';
}

void Loans::list()
{
    std::vector<LoanEntity> loans = dao.search("1=1");

    if (loans.empty()) {
        std::cerr << "Nenhum empréstimo encontrado...\n\n";
        return;
    }

    for (const auto& loan : loans)
        std::cout << loan.toString() << '\n';
}
