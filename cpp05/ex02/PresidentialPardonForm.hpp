#pragma once

# include "AForm.hpp"


// Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

// take only one parameter in their constructor: the target of the form.

class PresidentialPardonForm: public AForm {
 public:
	/***** constructor, destructor, copy assignment operator ****/
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);


	/***** getter, setter ****/
	const std::string &getTarget() const;
	void setTarget(const std::string &target);


	/***** execute ****/
	virtual void execute(const Bureaucrat &executor) const ;

 private:
	std::string	target_;
	const static int GRADE_TO_SIGN_ = 25;
	const static int GRADE_TO_EXEC_ = 5;

	/***** pardoned ****/
	void pardoned() const;


	/***** validate target name ****/
	void assertTargetName(const std::string &target) const;
};