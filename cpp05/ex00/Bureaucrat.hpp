#pragma once

#include <iostream>
#include <string>

#define UPPER	1
#define LOWER	150

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

	void validateGradeRange(const unsigned int grade);


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

// overload of the insertion << operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);