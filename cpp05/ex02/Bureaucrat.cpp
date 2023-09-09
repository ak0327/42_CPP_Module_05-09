#include "Bureaucrat.hpp"

/***** constructor, destructor, copy assignment operator ****/
Bureaucrat::Bureaucrat() : name_(INIT_NAME),
						   grade_(GRADE_LOWER_) {}


Bureaucrat::Bureaucrat(const std::string &name,
					   const unsigned int grade) : name_(name),
												   grade_(GRADE_LOWER_) {

	assertGradeRange(grade);
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.getName()),
												grade_(other.getGrade()) {
	assertGradeRange(this->getGrade());
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this == &rhs) {
		return *this;
	}
	setName(rhs.getName());
	setGrade(rhs.getGrade());

	assertGradeRange(this->getGrade());
	return *this;
}


/***** getter, setter ****/
// name
void Bureaucrat::setName(const std::string &name) {
	const_cast<std::string &>(name_) = name;
}
const std::string &Bureaucrat::getName() const { return name_; }

// grade
void Bureaucrat::setGrade(const unsigned grade) { grade_ = grade; }
unsigned int Bureaucrat::getGrade() const { return grade_; }


/***** increment, decrement grade ****/
// Grade (num of grade: upper < lower)
//  upper|-------------- ... --------------|lower
//         << increment       decrement >>
void Bureaucrat::incrementGrade() {
	unsigned int new_grade = getGrade() - 1;

	assertGradeRange(new_grade);
	setGrade(new_grade);
}

void Bureaucrat::decrementGrade() {
	unsigned int new_grade = getGrade() + 1;

	assertGradeRange(new_grade);
	setGrade(new_grade);
}


/***** validate grade range ****/
void Bureaucrat::assertGradeRange(unsigned int grade) {
	if (grade < GRADE_UPPER_) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (GRADE_LOWER_ < grade) {
		throw Bureaucrat::GradeTooLowException();
	}
}


/***** sign form ****/
void Bureaucrat::signForm(AForm &form) const {
	if (form.getSigned()) {
		std::cout << COLOR_RED << "[Info] " <<
		this->getName() << " couldn’t sign " << form.getName() << " because already signed " <<
		COLOR_RESET << std::endl;
	} else {
		std::cout << COLOR_BLUE <<
		this->getName() << " signing by " << form.getName() << "..." <<
		COLOR_RESET << std::endl;
		form.beSigned(*this);
		std::cout << COLOR_BLUE <<
		this->getName() << " signed " << form.getName() <<
		COLOR_RESET << std::endl;
	}
}


/***** execute form ****/
void Bureaucrat::executeForm(const AForm &form) const {
	std::cout << COLOR_CYAN <<
	this->getName() <<  " executing by " << form.getName() << "..." <<
	COLOR_RESET << std::endl;
	form.execute(*this);
	std::cout << COLOR_CYAN <<
	this->getName() <<  " executed " << form.getName() <<
	COLOR_RESET << std::endl;
}


/***** exception ****/
Bureaucrat::GradeTooLowException::GradeTooLowException() :
		std::out_of_range(COLOR_RED "Grade too Low X(" COLOR_RESET) {}

Bureaucrat::GradeTooHighException::GradeTooHighException() :
		std::out_of_range(COLOR_RED "Grade too High :o" COLOR_RESET) {}


// overload of the insertion << operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << COLOR_GREEN <<
	bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() <<
	COLOR_RESET;
	return os;
}
