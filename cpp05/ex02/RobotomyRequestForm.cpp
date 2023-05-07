#include "RobotomyRequestForm.hpp"

#define GRADE_TO_SIGN 72
#define GRADE_TO_EXEC 45

RobotomyRequestForm::RobotomyRequestForm() :
		AForm("RobotomyRequestForm", false, GRADE_TO_SIGN, GRADE_TO_EXEC), target_("hoge") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
		AForm("RobotomyRequestForm", false, GRADE_TO_SIGN, GRADE_TO_EXEC),
		target_(target) {
	validateTargetName();
}

/***** getter ****/
const std::string &RobotomyRequestForm::getTarget() const { return target_; }


/***** validate target name ****/
void RobotomyRequestForm::validateTargetName() const {
	if (getTarget().empty()) {
		throw std::invalid_argument("[Error] Target Name invalid");
	}
}


/***** execute ****/
void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	validateExecutorGrade(executor);
	robotomize();
}

void RobotomyRequestForm::robotomize() const {
	std::cout << COLOR_MAGENTA << getTarget() <<
	" has been robotomized\n" <<
	"\n (屮-_-)屮 rattling...\n"
	"...\n"
	"..\n"
	".\n" << COLOR_RESET << std::endl;
	if (isSuccess()) {
		std::cout << COLOR_MAGENTA << "SUCCEEDED!! 凹[◎凸◎]凹" << COLOR_RESET << std::endl;
	} else {
		std::cout << COLOR_MAGENTA << "FAILED... _____†_____" << COLOR_RESET << std::endl;
	}
}

bool RobotomyRequestForm::isSuccess() const {
	int probability = calcSuccessProbability();
//	std::cout << COLOR_MAGENTA << "(" << probability << ")" << COLOR_RESET << std::endl;
	return (probability >= 50);
}

int RobotomyRequestForm::calcSuccessProbability() const {
	std::srand(static_cast<unsigned>(std::time(NULL)));
	return std::rand() % 101;
}