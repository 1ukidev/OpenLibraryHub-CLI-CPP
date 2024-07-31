#pragma once

#include <string>
#include <optional>

static const std::string VERSION = "0.0.1";

static constexpr int EMPTY = 0;

namespace Util
{
    inline void clean();
    std::string scan();
    unsigned int iscan();
}

class Entity
{
    public:
        virtual unsigned int getId() const = 0;
        virtual Entity& setId(unsigned int id) = 0;
        virtual ~Entity() = default;
};

class BookEntity : public Entity
{
    private:
        unsigned int id;
        std::string title;
        std::string author;
        std::string section;
        unsigned int pages;
        unsigned int year;
        unsigned int stock;
    public:
        BookEntity(std::string_view title, std::string_view author,
                   std::string_view section, unsigned int pages,
                   unsigned int year, unsigned int stock)
            : title(title), author(author), section(section),
              pages(pages), year(year), stock(stock) {}

        BookEntity() = default;

        unsigned int getId() const override { return id; }
        BookEntity& setId(unsigned int id) override { this->id = id; return *this; }

        std::string getTitle() const { return title; }
        BookEntity& setTitle(std::string_view title) { this->title = title; return *this; }

        std::string getAuthor() const { return author; }
        BookEntity& setAuthor(std::string_view author) { this->author = author; return *this; }

        std::string getSection() const { return section; }
        BookEntity& setSection(std::string_view section) { this->section = section; return *this; }

        unsigned int getPages() const { return pages; }
        BookEntity& setPages(unsigned int pages) { this->pages = pages; return *this; }

        unsigned int getYear() const { return year; }
        BookEntity& setYear(unsigned int year) { this->year = year; return *this; }

        unsigned int getStock() const { return stock; }
        BookEntity& setStock(unsigned int stock) { this->stock = stock; return *this; }

        std::string toString() const {
            return "Id: " + std::to_string(this->id) + "\n" +
                   "Título: " + this->title + "\n" +
                   "Autor: " + this->author + "\n" +
                   "Seção: " + this->section + "\n" +
                   "Páginas: " + std::to_string(this->pages) + "\n" +
                   "Ano: " + std::to_string(this->year) + "\n" +
                   "Estoque: " + std::to_string(this->stock) + "\n";
        }
};

namespace BookDAO
{
    BookEntity& save(BookEntity& book);
    std::optional<BookEntity> getBookById(unsigned int id);
}

namespace Books
{
    void welcome();
    bool handleOption();
    void save();
    void search();
}

class ClassEntity : public Entity
{
    private:
        unsigned int id;
        std::string name;
    public:
        ClassEntity(std::string_view name) : name(name) {}

        ClassEntity() = default;

        unsigned int getId() const override { return id; }
        ClassEntity& setId(unsigned int id) override { this->id = id; return *this; }

        std::string getName() const { return name; }
        ClassEntity& setName(std::string_view name) { this->name = name; return *this; }

        std::string toString() const {
            return "Id: " + std::to_string(this->id) + "\n" +
                   "Nome: " + this->name + "\n";
        }
};

namespace Classes
{
    void welcome();
    bool handleOption();
}

class StudentEntity : public Entity
{
    private:
        unsigned int id;
        std::string name;
        ClassEntity* classEntity;
    public:
        StudentEntity(std::string_view name, ClassEntity* classEntity)
            : name(name), classEntity(classEntity) {}

        StudentEntity() = default;

        unsigned int getId() const override { return id; }
        StudentEntity& setId(unsigned int id) override { this->id = id; return *this; }

        std::string getName() const { return name; }
        StudentEntity& setName(std::string_view name) { this->name = name; return *this; }

        ClassEntity* getClassEntity() const { return classEntity; }
        StudentEntity& setClassEntity(ClassEntity* classEntity) { this->classEntity = classEntity; return *this; }

        std::string toString() const {
            return "Id: " + std::to_string(this->id) + "\n" +
                   "Nome: " + this->name + "\n" +
                   "Turma: " + this->classEntity->getName() + "\n";
        }
};

namespace Students
{
    void welcome();
    bool handleOption();
}

class LoanEntity : public Entity
{
    private:
        unsigned int id;
        BookEntity* bookEntity;
        StudentEntity* studentEntity;
        std::string loanDate;
        std::string returnDate;
    public:
        LoanEntity(BookEntity* bookEntity, StudentEntity* studentEntity,
                   std::string_view loanDate, std::string_view returnDate)
            : bookEntity(bookEntity), studentEntity(studentEntity),
              loanDate(loanDate), returnDate(returnDate) {}

        LoanEntity() = default;

        unsigned int getId() const override { return id; }
        LoanEntity& setId(unsigned int id) override { this->id = id; return *this; }

        BookEntity* getBookEntity() const { return bookEntity; }
        LoanEntity& setBookEntity(BookEntity* bookEntity) { this->bookEntity = bookEntity; return *this; }

        StudentEntity* getStudentEntity() const { return studentEntity; }
        LoanEntity& setStudentEntity(StudentEntity* studentEntity) { this->studentEntity = studentEntity; return *this; }

        std::string getLoanDate() const { return loanDate; }
        LoanEntity& setLoanDate(std::string_view loanDate) { this->loanDate = loanDate; return *this; }

        std::string getReturnDate() const { return returnDate; }
        LoanEntity& setReturnDate(std::string_view returnDate) { this->returnDate = returnDate; return *this; }

        std::string toString() const {
            return "Id: " + std::to_string(this->id) + "\n" +
                   "Livro: " + this->bookEntity->getTitle() + "\n" +
                   "Aluno: " + this->studentEntity->getName() + "\n" +
                   "Data de empréstimo: " + this->loanDate + "\n" +
                   "Data de devolução: " + this->returnDate + "\n";
        }
};

namespace Loans
{
    void welcome();
    bool handleOption();
}

namespace Others
{
    void welcome();
    bool handleOption();
    void about();
}

namespace Home
{
    void welcome();
    bool handleOption();
}
