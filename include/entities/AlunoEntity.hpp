#pragma once

#include "entities/TurmaEntity.hpp"
#include "entities/Entity.hpp"

#include <cstdint>
#include <string>

class AlunoEntity : public Entity
{
public:
    AlunoEntity() = default;
    ~AlunoEntity() = default;

    AlunoEntity(const std::string& nome, const TurmaEntity& turmaEntity)
        : nome{nome}, turmaEntity{turmaEntity} {};
    AlunoEntity(std::uint64_t id) : id{id} {};

    DECLARE_ENTITY(AlunoEntity, alunos)

    std::uint64_t id{};
    std::string nome;
    TurmaEntity turmaEntity;
};
