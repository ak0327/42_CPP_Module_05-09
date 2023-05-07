#include "Form.hpp"

/***** constructor, destructor, copy assignment operator ****/

Form::Form() : name_(), signed_(), grade_to_sign_(GRADE_UPPER), grade_to_exec_(GRADE_UPPER) {
	Bureaucrat::assertGradeRange(getGradeToSign());
	Bureaucrat::assertGradeRange(getGradeToExec());
}

Form::~Form() {}

Form::Form(const Form &form) : name_(), signed_(), grade_to_sign_(GRADE_UPPER), grade_to_exec_(GRADE_UPPER)  {
	*this = form;

	Bureaucrat::assertGradeRange(getGradeToSign());
	Bureaucrat::assertGradeRange(getGradeToExec());
}

Form::Form(const std::string &name,
		   const bool signed_,
		   const unsigned int grade_to_sign,
		   const unsigned int grade_to_exec) :
		   name_(name),
		   signed_(signed_),
		   grade_to_sign_(grade_to_sign),
		   grade_to_exec_(grade_to_exec) {

	Bureaucrat::assertGradeRange(getGradeToSign());
	Bureaucrat::assertGradeRange(getGradeToExec());
}

Form &Form::operator=(const Form &form) {
	if (this != &form) {
		setName(form.getName());
		setSigned(form.getSigned());
		setGradeToSign(form.getGradeToSign());
		setGradeToExec(form.getGradeToExec());

		Bureaucrat::assertGradeRange(getGradeToSign());
		Bureaucrat::assertGradeRange(getGradeToExec());
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
	if (bureaucrat.getGrade() <= getGradeToSign()) {
		return ;
	}
	throw Form::GradeTooLowException();
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

// grade to sign
unsigned int Form::getGradeToSign() const { return grade_to_sign_; }

void Form::setGradeToSign(const unsigned int grade_to_sign) {
	const_cast<unsigned int&>(grade_to_sign_) = grade_to_sign;
}

// grade to exec
unsigned int Form::getGradeToExec() const { return grade_to_exec_; }

void Form::setGradeToExec(const unsigned int grade_to_exec) {
	const_cast<unsigned int&>(grade_to_exec_) = grade_to_exec;
}


/***** exception ****/
Form::GradeTooLowException::GradeTooLowException() :
		std::out_of_range(COLOR_RED"Grade too Low X("COLOR_RESET) {}

Form::GradeTooHighException::GradeTooHighException() :
		std::out_of_range(COLOR_RED"Grade too High :o"COLOR_RESET) {}



/***** overload of the operator ****/
std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << COLOR_YELLOW <<
	"### Form info:: Name:[" << form.getName() <<
	"], signed:[" << (form.getSigned() ? "✓" : " ") <<
	"], grade to sign:[" << form.getGradeToSign() <<
	"], grade to exec:[" << form.getGradeToExec() <<
	"] ###" << COLOR_RESET;
	return os;
}