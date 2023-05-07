#include "PresidentialPardonForm.hpp"

#define GRADE_TO_SIGN 25
#define GRADE_TO_EXEC 5

PresidentialPardonForm::PresidentialPardonForm() :
		AForm("PresidentialPardonForm", false, GRADE_TO_SIGN, GRADE_TO_EXEC), target_("hoge") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
		AForm("PresidentialPardonForm", false, GRADE_TO_SIGN, GRADE_TO_EXEC),
		target_(target) {
	validateTargetName();
}


/***** getter ****/
const std::string &PresidentialPardonForm::getTarget() const { return target_; }


/***** validate target name ****/
void PresidentialPardonForm::validateTargetName() const {
	if (getTarget().empty()) {
		throw std::invalid_argument("[Error] Target Name invalid");
	}
}


/***** execute ****/
void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	assertExecutorGrade(executor);
	std::cout << COLOR_MAGENTA << getTarget() <<
	" has been pardoned by Zaphod Beeblebrox." << COLOR_RESET << std::endl;
}

