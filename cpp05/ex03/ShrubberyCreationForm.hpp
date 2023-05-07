#pragma once

#include <fstream>
#include "AForm.hpp"

// Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.

// take only one parameter in their constructor: the target of the form.

class ShrubberyCreationForm : public AForm {
public:
	/***** constructor, destructor, copy assignment operator ****/
	ShrubberyCreationForm(const std::string &target);
	virtual ~ShrubberyCreationForm();


	/***** getter ****/
	const std::string &getTarget() const;

	/***** execute ****/
	virtual void execute(const Bureaucrat &executor) const ;

private:
	const std::string	target_;

	/***** constructor ****/
	ShrubberyCreationForm();

	/***** create file ****/
	void createShrubberyFile() const;

	/***** validate target name ****/
	void assertTargetName() const;
};

