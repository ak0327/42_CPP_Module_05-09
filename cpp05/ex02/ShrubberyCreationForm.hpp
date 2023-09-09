#pragma once

# include <fstream>
# include "AForm.hpp"

# define INIT_SHRUBBERY_TARGET		"init_target"
# define INIT_SHRUBBERY_FORM_NAME	"ShrubberyCreationForm"
# define FILE_NAME_SUFFIX			"_shrubbery"

// Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.

// take only one parameter in their constructor: the target of the form.

class ShrubberyCreationForm : public AForm {
 public:
	/***** constructor, destructor, copy assignment operator ****/
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);


	/***** getter, setter ****/
	const std::string &getTarget() const;
	void setTarget(const std::string &target);


	/***** execute ****/
	virtual void execute(const Bureaucrat &executor) const;

 private:
	std::string target_;
	const static int GRADE_TO_SIGN_ = 145;
	const static int GRADE_TO_EXEC_ = 137;

	/***** create file ****/
	void createShrubberyFile() const;


	/***** validate target name ****/
	void assertTargetName(const std::string &target) const;
};

