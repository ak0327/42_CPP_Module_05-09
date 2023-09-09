#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
//#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	std::srand(static_cast<unsigned>(std::time(NULL)));
	std::string form_name;

	{
		std::cout <<     " ================ Intern ================\n" << std::endl;

		{
			std::cout << "[1] Constructor" << std::endl;
			try {
				Intern intern = Intern();
				std::cout << " success" << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
			std::cout << "\n-----------------------------------------\n" << std::endl;
		}
		{
			std::cout << "[2] Copy Constructor" << std::endl;
			try {
				Intern a = Intern();
				Intern b = Intern(a);
				std::cout << " success" << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
			std::cout << "\n-----------------------------------------\n" << std::endl;
		}
		{
			std::cout << "[3] Copy Assignment" << std::endl;
			try {
				Intern a = Intern();
				Intern b = a;
				std::cout << " success" << std::endl;
			}
			catch (std::exception const &e) {
				std::cerr << "exception: std:" << e.what() << std::endl;
			}
			std::cout << "\n-----------------------------------------\n" << std::endl;
		}
	}

	std::cout << "\n\n #######################################################" << std::endl;
	std::cout <<     " ================ ShrubberyCreationForm ================\n" << std::endl;
	{
		std::cout << "[1] name=Shrubbery Creation, target=testfile1" << std::endl;
		try {
			form_name = "Shrubbery Creation";
			std::cout << "form_name:" << form_name << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Mr.Black", 5);
			std::cout << bureaucrat << std::endl;
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "testfile1");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\nsign and execute" << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);

			delete form;
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
		std::cout << "[2] name=ShruBBery CreatIoN, target=testfile2" << std::endl;
		try {
			form_name = "ShruBBery CreatIoN";
			std::cout << "form_name:" << form_name << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Mr.Black", 5);
			std::cout << bureaucrat << std::endl;
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "testfile2");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\nsign and execute" << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);

			delete form;

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


	std::cout << "\n\n #####################################################" << std::endl;
	std::cout <<     " ================ RobotomyRequestForm ================\n" << std::endl;
	{
		std::cout << "[1] subject: name=robotomy request, target=Bender" << std::endl;
		try {
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm("robotomy request", "Bender");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;


			delete form;

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
		std::cout << "[2] name=Robotomy Request, target=foo" << std::endl;
		try {
			form_name = "Robotomy Request";
			std::cout << "form_name:" << form_name << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Mr.Black", 5);
			std::cout << bureaucrat << std::endl;
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "foo");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\nsign and execute" << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);

			delete form;

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
		std::cout << "[3] name=RBOTOMY Request, target=bar" << std::endl;
		try {
			form_name = "RBOTOMY Request";
			std::cout << "form_name:" << form_name << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Mr.Black", 5);
			std::cout << bureaucrat << std::endl;
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "bar");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\nsign and execute" << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);

			delete form;

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


	std::cout << "\n\n ########################################################" << std::endl;
	std::cout <<     " ================ PresidentialPardonForm ================\n" << std::endl;
	{
		std::cout << "[1] name=Presidential Pardon, target=bar" << std::endl;
		try {
			form_name = "Presidential Pardon";
			std::cout << "form_name:" << form_name << std::endl;

			Bureaucrat bureaucrat = Bureaucrat("Mr.Black", 5);
			std::cout << bureaucrat << std::endl;
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "bar");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\nsign and execute" << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);

			delete form;

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
		std::cout << "[2] name=presiDEntIal PARDON, target=bar" << std::endl;
		try {
			form_name = "presiDEntIal PARDON";
			std::cout << "form_name:" << form_name << std::endl;

			Bureaucrat bureaucrat = Bureaucrat("Mr.Black", 5);
			std::cout << bureaucrat << std::endl;
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "bar");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\nsign and execute" << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);

			delete form;

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


	std::cout << "\n\n ########################################################" << std::endl;
	std::cout <<     " ================ error ================\n" << std::endl;
	{
		std::cout << "[1] name='', target=hoge" << std::endl;
		try {
			form_name = "";
			std::cout << "form_name:" << form_name << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			delete form;
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
		std::cout << "[2] name=Shrubbery Creationn, target=hoge" << std::endl;
		try {
			form_name = "Shrubbery Creationn";
			std::cout << "form_name:" << form_name << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			delete form;
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
		std::cout << "[3] name=Shrubbery Creatiom, target=hoge" << std::endl;
		try {
			form_name = "Shrubbery Creatiom";
			std::cout << "form_name:" << form_name << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			delete form;
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
		std::cout << "[4] name=ShrubberyCreation, target=hoge" << std::endl;
		try {
			form_name = "ShrubberyCreation";
			std::cout << "form_name:" << form_name << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			delete form;
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
		std::cout << "[5] name=hoge, target=hoge" << std::endl;
		try {
			form_name = "hoge";
			std::cout << "form_name:" << form_name << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			delete form;
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
		std::cout << "[6] name=AForm, target=hoge" << std::endl;
		try {
			form_name = "AForm";
			std::cout << "form_name:" << form_name << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			delete form;
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
		std::cout << "[7] name=123, target=hoge" << std::endl;
		try {
			form_name = "123";
			std::cout << "form_name:" << form_name << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			delete form;
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
		std::cout << "[8] name=shrubbery creation, target=''" << std::endl;
		try {
			form_name = "shrubbery creation";
			std::cout << "form_name:" << form_name << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(form_name, "");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			delete form;
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
