#include "Bureaucrat.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

/***** constructor, destructor, copy assignment operator ****/
Bureaucrat::Bureaucrat() : name_(INIT_NAME),
						   grade_(INIT_GRADE),
						   upper_grade_(GRADE_UPPER),
						   lower_grade_(GRADE_LOWER) {}


Bureaucrat::Bureaucrat(const std::string &name,
					   const unsigned int grade) : name_(name),
												   grade_(grade),
												   upper_grade_(GRADE_UPPER),
												   lower_grade_(GRADE_LOWER) {
	assertGradeRange(this->getGrade());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.getName()),
												grade_(other.getGrade()),
												upper_grade_(GRADE_UPPER),
												lower_grade_(GRADE_LOWER) {
	assertGradeRange(this->getGrade());
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &lhs) {
	if (this == &lhs) {
		return *this;
	}
	setName(lhs.getName());
	setGrade(lhs.getGrade());
	setUpperGrade(GRADE_UPPER);
	setLowerGrade(GRADE_LOWER);
	assertGradeRange(grade_);
	return *this;
}


/***** getter, setter ****/
// name
void Bureaucrat::setName(const std::string &name) { const_cast<std::string &>(name_) = name; }
const std::string &Bureaucrat::getName() const { return name_; }

// grade
void Bureaucrat::setGrade(const unsigned grade) { grade_ = grade; }
unsigned int Bureaucrat::getGrade() const { return grade_; }

// upper
void Bureaucrat::setUpperGrade(unsigned int upper) {
	upper_grade_ = upper;
}

// lower
void Bureaucrat::setLowerGrade(unsigned int lower) {
	lower_grade_ = lower;
}


/***** increment, decrement grade ****/
// Grade (num of grade: upper < lower)
//  upper|-------------- ... --------------|lower
//         << increment       decrement >>
void Bureaucrat::incrementGrade() {
	grade_--;
	assertGradeRange(grade_);
}

void Bureaucrat::decrementGrade() {
	grade_++;
	assertGradeRange(grade_);
}


/***** validate grade range ****/
void Bureaucrat::assertGradeRange(const unsigned int grade) {
	if (grade < GRADE_UPPER) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (GRADE_LOWER < grade) {
		throw Bureaucrat::GradeTooLowException();
	}
}


/***** exception ****/
Bureaucrat::GradeTooLowException::GradeTooLowException() :
	std::out_of_range(COLOR_RED"Grade too Low X("COLOR_RESET) {}

Bureaucrat::GradeTooHighException::GradeTooHighException() :
	std::out_of_range(COLOR_RED"Grade too High :o"COLOR_RESET) {}


// overload of the insertion << operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << COLOR_GREEN <<
	bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() <<
	COLOR_RESET;
	return os;
}
