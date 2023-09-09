#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::srand(static_cast<unsigned>(std::time(NULL)));

	// std::cout << " ================ AForm ================\n" << std::endl;
	// // can't compile 'AForm' is abstract class
	// {
	// 	std::cout << " 1) AForm" << std::endl;
	// 	AForm form = AForm();
	// 	std::cout << "form:" << form << std::endl;
	// }

	std::cout << "\n\n #########################################################" << std::endl;
	std::cout <<     " ================ 1 ShrubberyCreationForm ================\n" << std::endl;
	{
		std::cout << "[1-1] Constructor" << std::endl;
		{
			std::cout << " 1) Default Constructor" << std::endl;
			try {
				ShrubberyCreationForm form = ShrubberyCreationForm();
				std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;
				std::cout << std::endl;
			}
			catch (AForm::GradeTooHighException const &e) {
				std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
			}
			catch (AForm::GradeTooLowException const &e) {
				std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
			}
			catch (AForm::UnsignedException const &e) {
				std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
		}
		{
			std::cout << " 2) Constructor with argument" << std::endl;
			try {
				ShrubberyCreationForm form = ShrubberyCreationForm("a");
				std::cout << "form:" << form << ", target:" << form.getTarget() <<  std::endl;
				std::cout << std::endl;
			}
			catch (AForm::GradeTooHighException const &e) {
				std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
			}
			catch (AForm::GradeTooLowException const &e) {
				std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
			}
			catch (AForm::UnsignedException const &e) {
				std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
		}
		{
			std::cout << " 3) Copy Constructor" << std::endl;
			try {
				ShrubberyCreationForm formA = ShrubberyCreationForm("a");
				ShrubberyCreationForm formB = ShrubberyCreationForm(formA);

				std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
				std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
				std::cout << std::endl;

				std::cout << "formA target_name: a -> aa" << std::endl;
				formA.setTarget("aa");
				std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
				std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
				std::cout << std::endl;
			}
			catch (AForm::GradeTooHighException const &e) {
				std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
			}
			catch (AForm::GradeTooLowException const &e) {
				std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
			}
			catch (AForm::UnsignedException const &e) {
				std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
		}
		{
			std::cout << " 4) Copy Assignment Operator" << std::endl;
			try {
				ShrubberyCreationForm formA = ShrubberyCreationForm("a");
				ShrubberyCreationForm formB = formA;

				std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
				std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
				std::cout << std::endl;

				std::cout << "formA target_name: a -> aa" << std::endl;
				formA.setTarget("aa");
				std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
				std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
				std::cout << std::endl;
			}
			catch (AForm::GradeTooHighException const &e) {
				std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
			}
			catch (AForm::GradeTooLowException const &e) {
				std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
			}
			catch (AForm::UnsignedException const &e) {
				std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[1-1] " << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Cherry", 5);
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("file1");
			std::cout << "form:" << form << ", target:" << form.getTarget() <<  std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() <<  std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[1-2] unsigned form" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 5);
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("file2");
			std::cout << "form:" << form << ", target:" << form.getTarget() <<  std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[1-3] grade too low to sign" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 146);
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("file3");
			std::cout << "form:" << form << ", target:" << form.getTarget() <<  std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() <<  std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[1-4] grade too low to exec" << std::endl;
		try {
			Bureaucrat bureaucrat_A = Bureaucrat("Willow", 1);
			Bureaucrat bureaucrat_B = Bureaucrat("Maple", 138);
			std::cout << bureaucrat_A << std::endl;
			std::cout << bureaucrat_B << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("file4");
			std::cout << "form:" << form << ", target:" << form.getTarget() <<  std::endl;

			std::cout << "signForm : ";
			bureaucrat_A.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() <<  std::endl;

			std::cout << "executeForm : ";
			bureaucrat_B.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[1-5] error : target=''" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 5);
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[1-6] error : target=test/" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 5);
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("test/");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;

	}
	{
		std::cout << "[1-8] error : target=objs/file" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 5);
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("objs/file");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;

	}
	{
		std::cout << "[1-9] copy" << std::endl;
		try {
			std::cout << "formA signed" << std::endl;
			ShrubberyCreationForm formA = ShrubberyCreationForm();
			formA.setTarget("formA");
			Bureaucrat bureaucrat = Bureaucrat("Maple", 1);

			std::cout << "signForm : ";
			bureaucrat.signForm(formA);

			std::cout << "\nformB = Form(formA)" << std::endl;
			ShrubberyCreationForm formB = ShrubberyCreationForm(formA);
			formB.setTarget("formB");
			std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
			std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
			std::cout << std::endl;

			std::cout << "\nformC = formB" << std::endl;
			ShrubberyCreationForm formC;
			formC = formB;
			formC.setTarget("formC");
			std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
			std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
			std::cout << "formC:" << formC << ", target:" << formC.getTarget() <<  std::endl;

			std::cout << "\nformC signed" << std::endl;
			bureaucrat.signForm(formC);
			std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
			std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
			std::cout << "formC:" << formC << ", target:" << formC.getTarget() <<  std::endl;

		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;

	}
	std::cout << "\n\n #######################################################" << std::endl;
	std::cout <<     " ================ 2 RobotomyRequestForm ================\n" << std::endl;
	{
		std::cout << "[2-1] Constructor" << std::endl;
		{
			std::cout << " 1) Default Constructor" << std::endl;
			try {
				RobotomyRequestForm form = RobotomyRequestForm();
				std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;
				std::cout << std::endl;
			}
			catch (AForm::GradeTooHighException const &e) {
				std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
			}
			catch (AForm::GradeTooLowException const &e) {
				std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
			}
			catch (AForm::UnsignedException const &e) {
				std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
		}
		{
			std::cout << " 2) Constructor with argument" << std::endl;
			try {
				RobotomyRequestForm form = RobotomyRequestForm("a");
				std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;
				std::cout << std::endl;
			}
			catch (AForm::GradeTooHighException const &e) {
				std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
			}
			catch (AForm::GradeTooLowException const &e) {
				std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
			}
			catch (AForm::UnsignedException const &e) {
				std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
		}
		{
			std::cout << " 3) Copy Constructor" << std::endl;
			try {
				RobotomyRequestForm formA = RobotomyRequestForm("a");
				RobotomyRequestForm formB = RobotomyRequestForm(formA);

				std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
				std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
				std::cout << std::endl;

				std::cout << "formA target_name: a -> aa" << std::endl;
				formA.setTarget("aa");
				std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
				std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
				std::cout << std::endl;
			}
			catch (AForm::GradeTooHighException const &e) {
				std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
			}
			catch (AForm::GradeTooLowException const &e) {
				std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
			}
			catch (AForm::UnsignedException const &e) {
				std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
		}
		{
			std::cout << " 4) Copy Assignment Operator" << std::endl;
			try {
				RobotomyRequestForm formA = RobotomyRequestForm("a");
				RobotomyRequestForm formB = formA;

				std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
				std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
				std::cout << std::endl;

				std::cout << "formA target_name: a -> aa" << std::endl;
				formA.setTarget("aa");
				std::cout << "formA:" << formA << ", target:" << formA.getTarget() << std::endl;
				std::cout << "formB:" << formB << ", target:" << formB.getTarget() << std::endl;
				std::cout << std::endl;
			}
			catch (AForm::GradeTooHighException const &e) {
				std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
			}
			catch (AForm::GradeTooLowException const &e) {
				std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
			}
			catch (AForm::UnsignedException const &e) {
				std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2-1] " << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("R2-D2", 5);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("Anakin Skywalker");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;

	}
	{
		std::cout << "[2-2] unsigned form" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("C-3PO", 5);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("Yoda");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2-3] grade too low to sign" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BB-8", 73);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("Luke Skywalke");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2-4] grade too low to exec" << std::endl;
		try {
			Bureaucrat bureaucrat_A = Bureaucrat("R2-D2", 1);
			Bureaucrat bureaucrat_B = Bureaucrat("Maple", 46);
			std::cout << bureaucrat_A << std::endl;
			std::cout << bureaucrat_B << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("Luke Skywalke");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat_A.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat_B.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2-5] target name error" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 5);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2-6] sign grade == grade" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BB-8", 72);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("Luke Skywalke");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2-7] exec grade == grade" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BB-8", 45);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("Luke Skywalke");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2-8] robotomy x 3" << std::endl;
		try {
			Bureaucrat bureaucrat1 = Bureaucrat("Mr.White", 1);
			RobotomyRequestForm form1 = RobotomyRequestForm("hoge");

			std::cout << "signForm : ";
			bureaucrat1.signForm(form1);

			std::cout << "executeForm : ";
			bureaucrat1.executeForm(form1);
			std::cout << std::endl;

			Bureaucrat bureaucrat2 = Bureaucrat("Mr.White", 1);
			RobotomyRequestForm form2 = RobotomyRequestForm("huga");

			std::cout << "signForm : ";
			bureaucrat2.signForm(form2);

			std::cout << "executeForm : ";
			bureaucrat2.executeForm(form2);
			std::cout << std::endl;

			Bureaucrat bureaucrat3 = Bureaucrat("Mr.White", 1);
			RobotomyRequestForm form3 = RobotomyRequestForm("piyo");

			std::cout << "signForm : ";
			bureaucrat3.signForm(form3);

			std::cout << "executeForm : ";
			bureaucrat3.executeForm(form3);

		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2-9] copy" << std::endl;
		try {
			std::cout << "formA signed" << std::endl;
			RobotomyRequestForm formA = RobotomyRequestForm();
			formA.setTarget("formA");
			Bureaucrat bureaucrat = Bureaucrat("Maple", 1);

			std::cout << "signForm : ";
			bureaucrat.signForm(formA);

			std::cout << "\nformB = Form(formA)" << std::endl;
			RobotomyRequestForm formB = RobotomyRequestForm(formA);
			formB.setTarget("formB");
			std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
			std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
			std::cout << std::endl;

			std::cout << "\nformC = formB" << std::endl;
			RobotomyRequestForm formC;
			formC = formB;
			formC.setTarget("formC");
			std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
			std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
			std::cout << "formC:" << formC << ", target:" << formC.getTarget() <<  std::endl;

			std::cout << "\nformC signed" << std::endl;
			bureaucrat.signForm(formC);
			std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
			std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
			std::cout << "formC:" << formC << ", target:" << formC.getTarget() <<  std::endl;

		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;

	}
	std::cout << "\n\n ##########################################################" << std::endl;
	std::cout <<     " ================ 3 PresidentialPardonForm ================\n" << std::endl;
	{
		std::cout << "[3-1] Constructor" << std::endl;
		{
			std::cout << " 1) Default Constructor" << std::endl;
			try {
				PresidentialPardonForm form = PresidentialPardonForm();
				std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;
				std::cout << std::endl;
			}
			catch (AForm::GradeTooHighException const &e) {
				std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
			}
			catch (AForm::GradeTooLowException const &e) {
				std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
			}
			catch (AForm::UnsignedException const &e) {
				std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
		}
		{
			std::cout << " 2) Constructor with argument" << std::endl;
			try {
				PresidentialPardonForm form = PresidentialPardonForm("a");
				std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;
				std::cout << std::endl;
			}
			catch (AForm::GradeTooHighException const &e) {
				std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
			}
			catch (AForm::GradeTooLowException const &e) {
				std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
			}
			catch (AForm::UnsignedException const &e) {
				std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
		}
		{
			std::cout << " 3) Copy Constructor" << std::endl;
			try {
				PresidentialPardonForm formA = PresidentialPardonForm("a");
				PresidentialPardonForm formB = PresidentialPardonForm(formA);

				std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
				std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
				std::cout << std::endl;

				std::cout << "formA target_name: a -> aa" << std::endl;
				formA.setTarget("aa");
				std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
				std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
				std::cout << std::endl;
			}
			catch (AForm::GradeTooHighException const &e) {
				std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
			}
			catch (AForm::GradeTooLowException const &e) {
				std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
			}
			catch (AForm::UnsignedException const &e) {
				std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
		}
		{
			std::cout << " 4) Copy Assignment Operator" << std::endl;
			try {
				PresidentialPardonForm formA = PresidentialPardonForm("a");
				PresidentialPardonForm formB = formA;

				std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
				std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
				std::cout << std::endl;

				std::cout << "formA target_name: a -> aa" << std::endl;
				formA.setTarget("aa");
				std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
				std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
				std::cout << std::endl;
			}
			catch (AForm::GradeTooHighException const &e) {
				std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
			}
			catch (AForm::GradeTooLowException const &e) {
				std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
			}
			catch (AForm::UnsignedException const &e) {
				std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[3-1] " << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("R2-D2", 5);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("Anakin Skywalker");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;

	}
	{
		std::cout << "[3-2] unsigned" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("C-3PO", 5);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("Yoda");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
 			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[3-3] grade too low to sign" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BB-8", 26);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("Luke Skywalke");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[3-4] grade too low to exec" << std::endl;
		try {
			Bureaucrat bureaucrat_A = Bureaucrat("R2-D2", 1);
			Bureaucrat bureaucrat_B = Bureaucrat("Maple", 6);
			std::cout << bureaucrat_A << std::endl;
			std::cout << bureaucrat_B << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("Luke Skywalke");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat_A.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat_B.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[3-5] target name error" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 5);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[3-6] sign grade == grade" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BB-8", 25);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("Luke Skywalke");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[3-7] exec grade == grade" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BB-8", 5);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("Luke Skywalke");
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "signForm : ";
			bureaucrat.signForm(form);
			std::cout << "form:" << form << ", target:" << form.getTarget() << std::endl;

			std::cout << "executeForm : ";
			bureaucrat.executeForm(form);
		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[3-8] copy" << std::endl;
		try {
			std::cout << "formA signed" << std::endl;
			PresidentialPardonForm formA = PresidentialPardonForm();
			formA.setTarget("formA");
			Bureaucrat bureaucrat = Bureaucrat("Maple", 1);

			std::cout << "signForm : ";
			bureaucrat.signForm(formA);

			std::cout << "\nformB = Form(formA)" << std::endl;
			PresidentialPardonForm formB = PresidentialPardonForm(formA);
			formB.setTarget("formB");
			std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
			std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
			std::cout << std::endl;

			std::cout << "\nformC = formB" << std::endl;
			PresidentialPardonForm formC;
			formC = formB;
			formC.setTarget("formC");
			std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
			std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
			std::cout << "formC:" << formC << ", target:" << formC.getTarget() <<  std::endl;

			std::cout << "\nformC signed" << std::endl;
			bureaucrat.signForm(formC);
			std::cout << "formA:" << formA << ", target:" << formA.getTarget() <<  std::endl;
			std::cout << "formB:" << formB << ", target:" << formB.getTarget() <<  std::endl;
			std::cout << "formC:" << formC << ", target:" << formC.getTarget() <<  std::endl;

		}
		catch (AForm::GradeTooHighException const &e) {
			std::cerr << "exception: AForm::GradeTooHigh:" << e.what() << std::endl;
		}
		catch (AForm::GradeTooLowException const &e) {
			std::cerr << "exception: AForm::GradeTooLow:" << e.what() << std::endl;
		}
		catch (AForm::UnsignedException const &e) {
			std::cerr << "exception: AForm::Unsigned:" << e.what() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << "exception: std:" << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;

	}
	return 0;
}

#ifdef __APPLE__

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}

#endif
