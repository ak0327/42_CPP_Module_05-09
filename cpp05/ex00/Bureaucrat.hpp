#pragma once

#include <iostream>
#include <string>

#define GRADE_UPPER	1
#define GRADE_LOWER	150
#define INIT_NAME	"InitName"
#define INIT_GRADE	150

class Bureaucrat {
private:
	const std::string	name_;
	unsigned int		grade_;
	const unsigned int	upper_grade_;
	const unsigned int	lower_grade_;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat(const std::string &name, const unsigned int grade);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &bureaucrat);

	// getter, setter
	const std::string &getName() const ;
	void setName(const std::string &name);
	unsigned int getGrade() const ;
	void setGrade(const unsigned int grade);
	void setUpperGrade(const unsigned int upper);
	void setLowerGrade(const unsigned int lower);

	// two member functions to increment or decrement the bureaucrat grade.
	void incrementGrade();
	void decrementGrade();

	void assertGradeRange(const unsigned int grade);


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

// overload of the insertion << operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);