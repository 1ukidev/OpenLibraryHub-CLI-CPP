#include "screens/Emprestimos.hpp"
#include "Util.hpp"
#include "entities/LivroEntity.hpp"
#include "entities/EmprestimoEntity.hpp"
#include "entities/AlunoEntity.hpp"

#include <cstdint>
#include <iostream>
#include <vector>

Emprestimos& Emprestimos::getInstance()
{
    static Emprestimos instance;
    return instance;
}

void Emprestimos::display()
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

bool Emprestimos::handleOption()
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

void Emprestimos::save()
{
    std::cout << "Digite o id do livro: ";
    uint64_t livroId = Util::uscan<uint64_t>();

    std::cout << "Digite o id do aluno: ";
    uint64_t alunoId = Util::uscan<uint64_t>();

    std::cout << "Digite a data de empréstimo [DD/MM/YYYY]: ";
    auto dataEmpresitmo = Util::tpscan();

    std::cout << "Digite a data de devolução [DD/MM/YYYY]: ";
    auto dataDevolucao = Util::tpscan();

    EmprestimoEntity emprestimo(LivroEntity(livroId), AlunoEntity(alunoId),
                                dataEmpresitmo, dataDevolucao);
    
    if (!dao.save(emprestimo)) {
        std::cerr << "Erro ao salvar empréstimo...\n\n";
    } else {
        Util::clean();
        std::cout << "Empréstimo salvo com sucesso!\n\n";
    }
}

void Emprestimos::update()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<EmprestimoEntity> emprestimos = dao.search(where);

    if (emprestimos.empty()) {
        std::cerr << "Nenhum empréstimo encontrado...\n\n";
        return;
    } else if (emprestimos.size() > 1) {
        std::cerr << "Mais de um empréstimo encontrado...\n\n";
        return;
    }

    EmprestimoEntity emprestimo = emprestimos[0];

    std::cout << "Digite o novo id do livro: ";
    uint64_t livroId = Util::uscan<uint64_t>();

    std::cout << "Digite o novo id do aluno: ";
    uint64_t alunoId = Util::uscan<uint64_t>();

    std::cout << "Digite a nova data de empréstimo [DD/MM/YYYY]: ";
    auto dataEmprestimo = Util::tpscan();

    std::cout << "Digite a nova data de devolução [DD/MM/YYYY]: ";
    auto dataDevolucao = Util::tpscan();

    emprestimo.setLivroEntity(LivroEntity(livroId));
    emprestimo.setAlunoEntity(AlunoEntity(alunoId));
    emprestimo.setDataEmprestimo(dataEmprestimo);
    emprestimo.setDataDevolucao(dataDevolucao);

    if (!dao.update(emprestimo)) {
        std::cerr << "Erro ao atualizar empréstimo...\n\n";
    } else {
        Util::clean();
        std::cout << "Empréstimo atualizado com sucesso!\n\n";
    }
}

void Emprestimos::remove()
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

void Emprestimos::search()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<EmprestimoEntity> emprestimos = dao.search(where);

    if (emprestimos.empty()) {
        std::cerr << "Nenhum empréstimo encontrado...\n\n";
        return;
    }

    Util::clean();
    for (const auto& loan : emprestimos)
        std::cout << loan.toString() << '\n';
}

void Emprestimos::list()
{
    std::vector<EmprestimoEntity> emprestimos = dao.search("1=1");

    if (emprestimos.empty()) {
        std::cerr << "Nenhum empréstimo encontrado...\n\n";
        return;
    }

    for (const auto& loan : emprestimos)
        std::cout << loan.toString() << '\n';
}
