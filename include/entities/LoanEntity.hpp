#pragma once

#include "Util.hpp"
#include "entities/BookEntity.hpp"
#include "entities/Entity.hpp"
#include "entities/StudentEntity.hpp"

#include <boost/mysql/row_view.hpp>
#include <chrono>
#include <cstdint>
#include <string>
#include <unordered_map>

class LoanEntity : public Entity
{
public:
    LoanEntity() = default;
    ~LoanEntity() override = default;

    LoanEntity(const BookEntity& bookEntity, const StudentEntity& studentEntity,
               const std::chrono::system_clock::time_point& loanDate,
               const std::chrono::system_clock::time_point& returnDate)
        : bookEntity(bookEntity), studentEntity(studentEntity), loanDate(loanDate), returnDate(returnDate) {};

    std::string getClassName() const override { return "LoanEntity"; }
    std::string getTable() const override { return "emprestimos"; }

    const std::unordered_map<std::string, std::string> getColumns() const override {
        return {
            {"livro", std::to_string(bookEntity.getId())},
            {"aluno", std::to_string(studentEntity.getId())},
            {"data_emprestimo", Util::timePointToString(loanDate, "{:%Y-%m-%d}")},
            {"data_devolucao", Util::timePointToString(returnDate, "{:%Y-%m-%d}")}
        };
    }

    void fromRowSet(const boost::mysql::row_view& row) override {
        if (!row.empty()) {
            id = row[0].get_uint64();
            bookEntity.setId(row[1].get_uint64());
            studentEntity.setId(row[2].get_uint64());
            loanDate = row[3].get_date().get_time_point();
            returnDate = row[4].get_date().get_time_point();
        }
    }

    uint64_t getId() const override { return id; }
    void setId(uint64_t id) override { this->id = id; }

    const BookEntity& getBookEntity() const { return bookEntity; }
    void setBookEntity(const BookEntity& bookEntity) { this->bookEntity = bookEntity; }

    const StudentEntity& getStudentEntity() const { return studentEntity; }
    void setStudentEntity(const StudentEntity& studentEntity) { this->studentEntity = studentEntity; }

    const std::chrono::system_clock::time_point& getLoanDate() const { return loanDate; }
    void setLoanDate(const std::chrono::system_clock::time_point& loanDate) { this->loanDate = loanDate; }

    const std::chrono::system_clock::time_point& getReturnDate() const { return returnDate; }
    void setReturnDate(const std::chrono::system_clock::time_point& returnDate) { this->returnDate = returnDate; }

    std::string toString() const override;

private:
    uint64_t id{};
    BookEntity bookEntity;
    StudentEntity studentEntity;
    std::chrono::system_clock::time_point loanDate;
    std::chrono::system_clock::time_point returnDate;
};
