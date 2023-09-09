#pragma once

# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

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
	RobotomyRequestForm(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);


	/***** getter, setter ****/
	const std::string &getTarget() const;
	void setTarget(const std::string &target);


	/***** execute ****/
	virtual void execute(const Bureaucrat &executor) const ;

 private:
	std::string	target_;
	const static int GRADE_TO_SIGN_ = 72;
	const static int GRADE_TO_EXEC_ = 45;

	/***** execute ****/
	void robotomize() const;
	int calcSuccessProbability() const;
	bool isSuccess() const;


	/***** validate target name ****/
	void assertTargetName(const std::string &target) const;
};
