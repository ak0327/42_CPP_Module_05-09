#pragma once

#include <iostream>
#include <string>

#include "Form.hpp"

#define GRADE_UPPER	1
#define GRADE_LOWER	150

class Form;

class Bureaucrat {
private:
	const std::string	name_;
	unsigned int		grade_;
	const unsigned int	upper_grade_;
	const unsigned int	lower_grade_;

public:
	/***** constructor, destructor, copy assignment operator ****/
	Bureaucrat();
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat(const std::string &name, const unsigned int grade);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &bureaucrat);


	/***** getter, setter ****/
	// name
	const std::string &getName() const ;
	void setName(const std::string &name);

	// grade
	unsigned int getGrade() const ;
	void setGrade(const unsigned int grade);

	// upper, lower grade
	void setUpperGrade(const unsigned int upper);
	void setLowerGrade(const unsigned int lower);


	/***** increment, decrement grade ****/
	void incrementGrade();
	void decrementGrade();


	/***** validate grade range ****/
	static void validateGradeRange(const unsigned int grade);


	/***** sign form ****/
	void signForm(Form &form);


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

/***** overload of the insertion << operator ****/
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

