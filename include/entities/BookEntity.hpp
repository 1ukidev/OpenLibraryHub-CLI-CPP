#pragma once

#include "entities/Entity.hpp"

#include <boost/mysql/row_view.hpp>
#include <cstdint>
#include <string>
#include <unordered_map>

class BookEntity : public Entity
{
public:
    BookEntity() = default;
    ~BookEntity() override = default;

    BookEntity(const std::string& title, const std::string& author,
               const std::string& section, uint64_t pages,
               uint64_t year, uint64_t stock)
        : title{title}, author{author}, section{section},
          pages{pages}, year{year}, stock{stock} {};
    BookEntity(uint64_t id) : id{id} {};

    std::string getClassName() const override { return "BookEntity"; }
    std::string getTable() const override { return "livros"; }

    const std::unordered_map<std::string, std::string> getColumns() const override {
        return {
            {"titulo", title},
            {"autor", author},
            {"secao", section},
            {"paginas", std::to_string(pages)},
            {"ano", std::to_string(year)},
            {"estoque", std::to_string(stock)}
        };
    }

    void fromRowSet(const boost::mysql::row_view& row) override {
        if (!row.empty()) {
            id = row[0].get_uint64();
            title = row[1].get_string();
            author = row[2].get_string();
            section = row[3].get_string();
            pages = row[4].get_uint64();
            year = row[5].get_uint64();
            stock = row[6].get_uint64();
        }
    }

    uint64_t getId() const override { return id; }
    void setId(uint64_t id) override { this->id = id; }

    std::string getTitle() const { return title; }
    void setTitle(const std::string& title) { this->title = title; }

    std::string getAuthor() const { return author; }
    void setAuthor(const std::string& author) { this->author = author; }

    std::string getSection() const { return section; }
    void setSection(const std::string& section) { this->section = section; }

    uint64_t getPages() const { return pages; }
    void setPages(uint64_t pages) { this->pages = pages; }

    uint64_t getYear() const { return year; }
    void setYear(uint64_t year) { this->year = year; }

    uint64_t getStock() const { return stock; }
    void setStock(uint64_t stock) { this->stock = stock; }

    std::string toString() const override;

private:
    uint64_t id{};
    std::string title;
    std::string author;
    std::string section;
    uint64_t pages{};
    uint64_t year{};
    uint64_t stock{};
};
