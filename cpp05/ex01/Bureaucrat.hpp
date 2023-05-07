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


	/***** setter ****/
	void setGrade(const unsigned int grade);
	// upper, lower grade
	void setUpperGrade(const unsigned int upper);
	void setLowerGrade(const unsigned int lower);

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


	/***** increment, decrement grade ****/
	void incrementGrade();
	void decrementGrade();


	/***** sign form ****/
	void signForm(Form &form);


	/***** validate grade range ****/
	// use in validation of Form grade
	static void validateGradeRange(const unsigned int grade);


	/***** exception ****/
	class GradeTooLowException : public std::out_of_range {
	public:
		GradeTooLowException();
	};

	class GradeTooHighException : public std::out_of_range {
	public:
		GradeTooHighException();
	};
};

/***** overload of the insertion << operator ****/
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

