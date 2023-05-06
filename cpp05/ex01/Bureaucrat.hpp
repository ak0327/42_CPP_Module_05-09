#pragma once

#include <iostream>
#include <string>

class Bureaucrat {
private:
	const std::string name_;
	unsigned int grade_;

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

	// two member functions to increment or decrement the bureaucrat grade.
	void incrementGrade();
	void decrementGrade();

	void validateGradeRange(const unsigned int grade);

};

// overload of the insertion << operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);