#include "PresidentialPardonForm.hpp"

#define GRADE_TO_SIGN 25
#define GRADE_TO_EXEC 5

PresidentialPardonForm::PresidentialPardonForm() :
		AForm("PresidentialPardonForm", false, GRADE_TO_SIGN, GRADE_TO_EXEC), target_() {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
		AForm("PresidentialPardonForm", false, GRADE_TO_SIGN, GRADE_TO_EXEC),
		target_(target) {
	assertTargetName(getTarget());
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &form) :
		AForm("PresidentialPardonForm", false, GRADE_TO_SIGN, GRADE_TO_EXEC), target_() {
	*this = form;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
		const PresidentialPardonForm &form) {
	if (this != &form) {
		setTarget(form.getTarget());
	}
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

