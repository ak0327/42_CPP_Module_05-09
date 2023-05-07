#pragma once

#include "AForm.hpp"

// Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

// take only one parameter in their constructor: the target of the form.

class PresidentialPardonForm: public AForm {
public:

	/***** constructor, destructor, copy assignment operator ****/
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &form);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &form);


	/***** getter ****/
	const std::string &getTarget() const;

	/***** execute ****/
	virtual void execute(const Bureaucrat &executor) const ;

private:
	const std::string	target_;


	/***** setter ****/
	void setTarget(const std::string &target);


	/***** pardoned ****/
	void pardoned() const;

	/***** validate target name ****/
	void assertTargetName(const std::string &target) const;
};