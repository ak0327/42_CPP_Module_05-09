#pragma once

# include <iostream>
# include <string>

# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET	"\x1b[0m"

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

	// two member functions to increment or decrement the bureaucrat grade.
	void incrementGrade();
	void decrementGrade();

	/***** exception ****/
	class GradeTooLowException : public std::out_of_range {
	 public:
		GradeTooLowException();
	};

	class GradeTooHighException : public std::out_of_range {
	 public:
		GradeTooHighException();
	};

 private:
	const std::string	name_;
	unsigned int		grade_;
	static const int	GRADE_UPPER_ = 1;
	static const int	GRADE_LOWER_ = 150;

	void assertGradeRange(const unsigned int grade);
	void setGrade(const unsigned int grade);
};

// overload of the insertion << operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
