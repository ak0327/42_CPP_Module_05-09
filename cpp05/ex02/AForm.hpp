#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

class Bureaucrat;

class AForm {
private:
	const std::string	name_;
	bool				signed_;
	const unsigned int	grade_to_sign_; //needed??
	const unsigned int	grade_to_exec_; //needed??


	/***** setter ****/
	void setGradeToSign(const unsigned int grade_to_sign);
	void setGradeToExec(const unsigned int grade_to_exec);


public:
	/***** constructor, destructor, copy assignment operator ****/
	AForm();
	AForm(const AForm &form);
	AForm(const std::string &name,
		 const bool signed_,
		 const unsigned int grade_to_sign,
		 const unsigned int grade_to_exec);
	virtual ~AForm();
	AForm &operator=(const AForm &form);



	/***** sign by signer ****/
	void beSigned(Bureaucrat &signer);

	/***** execute bu executor ****/
	virtual void execute(const Bureaucrat &executor) const = 0;


	/***** validate ****/
	void assertGradeRange(const unsigned int grade_to_sign, const unsigned int grade_to_exec);
	virtual void assertSignerGrade(const Bureaucrat &signer) const;
	virtual void assertExecutorGrade(const Bureaucrat &executor) const;


	/***** getter, setter ****/
	// name
	virtual const std::string &getName() const;
	void setName(const std::string &name);

	// signed
	virtual bool getSigned() const;
	void setSigned(const bool is_signed);

	// grade_to_sign
	virtual unsigned int getGradeToSign() const;

	// grade_to_exex
	virtual unsigned int getGradeToExec() const;



	/***** exception ****/
	class GradeTooLowException : public std::out_of_range {
	public:
		GradeTooLowException();
	};

	class GradeTooHighException : public std::out_of_range {
	public:
		GradeTooHighException();
	};

	class UnsignedException : public std::out_of_range {
	public:
		UnsignedException();
	};

};

/***** overload of the operator ****/
std::ostream &operator<<(std::ostream &os, const AForm &form);
