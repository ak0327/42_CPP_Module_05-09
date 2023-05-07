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
public:
	/***** constructor, destructor, copy assignment operator ****/
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &form);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &form);


	/***** getter ****/
	const std::string &getTarget() const;

	/***** execute ****/
	virtual void execute(const Bureaucrat &executor) const ;

private:
	const std::string	target_;


	/***** setter ****/
	void setTarget(const std::string &target);


	/***** execute ****/
	void robotomize() const;
	int calcSuccessProbability() const;
	bool isSuccess() const;


	/***** validate target name ****/
	void assertTargetName(const std::string &target) const;
};
