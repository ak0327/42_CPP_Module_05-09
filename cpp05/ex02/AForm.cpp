#include "AForm.hpp"

/***** constructor, destructor, copy assignment operator ****/

AForm::AForm() : name_(), signed_(), grade_to_sign_(GRADE_UPPER), grade_to_exec_(GRADE_UPPER) {
	Bureaucrat::validateGradeRange(getGradeToSign());
	Bureaucrat::validateGradeRange(getGradeToExec());
}

AForm::~AForm() {}

AForm::AForm(const AForm &form) : name_(), signed_(), grade_to_sign_(GRADE_UPPER), grade_to_exec_(GRADE_UPPER)  {
	*this = form;

	Bureaucrat::validateGradeRange(getGradeToSign());
	Bureaucrat::validateGradeRange(getGradeToExec());
}

AForm::AForm(const std::string &name,
		   const bool signed_,
		   const unsigned int grade_to_sign,
		   const unsigned int grade_to_exec) :
		   name_(name),
		   signed_(signed_),
		   grade_to_sign_(grade_to_sign),
		   grade_to_exec_(grade_to_exec) {

	Bureaucrat::validateGradeRange(getGradeToSign());
	Bureaucrat::validateGradeRange(getGradeToExec());
}

AForm &AForm::operator=(const AForm &form) {
	if (this != &form) {
		setName(form.getName());
		setSigned(form.getSigned());
		setGradeToSign(form.getGradeToSign());
		setGradeToExec(form.getGradeToExec());

		Bureaucrat::validateGradeRange(getGradeToSign());
		Bureaucrat::validateGradeRange(getGradeToExec());
	}
	return *this;
}

/***** sign by bureaucrat ****/
void AForm::beSigned(Bureaucrat &bureaucrat) {
	validateBureaucratSignableToForm(bureaucrat);
	bureaucrat.signForm(*this);
}

/***** validate ****/
void AForm::validateBureaucratSignableToForm(const Bureaucrat &bureaucrat) {
	if (getGradeToSign() <= bureaucrat.getGrade() &&\
		bureaucrat.getGrade() <= getGradeToExec()) {
		return ;
	}
	if (bureaucrat.getGrade() < getGradeToSign()) {
		throw AForm::GradeTooHighException();
	}
	throw AForm::GradeTooLowException();
}


/***** getter, setter ****/
// name
const std::string &AForm::getName() const { return name_; }

void AForm::setName(const std::string &name) {
	const_cast<std::string &>(name_) = name;
}

// signed
bool AForm::getSigned() const { return signed_; }

void AForm::setSigned(const bool is_signed) { signed_ = is_signed; }

// grade to sign
unsigned int AForm::getGradeToSign() const { return grade_to_sign_; }

void AForm::setGradeToSign(const unsigned int grade_to_sign) {
	const_cast<unsigned int&>(grade_to_sign_) = grade_to_sign;
}

// grade to exec
unsigned int AForm::getGradeToExec() const { return grade_to_exec_; }

void AForm::setGradeToExec(const unsigned int grade_to_exec) {
	const_cast<unsigned int&>(grade_to_exec_) = grade_to_exec;
}


/***** exception ****/
const char *AForm::GradeTooLowException::what() const throw() {
	return COLOR_RED"[AForm Error] Grade too Low to sign"COLOR_RESET;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return COLOR_RED"[AForm Error] Grade too High to sign"COLOR_RESET;
}



/***** overload of the operator ****/
std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << COLOR_YELLOW << "[AForm info:" << form.getName() <<
	   ", signed:" << (form.getSigned() ? "true" : "false") <<
	   ", grade to sign:" << form.getGradeToSign() <<
	   ", grade to exec" << form.getGradeToExec() <<
	   "]" << COLOR_RESET;
	return os;
}