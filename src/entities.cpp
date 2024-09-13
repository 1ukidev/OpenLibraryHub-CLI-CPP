#include <string>
#include <string_view>

#include "entities.h"

// BookEntity
BookEntity::BookEntity(std::string_view title, std::string_view author,
                       std::string_view section, unsigned int pages,
                       unsigned int year, unsigned int stock)
    : id(0), title(title), author(author), section(section),
      pages(pages), year(year), stock(stock) {}

unsigned int BookEntity::getId() const { return id; }
BookEntity& BookEntity::setId(unsigned int id) { this->id = id; return *this; }

std::string BookEntity::getTitle() const { return title; }
BookEntity& BookEntity::setTitle(std::string_view title) { this->title = title; return *this; }

std::string BookEntity::getAuthor() const { return author; }
BookEntity& BookEntity::setAuthor(std::string_view author) { this->author = author; return *this; }

std::string BookEntity::getSection() const { return section; }
BookEntity& BookEntity::setSection(std::string_view section) { this->section = section; return *this; }

unsigned int BookEntity::getPages() const { return pages; }
BookEntity& BookEntity::setPages(unsigned int pages) { this->pages = pages; return *this; }

unsigned int BookEntity::getYear() const { return year; }
BookEntity& BookEntity::setYear(unsigned int year) { this->year = year; return *this; }

unsigned int BookEntity::getStock() const { return stock; }
BookEntity& BookEntity::setStock(unsigned int stock) { this->stock = stock; return *this; }

std::string BookEntity::toString() const {
    return "Id: " + std::to_string(this->id) + '\n' +
           "Título: " + this->title + '\n' +
           "Autor: " + this->author + '\n' +
           "Seção: " + this->section + '\n' +
           "Páginas: " + std::to_string(this->pages) + '\n' +
           "Ano: " + std::to_string(this->year) + '\n' +
           "Estoque: " + std::to_string(this->stock) + '\n';
}

// ClassEntity
ClassEntity::ClassEntity(std::string_view name) : id(0), name(name) {}

unsigned int ClassEntity::getId() const { return id; }
ClassEntity& ClassEntity::setId(unsigned int id) { this->id = id; return *this; }

std::string ClassEntity::getName() const { return name; }
ClassEntity& ClassEntity::setName(std::string_view name) { this->name = name; return *this; }

std::string ClassEntity::toString() const {
    return "Id: " + std::to_string(this->id) + '\n' +
           "Nome: " + this->name + '\n';
}

// StudentEntity
StudentEntity::StudentEntity(std::string_view name, ClassEntity* classEntity)
    : id(0), name(name), classEntity(classEntity) {}

unsigned int StudentEntity::getId() const { return id; }
StudentEntity& StudentEntity::setId(unsigned int id) { this->id = id; return *this; }

std::string StudentEntity::getName() const { return name; }
StudentEntity& StudentEntity::setName(std::string_view name) { this->name = name; return *this; }

ClassEntity* StudentEntity::getClassEntity() const { return classEntity; }
StudentEntity& StudentEntity::setClassEntity(ClassEntity* classEntity) { this->classEntity = classEntity; return *this; }

std::string StudentEntity::toString() const {
    return "Id: " + std::to_string(this->id) + '\n' +
           "Nome: " + this->name + '\n' +
           "Turma: " + this->classEntity->getName() + '\n';
}

// LoanEntity
LoanEntity::LoanEntity(BookEntity* bookEntity, StudentEntity* studentEntity,
                       std::string_view loanDate, std::string_view returnDate)
    : id(0), bookEntity(bookEntity), studentEntity(studentEntity),
      loanDate(loanDate), returnDate(returnDate) {}

unsigned int LoanEntity::getId() const { return id; }
LoanEntity& LoanEntity::setId(unsigned int id) { this->id = id; return *this; }

BookEntity* LoanEntity::getBookEntity() const { return bookEntity; }
LoanEntity& LoanEntity::setBookEntity(BookEntity* bookEntity) { this->bookEntity = bookEntity; return *this; }

StudentEntity* LoanEntity::getStudentEntity() const { return studentEntity; }
LoanEntity& LoanEntity::setStudentEntity(StudentEntity* studentEntity) { this->studentEntity = studentEntity; return *this; }

std::string LoanEntity::getLoanDate() const { return loanDate; }
LoanEntity& LoanEntity::setLoanDate(std::string_view loanDate) { this->loanDate = loanDate; return *this; }

std::string LoanEntity::getReturnDate() const { return returnDate; }
LoanEntity& LoanEntity::setReturnDate(std::string_view returnDate) { this->returnDate = returnDate; return *this; }

std::string LoanEntity::toString() const {
    return "Id: " + std::to_string(this->id) + '\n' +
           "Livro: " + this->bookEntity->getTitle() + '\n' +
           "Aluno: " + this->studentEntity->getName() + '\n' +
           "Data de empréstimo: " + this->loanDate + '\n' +
           "Data de devolução: " + this->returnDate + '\n';
}
