#pragma once

#include "entities/Entity.hpp"

#include <cstdint>
#include <string>

class LivroEntity : public Entity
{
public:
    LivroEntity() = default;
    ~LivroEntity() = default;

    LivroEntity(const std::string& titulo, const std::string& autor,
               const std::string& secao, uint64_t paginas,
               uint64_t ano, uint64_t estoque)
        : titulo{titulo}, autor{autor}, secao{secao},
          paginas{paginas}, ano{ano}, estoque{estoque} {};
    LivroEntity(uint64_t id) : id{id} {};

    DECLARE_ENTITY(LivroEntity, livros)

    uint64_t id{};
    std::string titulo;
    std::string autor;
    std::string secao;
    uint64_t paginas{};
    uint64_t ano{};
    uint64_t estoque{};
};
