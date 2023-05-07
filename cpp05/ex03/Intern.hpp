#pragma once

#include <string>
#include "AForm.hpp"

// The intern has no name, no grade, no unique characteristics.
class Intern {
private:

	void assertFormName(const std::string &form_name) const;

public:
	Intern();
	~Intern();

	// argument : The first one is the name of a form, second one is the target of the form.
	// return   : pointer to a Form object (whose name is the one passed as parameter)
	//            whose target will be initialized to the second parameter.
	AForm *makeForm(const std::string &form_name, const std::string &form_target);

};