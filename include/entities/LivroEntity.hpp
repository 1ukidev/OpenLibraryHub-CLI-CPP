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
    ~LivroEntity() = default;

    LivroEntity(const std::string& titulo, const std::string& autor,
               const std::string& secao, uint64_t paginas,
               uint64_t ano, uint64_t estoque)
        : titulo_{titulo}, autor_{autor}, secao_{secao},
          paginas_{paginas}, ano_{ano}, estoque_{estoque} {};
    LivroEntity(uint64_t id) : id_{id} {};

    std::string getClassName() const override { return "LivroEntity"; }
    std::string getTable() const override { return "livros"; }

    const std::unordered_map<std::string, std::string> getColumns() const override;

    void fromRowSet(const boost::mysql::row_view& row) override;

    uint64_t getId() const override { return id_; }
    void setId(uint64_t id) override { this->id_ = id; }

    std::string getTitulo() const { return titulo_; }
    void setTitulo(const std::string& titulo) { this->titulo_ = titulo; }

    std::string getAutor() const { return autor_; }
    void setAutor(const std::string& autor) { this->autor_ = autor; }

    std::string getSecao() const { return secao_; }
    void setSecao(const std::string& secao) { this->secao_ = secao; }

    uint64_t getPaginas() const { return paginas_; }
    void setPaginas(uint64_t paginas) { this->paginas_ = paginas; }

    uint64_t getAno() const { return ano_; }
    void setAno(uint64_t ano) { this->ano_ = ano; }

    uint64_t getEstoque() const { return estoque_; }
    void setEstoque(uint64_t estoque) { this->estoque_ = estoque; }

    std::string toString() const override;

private:
    uint64_t id_{};
    std::string titulo_;
    std::string autor_;
    std::string secao_;
    uint64_t paginas_{};
    uint64_t ano_{};
    uint64_t estoque_{};
};
