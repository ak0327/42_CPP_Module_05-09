#include "Bureaucrat.hpp"
#include "AForm.hpp"

/***** constructor, destructor, copy assignment operator ****/
AForm::AForm() : name_(FORM_INIT_NAME),
				 signed_(FORM_INIT_SIGNED),
				 grade_to_sign_(),
				 grade_to_exec_(GRADE_LOWER_) {

	assertGradeRange(getGradeToSign(), getGradeToExec());
}

AForm::AForm(const AForm &other) : name_(other.getName()),
								  signed_(other.getSigned()),
								  grade_to_sign_(other.getGradeToSign()),
								  grade_to_exec_(other.getGradeToExec()) {

	assertGradeRange(getGradeToSign(), getGradeToExec());
}

AForm::AForm(const std::string &name,
			 bool is_signed,
			 unsigned int grade_to_sign,
			 unsigned int grade_to_exec) : name_(name),
										   signed_(is_signed),
										   grade_to_sign_(GRADE_LOWER_),
										   grade_to_exec_(GRADE_LOWER_) {

	assertGradeRange(grade_to_sign, grade_to_exec);
	setGradeToSign(grade_to_sign);
	setGradeToExec(grade_to_exec);
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &rhs) {
	if (this == &rhs) {
		return *this;
	}
	setName(rhs.getName());
	setSigned(rhs.getSigned());
	const_cast<unsigned int &>(grade_to_sign_) = rhs.getGradeToSign();
	const_cast<unsigned int &>(grade_to_exec_) = rhs.getGradeToExec();

	assertGradeRange(getGradeToSign(), getGradeToExec());
	return *this;
}


/***** sign by signer ****/
void AForm::beSigned(Bureaucrat const &signer) {
	this->assertSignerGrade(signer);
	if (getSigned()) {
		std::cerr << COLOR_YELLOW "[Info] Form already signed" COLOR_RESET << std::endl;
		return;
	}
	setSigned(true);
}

/***** validate ****/
void AForm::assertGradeRange(const unsigned int grade_to_sign,
							 const unsigned int grade_to_exec) {
	Bureaucrat::assertGradeRange(grade_to_sign);
	Bureaucrat::assertGradeRange(grade_to_exec);
}

void AForm::assertSignerGrade(const Bureaucrat &signer) const {
	if (this->getGradeToSign() < signer.getGrade()) {
		throw AForm::GradeTooLowException();
	}
}

void AForm::assertExecutorGrade(const Bureaucrat &executor) const {
	if (this->getGradeToExec() < executor.getGrade()) {
		throw AForm::GradeTooLowException();
	}
	if (!getSigned()) {
		throw AForm::UnsignedException();
	}
}


/***** getter, setter ****/
// name
const std::string &AForm::getName() const { return name_; }
void AForm::setName(const std::string &name) { const_cast<std::string &>(name_) = name; }

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
		std::out_of_range(COLOR_RED "Grade too LOW X(" COLOR_RESET) {}

AForm::GradeTooHighException::GradeTooHighException() :
		std::out_of_range(COLOR_RED "Grade too HIGH :o" COLOR_RESET) {}

AForm::UnsignedException::UnsignedException() :
		std::out_of_range(COLOR_RED "Form NOT SIGNED :<" COLOR_RESET) {}



/***** overload of the operator ****/
std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << COLOR_YELLOW <<
	"### Form info:: Name:[" << form.getName() << "], " \
	"signed:[" << (form.getSigned() ? "✓" : " ") << "], " \
	"grade to sign:[" << form.getGradeToSign() << "], " \
	"grade to exec:[" << form.getGradeToExec() << "] ###" <<
	COLOR_RESET;
	return os;
}
