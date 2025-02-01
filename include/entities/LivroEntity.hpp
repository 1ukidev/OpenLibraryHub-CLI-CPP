#pragma once

#include "entities/Entity.hpp"

#include <boost/mysql/row_view.hpp>
#include <cstdint>
#include <string>
#include <unordered_map>

class LivroEntity : public Entity
{
public:
    LivroEntity() = default;
    ~LivroEntity() override = default;

    LivroEntity(const std::string& titulo, const std::string& autor,
               const std::string& secao, uint64_t paginas,
               uint64_t ano, uint64_t estoque)
        : titulo{titulo}, autor{autor}, secao{secao},
          paginas{paginas}, ano{ano}, estoque{estoque} {};
    LivroEntity(uint64_t id) : id{id} {};

    std::string getClassName() const override { return "LivroEntity"; }
    std::string getTable() const override { return "livros"; }

    const std::unordered_map<std::string, std::string> getColumns() const override {
        return {
            {"titulo", titulo},
            {"autor", autor},
            {"secao", secao},
            {"paginas", std::to_string(paginas)},
            {"ano", std::to_string(ano)},
            {"estoque", std::to_string(estoque)}
        };
    }

    void fromRowSet(const boost::mysql::row_view& row) override {
        if (!row.empty()) {
            id = row[0].get_uint64();
            titulo = row[1].get_string();
            autor = row[2].get_string();
            secao = row[3].get_string();
            paginas = row[4].get_uint64();
            ano = row[5].get_uint64();
            estoque = row[6].get_uint64();
        }
    }

    uint64_t getId() const override { return id; }
    void setId(uint64_t id) override { this->id = id; }

    std::string getTitulo() const { return titulo; }
    void setTitulo(const std::string& titulo) { this->titulo = titulo; }

    std::string getAutor() const { return autor; }
    void setAutor(const std::string& autor) { this->autor = autor; }

    std::string getSecao() const { return secao; }
    void setSecao(const std::string& secao) { this->secao = secao; }

    uint64_t getPaginas() const { return paginas; }
    void setPaginas(uint64_t paginas) { this->paginas = paginas; }

    uint64_t getAno() const { return ano; }
    void setAno(uint64_t ano) { this->ano = ano; }

    uint64_t getEstoque() const { return estoque; }
    void setEstoque(uint64_t estoque) { this->estoque = estoque; }

    std::string toString() const override;

private:
    uint64_t id{};
    std::string titulo;
    std::string autor;
    std::string secao;
    uint64_t paginas{};
    uint64_t ano{};
    uint64_t estoque{};
};
