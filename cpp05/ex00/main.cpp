#include <exception>
#include <iostream>
#include <climits>
#include <string>
#include "Bureaucrat.hpp"

int main() {
	{
		std::cout << "========== [1] constructor ==========" << std::endl;

		{
			std::cout << " 1) OK(Grade = 1)" << std::endl;

			try {
				Bureaucrat bureaucrat = Bureaucrat("name", 1);
				std::cout << bureaucrat << std::endl;
			} catch (const Bureaucrat::GradeTooLowException &e) {
				std::cerr << "catch GradeTooLowException:" << e.what() << std::endl;
			} catch (const Bureaucrat::GradeTooHighException &e) {
				std::cerr << "catch GradeTooHighException:" << e.what() << std::endl;
			}
			std::cout << "\n" << std::endl;
		}
		{
			std::cout << " 2) NG(Grade = 0)" << std::endl;

			try {
				Bureaucrat bureaucrat = Bureaucrat("name", 0);
				std::cout << bureaucrat << std::endl;
			} catch (const Bureaucrat::GradeTooLowException &e) {
				std::cerr << "catch GradeTooLowException:" << e.what() << std::endl;
			} catch (const Bureaucrat::GradeTooHighException &e) {
				std::cerr << "catch GradeTooHighException:" << e.what() << std::endl;
			}
			std::cout << "\n" << std::endl;
		}
		{
			std::cout << " 3) NG(Grade = 151)" << std::endl;

			try {
				Bureaucrat bureaucrat = Bureaucrat("name", 151);
				std::cout << bureaucrat << std::endl;
			} catch (const Bureaucrat::GradeTooLowException &e) {
				std::cerr << "catch GradeTooLowException:" << e.what() << std::endl;
			} catch (const Bureaucrat::GradeTooHighException &e) {
				std::cerr << "catch GradeTooHighException:" << e.what() << std::endl;
			}
			std::cout << "\n" << std::endl;
		}
		{
			std::cout << " 4) NG(Grade = UINT_MAX)" << std::endl;

			try {
				Bureaucrat bureaucrat = Bureaucrat("name", UINT_MAX);
				std::cout << bureaucrat << std::endl;
			} catch (const Bureaucrat::GradeTooLowException &e) {
				std::cerr << "catch GradeTooLowException:" << e.what() << std::endl;
			} catch (const Bureaucrat::GradeTooHighException &e) {
				std::cerr << "catch GradeTooHighException:" << e.what() << std::endl;
			}
			std::cout << "\n" << std::endl;
		}
	}
	{
		std::cout << "========== [2] copy constructor ==========" << std::endl;

		Bureaucrat src = Bureaucrat("name", 42);
		Bureaucrat copy = Bureaucrat(src);

		std::cout << src << std::endl;
		std::cout << copy << std::endl;
		std::cout  << std::endl;

		std::cout << "[src] grade:42->41, name:name->HOGE" << std::endl;
		src.incrementGrade();
		src.setName("HOGE");
		std::cout << src << std::endl;
		std::cout << copy << std::endl;

		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "========== [3] copy assignment operator ==========" << std::endl;

		Bureaucrat src = Bureaucrat("name", 42);
		Bureaucrat copy = src;

		std::cout << src << std::endl;
		std::cout << copy << std::endl;
		std::cout << std::endl;

		std::cout << "[src] grade:42->43, name:name->hoge" << std::endl;
		src.decrementGrade();
		src.setName("hoge");
		std::cout << src << std::endl;
		std::cout << copy << std::endl;

		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "========== [4] grade 1->2->1->0->-1 ==========" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat_A", 1);

			std::cout << "Grade 1 : ";
			std::cout << bureaucrat << std::endl;	// 1

			std::cout << "Grade 2 : ";
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;	// 2

			std::cout << "Grade 1 : ";
			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;	// 1

			std::cout << "Grade 0 : ";
			bureaucrat.incrementGrade();				// exception
			std::cout << bureaucrat << std::endl;	// 0

			std::cout << "Grade -1 : ";
			bureaucrat.incrementGrade();
			std::cout << std::endl;
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << "catch GradeTooLowException:" << e.what() << std::endl;
		} catch (const Bureaucrat::GradeTooHighException &e) {
			std::cerr << "catch GradeTooHighException:" << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "========== [5] grade=149->150->151 ==========" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat_B", 149);

			std::cout << "Grade 149 : ";
			std::cout << bureaucrat << std::endl;	// 149

			std::cout << "Grade 150 : ";
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;	// 150

			std::cout << "Grade 151 : ";
			bureaucrat.decrementGrade();				// exception
			std::cout << bureaucrat << std::endl;	// 151

			std::cout << "Grade 152 : ";
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << "catch GradeTooLowException:" << e.what() << std::endl;
		} catch (const Bureaucrat::GradeTooHighException &e) {
			std::cerr << "catch GradeTooHighException:" << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
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
