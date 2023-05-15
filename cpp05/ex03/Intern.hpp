#pragma once

#include <cctype>
#include <string>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


#define FORM_CNT 3

// The intern has no name, no grade, no unique characteristics.
class Intern {
public:
	/***** constructor, destructor, copy assignment operator ****/
	Intern();
	~Intern();
	Intern(const Intern &intern);
	Intern &operator=(const Intern &intern);

	// argument : The first one is the name of a form, second one is the target of the form.
	// return   : pointer to a Form object (whose name is the one passed as parameter)
	//            whose target will be initialized to the second parameter.
	AForm *makeForm(const std::string &form_name, const std::string &form_target);

private:
	std::string form_names_[FORM_CNT];

	void assertFormName(const std::string &form_name) const;
	std::string stringToLower(const std::string &str) const;
	std::string toLower(const std::string &str) const;

};