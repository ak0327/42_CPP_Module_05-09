#pragma once

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
	/***** constructor, destructor, copy assignment operator ****/
	Form();
	Form(const Form &other);
	Form(const std::string &name,
		 bool signed_,
		 unsigned int grade_to_sign,
		 unsigned int grade_to_exec);
	~Form();
	Form &operator=(const Form &rhs);


	/***** getter, setter ****/
	// name
	const std::string &getName() const;
	void setName(const std::string &name);

	// signed
	bool getSigned() const;
	void setSigned(bool is_signed);

	// grade_to_sign
	unsigned int getGradeToSign() const;

	// grade_to_exex
	unsigned int getGradeToExec() const;


	/***** sign by bureaucrat ****/
	void beSigned(Bureaucrat const &signer);

	/***** exception ****/
	class GradeTooLowException : public std::out_of_range {
	 public:
		GradeTooLowException();
	};

	class GradeTooHighException : public std::out_of_range {  // unused
	 public:
		GradeTooHighException();
	};

 private:
	const std::string	name_;
	bool				signed_;
	const unsigned int	grade_to_sign_;
	const unsigned int	grade_to_exec_;
	static const int	GRADE_UPPER_ = 1;
	static const int	GRADE_LOWER_ = 150;

	/***** setter ****/
	void setGradeToSign(unsigned int grade_to_sign);
	void setGradeToExec(unsigned int grade_to_exec);


	/***** validate ****/
	void assertGradeRange(const unsigned int grade_to_sign,
						  const unsigned int grade_to_exec) const;
	void assertSignerGrade(const Bureaucrat &signer) const;
};

/***** overload of the operator ****/
std::ostream &operator<<(std::ostream &os, const Form &form);
