#include "screens/Classes.hpp"
#include "Util.hpp"
#include "dao/ClassDAO.hpp"
#include "entities/ClassEntity.hpp"

#include <iostream>
#include <string>
#include <vector>

void Classes::display()
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
            break;
        default:
            std::cerr << "Opção inválida...\n\n";
            break;
    }

    return true;
}

void Classes::save()
{
    std::cout << "Digite o nome da turma: ";
    std::string name = Util::scan();

    ClassEntity classEntity(name);

    ClassDAO dao;

    if (!dao.save(classEntity)) {
        std::cerr << "Erro ao cadastrar turma...\n\n";
    } else {
        Util::clean();
        std::cout << "Turma cadastrada com sucesso!\n\n";
    }
}

void Classes::update()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    ClassDAO dao;
    std::vector<ClassEntity> classes = dao.search(where);

    if (classes.empty()) {
        std::cout << "Nenhuma turma encontrada...\n\n";
        return;
    } else if (classes.size() > 1) {
        std::cerr << "Mais de uma turma encontrada...\n\n";
        return;
    }

    ClassEntity classEntity = classes[0];

    std::cout << "Digite o novo nome da turma: ";
    std::string name = Util::scan();

    classEntity.name = name;

    if (!dao.update(classEntity)) {
        std::cerr << "Erro ao atualizar turma...\n\n";
    } else {
        Util::clean();
        std::cout << "Turma atualizada com sucesso!\n\n";
    }
}

void Classes::remove()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    ClassDAO dao;

    if (!dao.remove(where)) {
        std::cerr << "Erro ao excluir turma...\n\n";
    } else {
        Util::clean();
        std::cout << "Turma excluída com sucesso!\n\n";
    }
}

void Classes::search()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    ClassDAO dao;
    std::vector<ClassEntity> classes = dao.search(where);

    if (classes.empty()) {
        std::cout << "Nenhuma turma encontrada...\n\n";
        return;
    }

    Util::clean();
    for (const auto& classEntity : classes)
        std::cout << classEntity.toString() << '\n';
}

void Classes::list()
{
    ClassDAO dao;
    std::vector<ClassEntity> classes = dao.search("1=1");

    if (classes.empty()) {
        std::cout << "Nenhuma turma encontrada...\n\n";
        return;
    }

    for (const auto& classEntity : classes)
        std::cout << classEntity.toString() << '\n';
}
