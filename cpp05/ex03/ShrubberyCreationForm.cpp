#include "ShrubberyCreationForm.hpp"

/***** constructor, destructor, copy assignment operator ****/
ShrubberyCreationForm::ShrubberyCreationForm() :
		AForm(INIT_SHRUBBERY_FORM_NAME, false, GRADE_TO_SIGN_, GRADE_TO_EXEC_),
		target_(INIT_SHRUBBERY_TARGET) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
		AForm(INIT_SHRUBBERY_FORM_NAME, false, GRADE_TO_SIGN_, GRADE_TO_EXEC_),
		target_(target) {

	assertTargetName(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
		AForm(other),
		target_(other.getTarget()) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this == &rhs) {
		return *this;
	}
	AForm::operator=(rhs);
	target_ = rhs.getTarget();
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
	if (target.find('/') != std::string::npos) {
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
	std::string file = this->getTarget() + FILE_NAME_SUFFIX;

	ofs.open(file.c_str(), std::ofstream::out | std::ofstream::trunc);
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
	"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\ ₍ᐞ•༝•ᐞ₎ //__/_\n"
	"------------------------------------------------\n";

	ofs.close();
}
