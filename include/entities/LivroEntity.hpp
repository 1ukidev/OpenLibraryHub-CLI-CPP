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
               const std::string& secao, std::uint64_t paginas,
               std::uint64_t ano, std::uint64_t estoque)
        : titulo{titulo}, autor{autor}, secao{secao},
          paginas{paginas}, ano{ano}, estoque{estoque} {};
    LivroEntity(std::uint64_t id) : id{id} {};

    DECLARE_ENTITY(LivroEntity, livros)

    std::uint64_t id{};
    std::string titulo;
    std::string autor;
    std::string secao;
    std::uint64_t paginas{};
    std::uint64_t ano{};
    std::uint64_t estoque{};
};
