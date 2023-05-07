#include "AForm.hpp"

/***** constructor, destructor, copy assignment operator ****/

AForm::AForm() : name_(), signed_(), grade_to_sign_(GRADE_UPPER), grade_to_exec_(GRADE_UPPER) {
	assertGradeRange(getGradeToSign(), getGradeToExec());
}

AForm::~AForm() {}

AForm::AForm(const AForm &form) : name_(), signed_(), grade_to_sign_(GRADE_UPPER), grade_to_exec_(GRADE_UPPER)  {
	*this = form;

	assertGradeRange(getGradeToSign(), getGradeToExec());
}

AForm::AForm(const std::string &name,
		   const bool signed_,
		   const unsigned int grade_to_sign,
		   const unsigned int grade_to_exec) :
		name_(name),
		signed_(signed_),
		grade_to_sign_(grade_to_sign),
		grade_to_exec_(grade_to_exec) {

	assertGradeRange(getGradeToSign(), getGradeToExec());
}

AForm &AForm::operator=(const AForm &form) {
	if (this != &form) {
		setName(form.getName());
		setSigned(form.getSigned());
		setGradeToSign(form.getGradeToSign());
		setGradeToExec(form.getGradeToExec());

		assertGradeRange(getGradeToSign(), getGradeToExec());
	}
	return *this;
}


/***** sign by signer ****/
void AForm::beSigned(Bureaucrat &signer) {
	assertSignerGrade(signer);
	setSigned(true);
//	signer.signForm(*this);
}


/***** validate ****/
// grade to sign/exec must in range of bureaucrat's one
void AForm::assertGradeRange(const unsigned int grade_to_sign,
							 const unsigned int grade_to_exec) {
	Bureaucrat::assertGradeRange(grade_to_sign);
	Bureaucrat::assertGradeRange(grade_to_exec);
}

void AForm::assertSignerGrade(const Bureaucrat &signer) const {
	if (signer.getGrade() <= getGradeToSign()) {
		return ;
	}
	throw AForm::GradeTooLowException();
}

void AForm::assertExecutorGrade(const Bureaucrat &executor) const {
	if (getSigned() && executor.getGrade() <= getGradeToExec()) {
		return ;
	}
	if (!getSigned()) {
		throw AForm::UnsignedException();
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
AForm::GradeTooLowException::GradeTooLowException() :
		std::out_of_range(COLOR_RED"Grade too LOW X("COLOR_RESET) {}

AForm::GradeTooHighException::GradeTooHighException() :
		std::out_of_range(COLOR_RED"Grade too HIGH :o"COLOR_RESET) {}

AForm::UnsignedException::UnsignedException() :
		std::out_of_range(COLOR_RED"Form NOT SIGNED :<"COLOR_RESET) {}



/***** overload of the operator ****/
std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << COLOR_YELLOW <<
	   "### AForm info:: Name:[" << form.getName() <<
	   "], signed:[" << (form.getSigned() ? "✓" : " ") <<
	   "], grade to sign:[" << form.getGradeToSign() <<
	   "], grade to exec:[" << form.getGradeToExec() <<
	   "] ###" << COLOR_RESET;
	return os;
}