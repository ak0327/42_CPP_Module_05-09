#pragma once
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

// Required grades: sign 72, exec 45
// Makes some drilling noises.
// Then, informs that <target> has been robotomized successfully 50% of the time.
// Otherwise, informs that the robotomy failed.

// take only one parameter in their constructor: the target of the form.


class RobotomyRequestForm : public AForm {
private:
	const std::string	target_;


	/***** constructor ****/
	RobotomyRequestForm();


	/***** execute ****/
	void robotomize() const;
	int calcSuccessProbability() const;
	bool isSuccess() const;


	/***** validate target name ****/
	void validateTargetName() const;

public:
	/***** constructor, destructor, copy assignment operator ****/
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();

	/***** getter ****/
	const std::string &getTarget() const;

	/***** execute ****/
	virtual void execute(const Bureaucrat &executor) const ;

};
