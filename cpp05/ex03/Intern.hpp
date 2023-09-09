#pragma once

# include <cctype>
# include <string>

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN		"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET		"\x1b[0m"

# define SHRUBBERY_IDX		0
# define ROBOTOMY_IDX		1
# define PRESIDENTIAL_IDX	2

# define FORM_CNT 3

// The intern has no name, no grade, no unique characteristics.
class Intern {
public:
	/***** constructor, destructor, copy assignment operator ****/
	Intern();
	Intern(Intern const &other);
	~Intern();

	Intern &operator=(Intern const &rhs);

	// argument : The first one is the name of a form, second one is the target of the form.
	// return   : pointer to a Form object (whose name is the one passed as parameter)
	//            whose target will be initialized to the second parameter.
	AForm *makeForm(const std::string &form_name,
					const std::string &form_target);

private:
	std::string form_names_[FORM_CNT];

	void assertFormName(const std::string &form_name) const;
	std::string stringToLower(const std::string &str) const;
};