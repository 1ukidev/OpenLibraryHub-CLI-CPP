#pragma once

#include "entities/Entity.hpp"

#include <cstdint>
#include <string>

class TurmaEntity : public Entity
{
public:
    TurmaEntity() = default;
    ~TurmaEntity() = default;

    TurmaEntity(const std::string& nome) : nome{nome} {};
    TurmaEntity(uint64_t id) : id{id} {};

    DECLARE_ENTITY(TurmaEntity, turmas)

    uint64_t id{};
    std::string nome;
};
