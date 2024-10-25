#include "screens/Loans.hpp"
#include "Util.hpp"

#include <chrono>
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

// TODO
void Loans::save()
{
    std::cout << "Digite o id do livro: ";
    unsigned long bookId = Util::ulscan();

    std::cout << "Digite o id do aluno: ";
    unsigned long studentId = Util::ulscan();

    std::cout << "Digite a data de empréstimo [dd/mm/yyyy]: ";
    std::chrono::system_clock::time_point loanDate = Util::tpscan();

    std::cout << "Digite a data de devolução [dd/mm/yyyy]: ";
    std::chrono::system_clock::time_point returnDate = Util::tpscan();

    Util::clean();
    return;
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
