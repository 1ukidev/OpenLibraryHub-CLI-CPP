#pragma once

#include "entities/Entity.hpp"

#include <cstdint>
#include <string>

class TurmaEntity final : public Entity
{
public:
    TurmaEntity() = default;
    ~TurmaEntity() = default;

    TurmaEntity(const std::string& nome) : nome{nome} {};
    TurmaEntity(std::uint64_t id) : id{id} {};

    DECLARE_ENTITY(TurmaEntity, turmas)

    std::uint64_t id{};
    std::string nome;
};
