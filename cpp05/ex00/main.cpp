#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

#include <limits>

int main() {
	{
		std::cout << "[1] grade=1" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat_A", 1);
			std::cout << bureaucrat << std::endl;	// 1
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;	// 2
			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;	// 1
			bureaucrat.incrementGrade();				// exception
			std::cout << bureaucrat << std::endl;	// 0
			bureaucrat.incrementGrade();
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "[2] grade=149" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat_B", 149);
			std::cout << bureaucrat << std::endl;	// 149
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;	// 150
			bureaucrat.decrementGrade();				// exception
			std::cout << bureaucrat << std::endl;	// 151
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade();
			std::cout << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "[3] grade=0" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat_C", 0);
			std::cout << bureaucrat << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "[4] grade=151" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat_D", 151);
			std::cout << bureaucrat << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "[5] grade=UINT_MAX" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat_E", UINT_MAX);
			std::cout << bureaucrat << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "[6] a:grade=5, b=a" << std::endl;
		try {
			Bureaucrat a = Bureaucrat("Bureaucrat_A", 5);
			Bureaucrat b = Bureaucrat(a);
			b.setName("Bureaucrat_B");
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << std::endl;
			a.incrementGrade();
			b.decrementGrade();
			std::cout << a << std::endl;
			std::cout << b << std::endl;

		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "[7] a:(), ++ && --" << std::endl;
		try {
			Bureaucrat a = Bureaucrat();
			std::cout << a << std::endl;
			a.incrementGrade();
			std::cout << a << std::endl;
			a.decrementGrade();
			std::cout << a << std::endl;
			a.decrementGrade();
			std::cout << a << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}