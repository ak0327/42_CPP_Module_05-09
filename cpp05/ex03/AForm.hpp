#pragma once

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET	"\x1b[0m"

# define FORM_INIT_NAME		"form name"
# define FORM_INIT_SIGNED	0

class Bureaucrat;

class AForm {
 public:
	/***** constructor, destructor, copy assignment operator ****/
	AForm();
	AForm(const AForm &form);
	AForm(const std::string &name,
		 bool signed_,
		 const unsigned int grade_to_sign,
		 const unsigned int grade_to_exec);
	virtual ~AForm();
	AForm &operator=(const AForm &form);


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


	/***** sign by signer ****/
	void beSigned(Bureaucrat const &signer);

	/***** execute bu executor ****/
	virtual void execute(const Bureaucrat &executor) const = 0;


	/***** validate ****/
	void assertGradeRange(const unsigned int grade_to_sign,
						  const unsigned int grade_to_exec);
	void assertSignerGrade(const Bureaucrat &signer) const;
	virtual void assertExecutorGrade(const Bureaucrat &executor) const;


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
};

/***** overload of the operator ****/
std::ostream &operator<<(std::ostream &os, const AForm &form);
