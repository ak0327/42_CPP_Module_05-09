#include "Intern.hpp"
Intern::Intern() {}

Intern::~Intern() {}

// If the form name passed as parameter doesn’t exist, print an explicit error message.
AForm *Intern::makeForm(const std::string &form_name,
						const std::string &form_target) {


	std::cout << "Intern creates " << form_name << std::endl;
}

void Intern::assertFormName(const std::string &form_name) const {

}