#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	{
		std::cout << "[1] Form[sign=1, exec=3]" << std::endl;
		try {
			Form formA = Form("FormA", false, 1, 3);
			std::cout << formA << std::endl;

			std::cout << "\nformB = Form(formA)" << std::endl;
			Form formB = Form(formA);
			formB.setName("formB");
			std::cout << formB << std::endl;


			std::cout << "\nBureA(1) sign to formB(1)" << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("BureA", 1);
			formB.beSigned(bureaucrat);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

			std::cout << "\nBureA(1) sign to formB(1), already signed" << std::endl;
			formB.beSigned(bureaucrat);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "[2] Form[sign=1, exec=3], Bureaucrat[5]" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BureA", 5);
			Form form = Form("FormA", false, 1, 3);
			std::cout << bureaucrat << std::endl;
			std::cout << form << std::endl;
			form.beSigned(bureaucrat);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "[3] Form[sign=150, exec=150]" << std::endl;
		try {
			Form form = Form("FormA", false, 150, 150);
			std::cout << form << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "[4] Form[sign=0, exec=1]" << std::endl;
		try {
			Form form = Form("FormA", false, 0, 1);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "[5] Form[sign=0, exec=151]" << std::endl;
		try {
			Form form = Form("FormA", false, 0, 151);

		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "[6] Form[sign=151, exec=1]" << std::endl;
		try {
			Form form = Form("FormA", false, 151, 1);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "[7] Form[sign=151, exec=151]" << std::endl;
		try {
			Form form = Form("FormA", false, 151, 151);

		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "[8] Form[sign=1, exec=0]" << std::endl;
		try {
			Form form = Form("FormA", false, 1, 0);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "[9] Form[sign=1, exec=151]" << std::endl;
		try {
			Form form = Form("FormA", false, 1, 151);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "[10] Form[sign=1, exec=5]=Form[10, 20], Bure(12)" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BureA", 10);
			Form formA = Form("FormA", false, 1, 5);
			Form formB = Form("FormB", false, 10, 20);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

			std::cout << "\nformA=formB" << std::endl;
			formA = formB;
			formA.setName("formA");
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

			std::cout << "\nBureA(10) sign to formB(10)" << std::endl;
			formB.beSigned(bureaucrat);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

			std::cout << "\nBureA(10)->(8)" << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //9
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //8
			std::cout << bureaucrat << std::endl;

			std::cout << "\nBureA(8) sign to formA(10)" << std::endl;
			formA.beSigned(bureaucrat);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "[11] FormA[sign=1, exec=5], FormB=Form(FormA), Bure(1)" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BureA", 1);
			Form formA = Form("FormA", false, 1, 5);
			Form formB = Form(formA);
			formB.setName("FromB");
			std::cout << bureaucrat << std::endl;
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

			std::cout << "\nBureA(1) sign to formA(3)" << std::endl;
			formA.beSigned(bureaucrat);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

			std::cout << "\nBureA(1) sign to formB(3)" << std::endl;
			formB.beSigned(bureaucrat);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

			std::cout << "\nBureA(1)->(4) and sign to B(3)" << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.decrementGrade(); //2
			bureaucrat.decrementGrade(); //3
			bureaucrat.decrementGrade(); //4
			std::cout << bureaucrat << std::endl;
			formB.beSigned(bureaucrat);
			std::cout << formA << std::endl;
			std::cout << formB << std::endl;

		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	return 0;
}