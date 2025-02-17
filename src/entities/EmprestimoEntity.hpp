#pragma once

#include "entities/LivroEntity.hpp"
#include "entities/Entity.hpp"
#include "entities/AlunoEntity.hpp"

#include <chrono>
#include <cstdint>

class EmprestimoEntity final : public Entity
{
public:
    EmprestimoEntity() = default;
    ~EmprestimoEntity() = default;

    EmprestimoEntity(const LivroEntity& livroEntity, const AlunoEntity& alunoEntity,
                     const std::chrono::system_clock::time_point& dataEmpresitmo,
                     const std::chrono::system_clock::time_point& dataDevolucao)
        : livroEntity(livroEntity), alunoEntity(alunoEntity),
          dataEmpresitmo(dataEmpresitmo), dataDevolucao(dataDevolucao) {};

    DECLARE_ENTITY(EmprestimoEntity, emprestimos)

    std::uint64_t id{};
    LivroEntity livroEntity;
    AlunoEntity alunoEntity;
    std::chrono::system_clock::time_point dataEmpresitmo;
    std::chrono::system_clock::time_point dataDevolucao;
};
