#include "screens/Loans.hpp"
#include "Util.hpp"
#include "dao/LoanDAO.hpp"
#include "entities/BookEntity.hpp"
#include "entities/LoanEntity.hpp"
#include "entities/StudentEntity.hpp"

#include <iostream>

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
    unsigned int option = Util::uiscan();
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
            _delete();
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
            break;
        default:
            std::cerr << "Opção inválida...\n\n";
            break;
    }

    return true;
}

void Loans::save()
{
    std::cout << "Digite o id do livro: ";
    unsigned long bookId = Util::ulscan();

    std::cout << "Digite o id do aluno: ";
    unsigned long studentId = Util::ulscan();

    std::cout << "Digite a data de empréstimo [dd/mm/yyyy]: ";
    auto loanDate = Util::tpscan();

    std::cout << "Digite a data de devolução [dd/mm/yyyy]: ";
    auto returnDate = Util::tpscan();

    LoanEntity loan(BookEntity(bookId), StudentEntity(studentId), loanDate, returnDate);

    LoanDAO dao;
    
    if (!dao.save(loan)) {
        std::cerr << "Erro ao salvar empréstimo...\n\n";
    } else {
        Util::clean();
        std::cout << "Empréstimo salvo com sucesso!\n\n";
    }
}

void Loans::update()
{
    // TODO
    return;
}

void Loans::_delete()
{
    // TODO
    return;
}

void Loans::search()
{
    // TODO
    return;
}

void Loans::list()
{
    // TODO
    return;
}
