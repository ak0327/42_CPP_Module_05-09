#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

Bureaucrat::Bureaucrat() {} // todo:initialization
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade) : name_(name), grade_(grade) {
	validateGradeRange(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) {
	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	if (this != &bureaucrat) {
		setName(bureaucrat.getName());
		setGrade(bureaucrat.getGrade());
	}
	return *this;
}

// getter, setter
void Bureaucrat::setName(const std::string &name) { const_cast<std::string &>(name_) = name; }
const std::string &Bureaucrat::getName() const { return name_; }

void Bureaucrat::setGrade(const unsigned grade) { grade_ = grade; }
unsigned int Bureaucrat::getGrade() const { return grade_; }

// two member functions to increment or decrement the bureaucrat grade.
void Bureaucrat::incrementGrade() {
	setGrade(getGrade() - 1);
	validateGradeRange(getGrade());
}

void Bureaucrat::decrementGrade() {
	setGrade(getGrade() + 1);
	validateGradeRange(getGrade());
}

void Bureaucrat::validateGradeRange(const unsigned int grade) {
	if (1 <= grade && grade <= 150) {
		return ;
	}
	if (grade == 0) {
		throw std::invalid_argument("Bureaucrat::GradeTooHighException");
//		return ;
	}
	throw std::invalid_argument("Bureaucrat::GradeTooLowException");
}

// overload of the insertion << operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << COLOR_GREEN << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << COLOR_RESET;
	return os;
}