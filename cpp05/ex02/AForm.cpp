#include "Form.hpp"

/***** constructor, destructor, copy assignment operator ****/

Form::Form() : name_(), signed_(), upper_grade_(GRADE_UPPER), lower_grade_(GRADE_LOWER) {
	validateGradeRange(getUpperGrade(), getLowerGrade());
}

Form::~Form() {}

Form::Form(const Form &form) : name_(), signed_(), upper_grade_(GRADE_UPPER), lower_grade_(GRADE_LOWER)  {
	*this = form;
	validateGradeRange(getUpperGrade(), getLowerGrade());
}

Form::Form(const std::string &name,
		   const bool signed_,
		   const unsigned int upper_grade,
		   const unsigned int lower_grade) :
		   name_(name),
		   signed_(signed_),
		   upper_grade_(upper_grade),
		   lower_grade_(lower_grade) {
	validateGradeRange(getUpperGrade(), getLowerGrade());
}

Form &Form::operator=(const Form &form) {
	if (this != &form) {
		setName(form.getName());
		setSigned(form.getSigned());
		setUpperGrade(form.getUpperGrade());
		setLowerGrade(form.getLowerGrade());
		validateGradeRange(getUpperGrade(), getLowerGrade());
	}
	return *this;
}

/***** sign by bureaucrat ****/
void Form::beSigned(Bureaucrat &bureaucrat) {
	validateBureaucratSignableToForm(bureaucrat);
	bureaucrat.signForm(*this);
}

/***** validate ****/
void Form::validateBureaucratSignableToForm(const Bureaucrat &bureaucrat) {
	if (getUpperGrade() <= bureaucrat.getGrade() &&\
		bureaucrat.getGrade() <= getLowerGrade()) {
		return ;
	}
	if (bureaucrat.getGrade() < getUpperGrade()) {
		throw Form::GradeTooHighException();
	}
	throw Form::GradeTooLowException();
}

void Form::validateGradeRange(const unsigned int upper,
							  const unsigned int lower) {
	if (upper > lower) {
		throw std::invalid_argument("invalid argument");
	}
	if (upper < GRADE_UPPER) {
		throw std::invalid_argument("invalid argument");
	}
	if (GRADE_LOWER < lower) {
		throw std::invalid_argument("invalid argument");
	}
}


/***** getter, setter ****/
// name
const std::string &Form::getName() const { return name_; }

void Form::setName(const std::string &name) {
	const_cast<std::string &>(name_) = name;
}

// signed
bool Form::getSigned() const { return signed_; }

void Form::setSigned(const bool is_signed) { signed_ = is_signed; }

// lower_grade
 unsigned int Form::getLowerGrade() const { return lower_grade_; }

void Form::setLowerGrade(const unsigned int upper_grade) {
	const_cast<unsigned int&>(lower_grade_) = upper_grade;
}

// upper_grade
 unsigned int Form::getUpperGrade() const { return upper_grade_; }

void Form::setUpperGrade(const unsigned int upper_grade) {
	const_cast<unsigned int&>(upper_grade_) = upper_grade;
}


/***** exception ****/
const char *Form::GradeTooLowException::what() const throw() {
	return COLOR_RED"Grade too Low"COLOR_RESET;
}

const char *Form::GradeTooHighException::what() const throw() {
	return COLOR_RED"Grade too High"COLOR_RESET;
}



/***** overload of the operator ****/
std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << COLOR_YELLOW << "Form info:" << form.getName() <<
	   ", signed:" << (form.getSigned() ? "true" : "false") <<
	   ", grade:[" << form.getUpperGrade() <<
	   ", " << form.getLowerGrade() <<
	   "]" << COLOR_RESET;
	return os;
}