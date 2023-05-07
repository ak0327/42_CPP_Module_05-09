#pragma once

#include <fstream>
#include "AForm.hpp"

// Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.

// take only one parameter in their constructor: the target of the form.

class ShrubberyCreationForm : public AForm {
public:
	/***** constructor, destructor, copy assignment operator ****/
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &form);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);


	/***** getter ****/
	const std::string &getTarget() const;

	/***** execute ****/
	virtual void execute(const Bureaucrat &executor) const ;

private:
	const std::string	target_;


	/***** setter ****/
	void setTarget(const std::string &target);

	/***** create file ****/
	void createShrubberyFile() const;

	/***** validate target name ****/
	void assertTargetName(const std::string &target) const;
};

