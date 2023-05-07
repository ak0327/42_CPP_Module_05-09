#include "Intern.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

#define SHRUBBERY_IDX		0
#define ROBOTOMY_IDX		1
#define PRESIDENTIAL_IDX	2

/***** constructor, destructor, copy assignment operator ****/
Intern::Intern() {
	form_names_[SHRUBBERY_IDX] = "shrubbery creation";
	form_names_[ROBOTOMY_IDX] = "robotomy request";
	form_names_[PRESIDENTIAL_IDX] = "presidential pardon";
}

Intern::~Intern() {}

// If the form name passed as parameter doesn’t exist, print an explicit error message.
AForm *Intern::makeForm(const std::string &form_name,
						const std::string &target) {

	const std::string name = toLower(form_name);
	assertFormName(name);

	AForm *form;
	int i = 0;
	while (i < FORM_CNT) {
		if (name == form_names_[i]) {
			break ;
		}
		i++;
	}
	switch (i) {
		case SHRUBBERY_IDX:
			form = new ShrubberyCreationForm(target);
			break ;
		case ROBOTOMY_IDX:
			form = new RobotomyRequestForm(target);
			break ;
		case PRESIDENTIAL_IDX:
			form = new PresidentialPardonForm(target);
			break ;
		default:
			throw std::invalid_argument("[Error] Form name invalid");
	}
	std::cout << COLOR_GREEN << "Intern creates " << form_name << COLOR_RESET << std::endl;
	return form;
}

void Intern::assertFormName(const std::string &form_name) const {
	int i = 0;

	while (i < FORM_CNT) {
		if (form_name == form_names_[i]) {
			return ;
		}
		i++;
	}
	throw std::invalid_argument(COLOR_RED"[Error] Form name invalid"COLOR_RESET);
}

std::string Intern::toLower(const std::string &str) const {
	std::string ret = "";

	for (size_t i=0; i<str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			ret += str[i] - 'A' + 'a';
		} else {
			ret += tolower(str[i]);
		}
	}
	return ret;
}
