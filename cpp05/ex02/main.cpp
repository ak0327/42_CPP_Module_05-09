#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
//#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::srand(static_cast<unsigned>(std::time(NULL)));

	std::cout << "\n\n #######################################################" << std::endl;
	std::cout <<     " ================ ShrubberyCreationForm ================\n" << std::endl;
	{
		std::cout << "[1] " << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Cherry", 5);
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("file1");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[2] unsigned" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 5);
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("file2");
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[3] grade too low to sign" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 150);
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("file3");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[4] grade too low to exec" << std::endl;
		try {
			Bureaucrat bureaucrat_A = Bureaucrat("Willow", 1);
			Bureaucrat bureaucrat_B = Bureaucrat("Maple", 150);
			std::cout << bureaucrat_A << std::endl;
			std::cout << bureaucrat_B << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("file4");
			std::cout << form << std::endl;
			bureaucrat_A.signForm(form);
			std::cout << form << std::endl;
			bureaucrat_B.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[5] target=filename error" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 5);
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[6] target=filename error" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 5);
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form = ShrubberyCreationForm("test/");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;

	}
	std::cout << "\n\n #####################################################" << std::endl;
	std::cout <<     " ================ RobotomyRequestForm ================\n" << std::endl;
	{
		std::cout << "[1] " << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("R2-D2", 5);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("Anakin Skywalker");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;

	}
	{
		std::cout << "[2] unsigned" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("C-3PO", 5);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("Yoda");
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[3] grade too low to sign" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BB-8", 73);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("Luke Skywalke");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[4] grade too low to exec" << std::endl;
		try {
			Bureaucrat bureaucrat_A = Bureaucrat("R2-D2", 1);
			Bureaucrat bureaucrat_B = Bureaucrat("Maple", 46);
			std::cout << bureaucrat_A << std::endl;
			std::cout << bureaucrat_B << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("Luke Skywalke");
			std::cout << form << std::endl;
			bureaucrat_A.signForm(form);
			std::cout << form << std::endl;
			bureaucrat_B.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[5] target name error" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 5);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[6] sign grade == grade" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BB-8", 72);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("Luke Skywalke");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[7] exec grade == grade" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BB-8", 45);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form = RobotomyRequestForm("Luke Skywalke");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[8] robotomy x 3" << std::endl;
		try {
			Bureaucrat bureaucrat1 = Bureaucrat("Mr.White", 1);
			RobotomyRequestForm form1 = RobotomyRequestForm("hoge");
			bureaucrat1.signForm(form1);
			bureaucrat1.executeForm(form1);
			std::cout << std::endl;

			Bureaucrat bureaucrat2 = Bureaucrat("Mr.White", 1);
			RobotomyRequestForm form2 = RobotomyRequestForm("huga");
			bureaucrat2.signForm(form2);
			bureaucrat2.executeForm(form2);
			std::cout << std::endl;

			Bureaucrat bureaucrat3 = Bureaucrat("Mr.White", 1);
			RobotomyRequestForm form3 = RobotomyRequestForm("piyo");
			bureaucrat3.signForm(form3);
			bureaucrat3.executeForm(form3);

		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	std::cout << "\n\n ########################################################" << std::endl;
	std::cout <<     " ================ PresidentialPardonForm ================\n" << std::endl;

	{
		std::cout << "[1] " << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("R2-D2", 5);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("Anakin Skywalker");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;

	}
	{
		std::cout << "[2] unsigned" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("C-3PO", 5);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("Yoda");
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[3] grade too low to sign" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BB-8", 26);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("Luke Skywalke");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[4] grade too low to exec" << std::endl;
		try {
			Bureaucrat bureaucrat_A = Bureaucrat("R2-D2", 1);
			Bureaucrat bureaucrat_B = Bureaucrat("Maple", 6);
			std::cout << bureaucrat_A << std::endl;
			std::cout << bureaucrat_B << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("Luke Skywalke");
			std::cout << form << std::endl;
			bureaucrat_A.signForm(form);
			std::cout << form << std::endl;
			bureaucrat_B.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[5] target name error" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Maple", 5);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[6] sign grade == grade" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BB-8", 25);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("Luke Skywalke");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}
	{
		std::cout << "[7] exec grade == grade" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BB-8", 5);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form = PresidentialPardonForm("Luke Skywalke");
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n-----------------------------------------\n" << std::endl;
	}

	return 0;
}