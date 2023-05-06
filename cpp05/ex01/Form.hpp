#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

class Bureaucrat;

class Form {
private:
	const std::string	name_;
	bool				signed_;
	const unsigned int	upper_grade_;
	const unsigned int	lower_grade_;

public:
	/***** constructor, destructor, copy assignment operator ****/
	Form();
	Form(const Form &form);
	Form(const std::string &name,
		 const bool signed_,
		 const unsigned int upper_grade,
		 const unsigned int lower_grade);
	~Form();
	Form &operator=(const Form &form);


	/***** getter, setter ****/
	// name
	const std::string &getName() const;
	void setName(const std::string &name);

	// signed
	bool getSigned() const;
	void setSigned(const bool is_signed);

	// upper_grade
	unsigned int getUpperGrade() const;
	void setUpperGrade(const unsigned int upper_grade);

	// lower_grade
	unsigned int getLowerGrade() const;
	void setLowerGrade(const unsigned int lower_grade);


	/***** sign by bureaucrat ****/
	void beSigned(Bureaucrat &bureaucrat);

	/***** validate ****/
	void validateBureaucratSignableToForm(const Bureaucrat &bureaucrat);
	void validateGradeRange(const unsigned int upper, const unsigned int lower);


	/***** exception ****/
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

};

/***** overload of the operator ****/
std::ostream &operator<<(std::ostream &os, const Form &form);
