#pragma once

#include <string>
#include <string_view>

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
				   unsigned int year, unsigned int stock);
		BookEntity() = default;

		unsigned int getId() const override;
		BookEntity& setId(unsigned int id) override;

		std::string getTitle() const;
		BookEntity& setTitle(std::string_view title);

		std::string getAuthor() const;
		BookEntity& setAuthor(std::string_view author);

		std::string getSection() const;
		BookEntity& setSection(std::string_view section);

		unsigned int getPages() const;
		BookEntity& setPages(unsigned int pages);

		unsigned int getYear() const;
		BookEntity& setYear(unsigned int year);

		unsigned int getStock() const;
		BookEntity& setStock(unsigned int stock);

		std::string toString() const;
};

class ClassEntity : public Entity
{
	private:
		unsigned int id;
		std::string name;

	public:
		ClassEntity(std::string_view name);
		ClassEntity() = default;

		unsigned int getId() const override;
		ClassEntity& setId(unsigned int id) override;

		std::string getName() const;
		ClassEntity& setName(std::string_view name);

		std::string toString() const;
};

class StudentEntity : public Entity
{
	private:
		unsigned int id;
		std::string name;
		ClassEntity* classEntity;

	public:
		StudentEntity(std::string_view name, ClassEntity* classEntity);
		StudentEntity() = default;

		unsigned int getId() const override;
		StudentEntity& setId(unsigned int id) override;

		std::string getName() const;
		StudentEntity& setName(std::string_view name);

		ClassEntity* getClassEntity() const;
		StudentEntity& setClassEntity(ClassEntity* classEntity);

		std::string toString() const;
};

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
				   std::string_view loanDate, std::string_view returnDate);
		LoanEntity() = default;

		unsigned int getId() const override;
		LoanEntity& setId(unsigned int id) override;

		BookEntity* getBookEntity() const;
		LoanEntity& setBookEntity(BookEntity* bookEntity);

		StudentEntity* getStudentEntity() const;
		LoanEntity& setStudentEntity(StudentEntity* studentEntity);

		std::string getLoanDate() const;
		LoanEntity& setLoanDate(std::string_view loanDate);

		std::string getReturnDate() const;
		LoanEntity& setReturnDate(std::string_view returnDate);

		std::string toString() const;
};
