#include "screens/Students.hpp"
#include "Util.hpp"
#include "dao/StudentDAO.hpp"
#include "entities/ClassEntity.hpp"
#include "entities/StudentEntity.hpp"

#include <iostream>

void Students::display()
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
    unsigned int option = Util::uiscan();
    Util::clean();

    switch (option) {
        // 1 - Cadastrar aluno
        case 1:
            save();
            break;
        // 2 - Atualizar aluno
        case 2:
            update();
            break;
        // 3 - Excluir aluno
        case 3:
            _delete();
            break;
        // 4 - Buscar aluno
        case 4:
            search();
            break;
        // 5 - Listar alunos
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

void Students::save()
{
    std::cout << "Digite o nome do aluno: ";
    std::string name = Util::scan();

    std::cout << "Digite o id da turma: ";
    unsigned int classId = Util::uiscan();

    ClassEntity classEntity;
    classEntity.setId(classId);

    StudentEntity student(name, classEntity);

    StudentDAO dao;

    if (!dao.save(student)) {
        std::cerr << "Erro ao salvar aluno...\n\n";
    } else {
        Util::clean();
        std::cout << "Aluno salvo com sucesso!\n\n";
    }
}

void Students::update()
{
    // TODO
    return;
}

void Students::_delete()
{
    // TODO
    return;
}

void Students::search()
{
    // TOOD
    return;
}

void Students::list()
{
    // TODO
    return;
}
