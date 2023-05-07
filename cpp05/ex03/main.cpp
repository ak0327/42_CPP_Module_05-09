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
	std::string input;

	std::cout << "\n\n #######################################################" << std::endl;
	std::cout <<     " ================ ShrubberyCreationForm ================\n" << std::endl;
	{
		std::cout << "[1] ShrubberyCreationForm" << std::endl;
		try {
			input = "Shrubbery Creation";
			std::cout << "input:" << input << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Mr.Black", 5);
			std::cout << bureaucrat << std::endl;
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "testfile1");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\nsign and execute" << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);

		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2] ShrubberyCreationForm" << std::endl;
		try {
			input = "ShruBBery CreatIoN";
			std::cout << "input:" << input << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Mr.Black", 5);
			std::cout << bureaucrat << std::endl;
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "testfile2");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\nsign and execute" << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);

		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}


	std::cout << "\n\n #####################################################" << std::endl;
	std::cout <<     " ================ RobotomyRequestForm ================\n" << std::endl;
	{
		std::cout << "[1] ShrubberyCreationForm" << std::endl;
		try {
			input = "Robotomy Request";
			std::cout << "input:" << input << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Mr.Black", 5);
			std::cout << bureaucrat << std::endl;
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "foo");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\nsign and execute" << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);

		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2] ShrubberyCreationForm" << std::endl;
		try {
			input = "RBOTOMY Request";
			std::cout << "input:" << input << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Mr.Black", 5);
			std::cout << bureaucrat << std::endl;
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "bar");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\nsign and execute" << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);

		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}



	std::cout << "\n\n ########################################################" << std::endl;
	std::cout <<     " ================ PresidentialPardonForm ================\n" << std::endl;
	{
		std::cout << "[1] PresidentialPardonForm" << std::endl;
		try {
			input = "Presidential Pardon";
			std::cout << "input:" << input << std::endl;

			Bureaucrat bureaucrat = Bureaucrat("Mr.Black", 5);
			std::cout << bureaucrat << std::endl;
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "bar");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\nsign and execute" << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);

		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2] PresidentialPardonForm" << std::endl;
		try {
			input = "presiDEntIal PARDON";
			std::cout << "input:" << input << std::endl;

			Bureaucrat bureaucrat = Bureaucrat("Mr.Black", 5);
			std::cout << bureaucrat << std::endl;
			Intern intern;

			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "bar");

			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;

			std::cout << "\nsign and execute" << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);

		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}


	std::cout << "\n\n ########################################################" << std::endl;
	std::cout <<     " ================ error ================\n" << std::endl;
	{
		std::cout << "[1] form name" << std::endl;
		try {
			input = "";
			std::cout << "input:" << input << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2] form name invalid" << std::endl;
		try {
			input = "Shrubbery Creationn";
			std::cout << "input:" << input << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[3] form name invalid" << std::endl;
		try {
			input = "Shrubbery Creatiom";
			std::cout << "input:" << input << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[4] form name invalid" << std::endl;
		try {
			input = "ShrubberyCreation";
			std::cout << "input:" << input << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[5] form name invalid" << std::endl;
		try {
			input = "hoge";
			std::cout << "input:" << input << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[6] form name invalid" << std::endl;
		try {
			input = "AForm";
			std::cout << "input:" << input << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[7] form name invalid" << std::endl;
		try {
			input = "123";
			std::cout << "input:" << input << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "hoge");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[8] target name invalid" << std::endl;
		try {
			input = "shrubbery creation";
			std::cout << "input:" << input << std::endl;
			Intern intern;
			std::cout << "make form" << std::endl;
			AForm *form = intern.makeForm(input, "");
			std::cout << "\nform info" << std::endl;
			std::cout << *form << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	system("leaks a.out");
	return 0;
}