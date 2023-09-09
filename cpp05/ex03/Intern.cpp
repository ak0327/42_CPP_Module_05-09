#include <string>
#include "Intern.hpp"

/***** constructor, destructor, copy assignment operator ****/
Intern::Intern() {
	this->form_names_[SHRUBBERY_IDX] = "shrubbery creation";
	this->form_names_[ROBOTOMY_IDX] = "robotomy request";
	this->form_names_[PRESIDENTIAL_IDX] = "presidential pardon";
}

Intern::Intern(Intern const &other) {
	for (int i = 0; i < FORM_CNT; ++i) {
		this->form_names_[i] = other.form_names_[i];
	}
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &rhs) {
	if (this == &rhs) {
		return *this;
	}
	for (int i = 0; i < FORM_CNT; ++i) {
		this->form_names_[i] = rhs.form_names_[i];
	}
	return *this;
}

// If the form name passed as parameter doesn’t exist, print an explicit error message.
AForm *Intern::makeForm(const std::string &form_name,
						const std::string &target) {

	const std::string name = stringToLower(form_name);
	assertFormName(name);

	AForm *form;
	int i = 0;
	while (i < FORM_CNT) {
		if (name == form_names_[i]) {
			break ;
		}
		i++;
	}
	try {
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
	}
	catch (std::bad_alloc const &e) {
		throw std::runtime_error("[Error] Fail to allocate memory");
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
	throw std::invalid_argument(COLOR_RED "[Error] Form name invalid" COLOR_RESET);
}

std::string Intern::stringToLower(const std::string &str) const {
	std::string ret = "";

	for (size_t i=0; i<str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			ret += str[i] - 'A' + 'a';
		} else {
			ret += std::tolower(str[i]);
		}
	}
	return ret;
}
