#include <string>
#include "PresidentialPardonForm.hpp"

#define INIT_PRESIDENTIAL_TARGET	"init_target"
#define INIT_PRESIDENTIAL_FORM_NAME	"PresidentialPardonForm"

/***** constructor, destructor, copy assignment operator ****/
PresidentialPardonForm::PresidentialPardonForm() :
		AForm(INIT_PRESIDENTIAL_FORM_NAME, false, GRADE_TO_SIGN_, GRADE_TO_EXEC_),
		target_(INIT_PRESIDENTIAL_TARGET) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
		AForm(INIT_PRESIDENTIAL_FORM_NAME, false, GRADE_TO_SIGN_, GRADE_TO_EXEC_),
		target_(target) {

	assertTargetName(getTarget());
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
		AForm(other),
		target_(other.getTarget()) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this == &rhs) {
		return *this;
	}
	AForm::operator=(rhs);
	target_ = rhs.getTarget();
	return *this;
}


/***** getter, setter ****/
const std::string &PresidentialPardonForm::getTarget() const { return target_; }

void PresidentialPardonForm::setTarget(const std::string &target) {
	assertTargetName(target);
	const_cast<std::string &>(target_) = target;
}


/***** validate target name ****/
void PresidentialPardonForm::assertTargetName(const std::string &target) const {
	if (target.empty()) {
		throw std::invalid_argument("[Error] Target Name invalid");
	}
}


/***** execute ****/
void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	assertExecutorGrade(executor);
	std::cout << COLOR_MAGENTA << getTarget() <<
	" has been pardoned by Zaphod Beeblebrox." << COLOR_RESET << std::endl;
}

