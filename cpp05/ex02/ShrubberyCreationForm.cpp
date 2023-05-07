#include "ShrubberyCreationForm.hpp"

#define GRADE_TO_SIGN 145
#define GRADE_TO_EXEC 137

/***** constructor, destructor, copy assignment operator ****/
ShrubberyCreationForm::ShrubberyCreationForm() :
		AForm("ShrubberyCreationForm", false, GRADE_TO_SIGN, GRADE_TO_EXEC), target_() {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
		AForm("ShrubberyCreationForm", false, GRADE_TO_SIGN, GRADE_TO_EXEC),
		target_(target) {
	assertTargetName(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) :
		AForm("ShrubberyCreationForm", false, GRADE_TO_SIGN, GRADE_TO_EXEC), target_() {
	*this = form;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
		const ShrubberyCreationForm &form) {
	if (this != &form) {

	}
	return *this;
}


/***** getter, setter ****/
const std::string &ShrubberyCreationForm::getTarget() const { return target_; }

void ShrubberyCreationForm::setTarget(const std::string &target) {
	assertTargetName(target);
	const_cast<std::string &>(target_) = target;
}


/***** validate target name ****/
void ShrubberyCreationForm::assertTargetName(const std::string &target) const {
	if (target.empty()) {
		throw std::invalid_argument("[Error] Target Name invalid");
	}
}


/***** execute ****/
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	assertExecutorGrade(executor);
	createShrubberyFile();
}


/***** create file ****/
void ShrubberyCreationForm::createShrubberyFile() const {
	std::ofstream ofs;

	ofs.open(getTarget(), std::ofstream::out | std::ofstream::trunc);
	if (!ofs) {
		throw std::invalid_argument("[Error] file can't open");
	}

	ofs <<
	"               ,@@@@@@@,\n"
	"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
	"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
	"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
	"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
	"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
	"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
	"       |o|        | |         | |\n"
	"       |.|        | |         | |\n"
	"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n"
	"------------------------------------------------\n";

	ofs.close();
}

