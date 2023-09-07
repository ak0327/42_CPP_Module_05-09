#pragma once

# include <iostream>
# include <string>

# define GRADE_UPPER	1
# define GRADE_LOWER	150
# define INIT_GRADE		150
# define INIT_NAME		"InitName"

class Bureaucrat {
 public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat(const std::string &name, const unsigned int grade);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &lhs);

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

 private:
	std::string		name_;
	unsigned int	grade_;
	unsigned int	upper_grade_;
	unsigned int	lower_grade_;

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
