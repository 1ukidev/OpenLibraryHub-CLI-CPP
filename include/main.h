#pragma once

#include <string>
#include <optional>

static const std::string version = "0.0.1";

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
        unsigned int id = EMPTY;
        std::string title;
        std::string author;
        std::string section;
        unsigned int pages = EMPTY;
        unsigned int year = EMPTY;
        unsigned int stock = EMPTY;
    public:
        BookEntity(std::string title, std::string author,
                   std::string section, unsigned int pages,
                   unsigned int year, unsigned int stock) {
            this->title = title;
            this->author = author;
            this->section = section;
            this->pages = pages;
            this->year = year;
            this->stock = stock;
        }

        BookEntity() {}

        unsigned int getId() const;
        BookEntity& setId(unsigned int id);

        std::string getTitle() const;
        BookEntity& setTitle(std::string title);

        std::string getAuthor() const;
        BookEntity& setAuthor(std::string author);

        std::string getSection() const;
        BookEntity& setSection(std::string section);

        unsigned int getPages() const;
        BookEntity& setPages(unsigned int pages);

        unsigned int getYear() const;
        BookEntity& setYear(unsigned int year);

        unsigned int getStock() const;
        BookEntity& setStock(unsigned int stock);

        std::string toString() const;
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
        unsigned int id = EMPTY;
        std::string name;
    public:
        ClassEntity(std::string name) {
            this->name = name;
        }

        ClassEntity() {}

        unsigned int getId() const;
        ClassEntity& setId(unsigned int id);

        std::string getName() const;
        ClassEntity& setName(std::string name);
};

namespace Classes
{
    void welcome();
    bool handleOption();
}

class StudentEntity : public Entity
{
    private:
        unsigned int id = EMPTY;
        std::string name;
        ClassEntity* classEntity;
    public:
        StudentEntity(std::string name, ClassEntity* classEntity) {
            this->name = name;
            this->classEntity = classEntity;
        }

        StudentEntity() {}

        unsigned int getId() const;
        StudentEntity& setId(unsigned int id);

        std::string getName() const;
        StudentEntity& setName(std::string name);

        ClassEntity* getClassEntity() const;
        StudentEntity& setClassEntity(ClassEntity* classEntity);
};

namespace Students
{
    void welcome();
    bool handleOption();
}

class LoanEntity : public Entity
{
    private:
        unsigned int id = EMPTY;
        BookEntity* bookEntity;
        StudentEntity* studentEntity;
        std::string loanDate;
        std::string returnDate;
    public:
        LoanEntity(BookEntity* bookEntity, StudentEntity* studentEntity,
                   std::string loanDate, std::string returnDate) {
            this->studentEntity = studentEntity;
            this->bookEntity = bookEntity;
            this->loanDate = loanDate;
            this->returnDate = returnDate;
        }

        LoanEntity() {}

        unsigned int getId() const;
        LoanEntity& setId(unsigned int id);

        BookEntity* getBookEntity() const;
        LoanEntity& setBookEntity(BookEntity* bookEntity);

        StudentEntity* getStudentEntity() const;
        LoanEntity& setStudentEntity(StudentEntity* studentEntity);

        std::string getLoanDate() const;
        LoanEntity& setLoanDate(std::string loanDate);

        std::string getReturnDate() const;
        LoanEntity& setReturnDate(std::string returnDate);
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
