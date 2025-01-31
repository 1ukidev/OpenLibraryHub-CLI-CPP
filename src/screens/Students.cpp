#include "screens/Students.hpp"
#include "Util.hpp"
#include "entities/ClassEntity.hpp"
#include "entities/StudentEntity.hpp"

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

Students& Students::getInstance()
{
    static Students instance;
    return instance;
}

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
    unsigned int option = Util::uscan();
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
            remove();
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
    uint64_t classId = Util::uscan<uint64_t>();

    StudentEntity student(name, ClassEntity(classId));

    if (!dao.save(student)) {
        std::cerr << "Erro ao salvar aluno...\n\n";
    } else {
        Util::clean();
        std::cout << "Aluno salvo com sucesso!\n\n";
    }
}

void Students::update()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<StudentEntity> students = dao.search(where);

    if (students.empty()) {
        std::cerr << "Nenhum aluno encontrado...\n\n";
        return;
    } else if (students.size() > 1) {
        std::cerr << "Mais de um aluno encontrado...\n\n";
        return;
    }

    StudentEntity student = students[0];

    std::cout << "Digite o novo nome do aluno: ";
    std::string name = Util::scan();

    std::cout << "Digite o novo id da turma: ";
    uint64_t classId = Util::uscan<uint64_t>();

    student.setName(name);
    student.setClassEntity(ClassEntity(classId));

    if (!dao.update(student)) {
        std::cerr << "Erro ao atualizar aluno...\n\n";
    } else {
        Util::clean();
        std::cout << "Aluno atualizado com sucesso!\n\n";
    }
}

void Students::remove()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    if (!dao.remove(where)) {
        std::cerr << "Erro ao excluir aluno...\n\n";
    } else {
        Util::clean();
        std::cout << "Aluno excluído com sucesso!\n\n";
    }
}

void Students::search()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<StudentEntity> students = dao.search(where);

    if (students.empty()) {
        std::cerr << "Nenhum aluno encontrado...\n\n";
        return;
    }

    Util::clean();
    for (const auto& student : students) {
        std::cout << student.toString() << '\n';
    }
}

void Students::list()
{
    std::vector<StudentEntity> students = dao.search("1=1");

    if (students.empty()) {
        std::cerr << "Nenhum aluno encontrado...\n\n";
        return;
    }

    for (const auto& student : students)
        std::cout << student.toString() << '\n';
}
