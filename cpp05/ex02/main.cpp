#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
	{
		std::cout << "[1] AForm[1-3]" << std::endl;
		try {
			AForm formA = AForm("FormA", false, 1, 3);
			std::cout << formA << std::endl;

			std::cout << "\nformB = AForm(formA)" << std::endl;
			AForm formB = AForm(formA);
			formB.setName("formB");
			std::cout << formB << std::endl;


			std::cout << "\nBureA sign to formB" << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("BureA", 2);
			formB.beSigned(bureaucrat);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

			std::cout << "\nBureA sign to formB" << std::endl;
			formB.beSigned(bureaucrat);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "[2] AForm[1-3], Bureaucrat[5]" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BureA", 5);
			AForm form = AForm("FormA", false, 1, 3);
			std::cout << bureaucrat << std::endl;
			std::cout << form << std::endl;
			form.beSigned(bureaucrat);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "[3] AForm[0,0]" << std::endl;
		try {
			AForm form = AForm("FormA", false, 0, 0);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "[4] AForm[100,151]" << std::endl;
		try {
			AForm form = AForm("FormA", false, 0, 151);

		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "[5] AForm[100,1]" << std::endl;
		try {
			AForm form = AForm("FormA", false, 100, 1);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "[6] AForm[3,5]=AForm[10, 20], Bure(12)" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BureA", 12);
			AForm formA = AForm("FormA", false, 3, 5);
			AForm formB = AForm("FormB", false, 10, 20);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

			std::cout << "\nformA=formB" << std::endl;
			formA = formB;
			formA.setName("formA");
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

			std::cout << "\nBureA sign to formB" << std::endl;
			formB.beSigned(bureaucrat);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

			std::cout << "\nBureA(12)->(10)" << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //11
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //10
			std::cout << bureaucrat << std::endl;

			std::cout << "\nBureA sign to formA" << std::endl;
			formA.beSigned(bureaucrat);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

			std::cout << "\nBureA(10)->(0)" << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //9
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //8
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //7
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //6
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //5
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //4
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //3
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //2
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //1
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //0
			std::cout << bureaucrat << std::endl;

		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}