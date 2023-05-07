#pragma once

#include "AForm.hpp"

// Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

// take only one parameter in their constructor: the target of the form.

class PresidentialPardonForm: public AForm {
private:
	const std::string	target_;


	/***** constructor ****/
	PresidentialPardonForm();

	/***** pardoned ****/
	void pardoned() const;

	/***** validate target name ****/
	void validateTargetName() const;

public:

	/***** constructor, destructor, copy assignment operator ****/
	PresidentialPardonForm(const std::string &target);
	virtual ~PresidentialPardonForm();


	/***** getter ****/
	const std::string &getTarget() const;

	/***** execute ****/
	virtual void execute(const Bureaucrat &executor) const ;

};