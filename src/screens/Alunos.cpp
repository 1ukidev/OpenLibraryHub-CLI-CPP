#include "screens/Alunos.hpp"
#include "Util.hpp"
#include "entities/TurmaEntity.hpp"
#include "entities/AlunoEntity.hpp"

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

void Alunos::display()
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

bool Alunos::handleOption()
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

void Alunos::save()
{
    std::cout << "Digite o nome do aluno: ";
    std::string nome = Util::scan();

    std::cout << "Digite o id da turma: ";
    std::uint64_t turmaId = Util::uscan<std::uint64_t>();

    AlunoEntity aluno(nome, TurmaEntity(turmaId));

    if (!dao.save(aluno)) {
        std::cerr << "Erro ao salvar aluno...\n\n";
    } else {
        Util::clean();
        std::cout << "Aluno salvo com sucesso!\n\n";
    }
}

void Alunos::update()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<AlunoEntity> alunos = dao.search(where);

    if (alunos.empty()) {
        std::cerr << "Nenhum aluno encontrado...\n\n";
        return;
    } else if (alunos.size() > 1) {
        std::cerr << "Mais de um aluno encontrado...\n\n";
        return;
    }

    AlunoEntity aluno = alunos[0];

    std::cout << "Digite o novo nome do aluno: ";
    std::string nome = Util::scan();

    std::cout << "Digite o novo id da turma: ";
    std::uint64_t turmaId = Util::uscan<std::uint64_t>();

    aluno.nome = nome;
    aluno.turmaEntity = TurmaEntity(turmaId);

    if (!dao.update(aluno)) {
        std::cerr << "Erro ao atualizar aluno...\n\n";
    } else {
        Util::clean();
        std::cout << "Aluno atualizado com sucesso!\n\n";
    }
}

void Alunos::remove()
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

void Alunos::search()
{
    std::cout << "where: ";
    std::string where = Util::scan();

    std::vector<AlunoEntity> alunos = dao.search(where);

    if (alunos.empty()) {
        std::cerr << "Nenhum aluno encontrado...\n\n";
        return;
    }

    Util::clean();
    for (const auto& student : alunos) {
        std::cout << student.toString() << '\n';
    }
}

void Alunos::list()
{
    std::vector<AlunoEntity> alunos = dao.search("1=1");

    if (alunos.empty()) {
        std::cerr << "Nenhum aluno encontrado...\n\n";
        return;
    }

    for (const auto& student : alunos)
        std::cout << student.toString() << '\n';
}
