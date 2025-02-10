#include "screens/Turmas.hpp"
#include "Util.hpp"
#include "entities/TurmaEntity.hpp"

#include <iostream>
#include <string>
#include <vector>

void Turmas::display()
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

bool Turmas::handleOption()
{
    unsigned int option = Util::uscan();
    Util::clean();

    switch (option) {
        // 1 - Cadastrar turma
        case 1:
            save();
            break;
        // 2 - Atualizar turma
        case 2:
            update();
            break;
        // 3 - Excluir turma
        case 3:
            remove();
            break;
        // 4 - Buscar turma
        case 4:
            search();
            break;
        // 5 - Listar turmas
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

void Turmas::save()
{
    std::cout << "Digite o nome da turma: ";
    std::string nome = Util::scan();

    TurmaEntity turma(nome);

    if (!dao.save(turma)) {
        std::cerr << "Erro ao cadastrar turma...\n\n";
    } else {
        Util::clean();
        std::cout << "Turma cadastrada com sucesso!\n\n";
    }
}

void Turmas::update()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<TurmaEntity> turmas = dao.search(where);

    if (turmas.empty()) {
        std::cout << "Nenhuma turma encontrada...\n\n";
        return;
    } else if (turmas.size() > 1) {
        std::cerr << "Mais de uma turma encontrada...\n\n";
        return;
    }

    TurmaEntity turma = turmas[0];

    std::cout << "Digite o novo nome da turma: ";
    std::string nome = Util::scan();

    turma.nome = nome;

    if (!dao.update(turma)) {
        std::cerr << "Erro ao atualizar turma...\n\n";
    } else {
        Util::clean();
        std::cout << "Turma atualizada com sucesso!\n\n";
    }
}

void Turmas::remove()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    if (!dao.remove(where)) {
        std::cerr << "Erro ao excluir turma...\n\n";
    } else {
        Util::clean();
        std::cout << "Turma excluída com sucesso!\n\n";
    }
}

void Turmas::search()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<TurmaEntity> turmas = dao.search(where);

    if (turmas.empty()) {
        std::cout << "Nenhuma turma encontrada...\n\n";
        return;
    }

    Util::clean();
    for (const auto& TurmaEntity : turmas)
        std::cout << TurmaEntity.toString() << '\n';
}

void Turmas::list()
{
    std::vector<TurmaEntity> turmas = dao.search("1=1");

    if (turmas.empty()) {
        std::cout << "Nenhuma turma encontrada...\n\n";
        return;
    }

    for (const auto& TurmaEntity : turmas)
        std::cout << TurmaEntity.toString() << '\n';
}
