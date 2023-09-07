#include "Bureaucrat.hpp"
#include "Form.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

#define FORM_INIT_NAME		"form name"
#define FORM_INIT_SIGNED	0


/***** constructor, destructor, copy assignment operator ****/

Form::Form() : name_(FORM_INIT_NAME),
			   signed_(FORM_INIT_SIGNED),
			   grade_to_sign_(GRADE_LOWER_),
			   grade_to_exec_(GRADE_LOWER_) {

	assertGradeRange(this->getGradeToSign(), this->getGradeToExec());
}

Form::Form(const Form &other) : name_(other.getName()),
							   signed_(other.getSigned()),
							   grade_to_sign_(other.getGradeToSign()),
							   grade_to_exec_(other.getGradeToExec()) {

	assertGradeRange(this->getGradeToSign(), this->getGradeToExec());
}

Form::Form(const std::string &name,
		   bool is_signed,
		   unsigned int grade_to_sign,
		   unsigned int grade_to_exec) : name_(name),
		   								 signed_(is_signed),
										 grade_to_sign_(GRADE_LOWER_),
										 grade_to_exec_(GRADE_LOWER_) {

	assertGradeRange(grade_to_sign, grade_to_exec);
	this->setGradeToSign(grade_to_sign);
	this->setGradeToExec(grade_to_exec);
}

Form::~Form() {}

Form &Form::operator=(const Form &rhs) {
	if (this == &rhs) {
		return *this;
	}
	this->setName(rhs.getName());
	this->setSigned(rhs.getSigned());
	this->setGradeToSign(rhs.getGradeToSign());
	this->setGradeToExec(rhs.getGradeToExec());

	assertGradeRange(this->getGradeToSign(), this->getGradeToExec());
	return *this;
}


/***** sign by signer ****/
void Form::beSigned(Bureaucrat const &signer) {
	this->assertSignerGrade(signer);
	if (this->getSigned()) {
		std::cerr << COLOR_YELLOW "[Info] Form already signed" COLOR_RESET << std::endl;
		return;
	}
	this->setSigned(true);
}


/***** validate ****/
void Form::assertGradeRange(const unsigned int grade_to_sign,
							const unsigned int grade_to_exec) const {

	Bureaucrat::assertGradeRange(grade_to_sign);
	Bureaucrat::assertGradeRange(grade_to_exec);
}

void Form::assertSignerGrade(const Bureaucrat &signer) const {
	if (this->getGradeToSign() < signer.getGrade()) {
		throw Form::GradeTooLowException();
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
		std::out_of_range(COLOR_RED "Grade too Low X(" COLOR_RESET) {}

Form::GradeTooHighException::GradeTooHighException() :
		std::out_of_range(COLOR_RED "Grade too High :o" COLOR_RESET) {}



/***** overload of the operator ****/
std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << COLOR_YELLOW <<
	"### Form info:: Name:[" << form.getName() << "], " \
	"signed:[" << (form.getSigned() ? "✓" : " ") << "], " \
	"grade to sign:[" << form.getGradeToSign() << "], " \
	"grade to exec:[" << form.getGradeToExec() << "] ###" <<
	COLOR_RESET;
	return os;
}
