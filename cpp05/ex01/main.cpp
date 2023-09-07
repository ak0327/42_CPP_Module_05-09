#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	{
		std::cout << "========== [1] Constructor ==========" << std::endl;
		{
			std::cout << " 1) Constructor : formA = Form()" << std::endl;

			try {
				Form formA = Form("FormA", false, 1, 3);
				std::cout << "  formA:" << formA << std::endl;

			} catch (const Bureaucrat::GradeTooLowException &e) {
				std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
			} catch (const Bureaucrat::GradeTooHighException &e) {
				std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
			} catch (const Form::GradeTooLowException &e) {
				std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
			} catch (const Form::GradeTooHighException &e) {
				std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
			}
			std::cout << "\n" << std::endl;
		}
		{
			std::cout << " 2) Copy Constructor : formB = Form(formA)" << std::endl;

			try {
				Form formA = Form("FormA", false, 1, 3);

				Form formB = Form(formA);
				std::cout << "  formA:" << formA << std::endl;
				std::cout << "  formB:" << formB << "\n" << std::endl;

				std::cout << "formA name:formA->FORM, setSigned:false->true" << std::endl;
				formA.setName("FORM");
				formA.setSigned(true);
				std::cout << "  formA:" << formA << std::endl;
				std::cout << "  formB:" << formB << "\n" << std::endl;

			} catch (const Bureaucrat::GradeTooLowException &e) {
				std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
			} catch (const Bureaucrat::GradeTooHighException &e) {
				std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
			} catch (const Form::GradeTooLowException &e) {
				std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
			} catch (const Form::GradeTooHighException &e) {
				std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
			}
			std::cout << "\n" << std::endl;
		}
		{
			std::cout << " 3) Copy Assignment operator : formB = formA" << std::endl;

			try {
				Form formA = Form("FormA", false, 1, 3);
				Form formB = formA;

				std::cout << "  formA:" << formA << std::endl;
				std::cout << "  formB:" << formB << "\n" << std::endl;

				std::cout << "formA name:formA->FORM, setSigned:false->true" << std::endl;
				formA.setName("FORM");
				formA.setSigned(true);
				std::cout << "  formA:" << formA << std::endl;
				std::cout << "  formB:" << formB << "\n" << std::endl;

			} catch (const Bureaucrat::GradeTooLowException &e) {
				std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
			} catch (const Bureaucrat::GradeTooHighException &e) {
				std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
			} catch (const Form::GradeTooLowException &e) {
				std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
			} catch (const Form::GradeTooHighException &e) {
				std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
			}
			std::cout << "\n" << std::endl;
		}
		{
			std::cout << "========== [2] Form grade ==========" << std::endl;
			{
				std::cout << " 1) Form[sign=150, exec=150]" << std::endl;
				try {
					Form form = Form("FormA", false, 150, 150);
					std::cout << form << std::endl;
				} catch (const Bureaucrat::GradeTooLowException &e) {
					std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Bureaucrat::GradeTooHighException &e) {
					std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooLowException &e) {
					std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooHighException &e) {
					std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
				}		std::cout << "\n" << std::endl;
			}
			{
				std::cout << " 2) Form[sign=0, exec=1]" << std::endl;
				try {
					Form form = Form("FormA", false, 0, 1);
					std::cout << form << std::endl;
				} catch (const Bureaucrat::GradeTooLowException &e) {
					std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Bureaucrat::GradeTooHighException &e) {
					std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooLowException &e) {
					std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooHighException &e) {
					std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
				}		std::cout << "\n" << std::endl;
			}
			{
				std::cout << " 3) Form[sign=0, exec=151]" << std::endl;
				try {
					Form form = Form("FormA", false, 0, 151);
					std::cout << form << std::endl;
				} catch (const Bureaucrat::GradeTooLowException &e) {
					std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Bureaucrat::GradeTooHighException &e) {
					std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooLowException &e) {
					std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooHighException &e) {
					std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
				}		std::cout << "\n" << std::endl;
			}
			{
				std::cout << " 4) Form[sign=151, exec=1]" << std::endl;
				try {
					Form form = Form("FormA", false, 151, 1);
					std::cout << form << std::endl;
				} catch (const Bureaucrat::GradeTooLowException &e) {
					std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Bureaucrat::GradeTooHighException &e) {
					std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooLowException &e) {
					std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooHighException &e) {
					std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
				}		std::cout << "\n" << std::endl;
			}
			{
				std::cout << " 5) Form[sign=151, exec=151]" << std::endl;
				try {
					Form form = Form("FormA", false, 151, 151);
					std::cout << form << std::endl;
				} catch (const Bureaucrat::GradeTooLowException &e) {
					std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Bureaucrat::GradeTooHighException &e) {
					std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooLowException &e) {
					std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooHighException &e) {
					std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
				}		std::cout << "\n" << std::endl;
			}
			{
				std::cout << " 6) Form[sign=1, exec=0]" << std::endl;
				try {
					Form form = Form("FormA", false, 1, 0);
					std::cout << form << std::endl;
				} catch (const Bureaucrat::GradeTooLowException &e) {
					std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Bureaucrat::GradeTooHighException &e) {
					std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooLowException &e) {
					std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooHighException &e) {
					std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
				}		std::cout << "\n" << std::endl;
			}
			{
				std::cout << " 7) Form[sign=1, exec=151]" << std::endl;
				try {
					Form form = Form("FormA", false, 1, 151);
				} catch (const Bureaucrat::GradeTooLowException &e) {
					std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Bureaucrat::GradeTooHighException &e) {
					std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooLowException &e) {
					std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooHighException &e) {
					std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
				}		std::cout << "\n" << std::endl;
			}
			{
				std::cout << " 8) Form[sign=0, exec=20]" << std::endl;
				try {
					Form form = Form("FormA", false, 0, 20);
					std::cout << form << std::endl;
				} catch (const Bureaucrat::GradeTooLowException &e) {
					std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Bureaucrat::GradeTooHighException &e) {
					std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooLowException &e) {
					std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooHighException &e) {
					std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
				}		std::cout << "\n" << std::endl;
			}
			{
				std::cout << " 9) Form[sign=-1, exec=20]" << std::endl;
				try {
					Form form = Form("FormA", false, -1, 20);
					std::cout << form << std::endl;
				} catch (const Bureaucrat::GradeTooLowException &e) {
					std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Bureaucrat::GradeTooHighException &e) {
					std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooLowException &e) {
					std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooHighException &e) {
					std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
				}		std::cout << "\n" << std::endl;
			}
			{
				std::cout << " 10) Form[sign=10, exec=20]" << std::endl;
				try {
					Form form = Form("FormA", false, 10, 20);
					std::cout << form << std::endl;
				} catch (const Bureaucrat::GradeTooLowException &e) {
					std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Bureaucrat::GradeTooHighException &e) {
					std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooLowException &e) {
					std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
				} catch (const Form::GradeTooHighException &e) {
					std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
				}		std::cout << "\n" << std::endl;
			}
		}
	}

	{
		std::cout << "========== [2] Form[sign=1, exec=3], sign by Bureaucrat ==========" << std::endl;
		try {
			Form formA = Form("FormA", false, 1, 3);
			std::cout << formA << "\n" << std::endl;

			std::cout << "BureA(1) sign to formA(1)" << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("BureA", 1);

			bureaucrat.signForm(formA);
			std::cout << formA << "\n" << std::endl;

			std::cout << "BureA(1) sign to formA(1), already signed" << std::endl;
			bureaucrat.signForm(formA);
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
		} catch (const Bureaucrat::GradeTooHighException &e) {
			std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
		} catch (const Form::GradeTooLowException &e) {
			std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
		} catch (const Form::GradeTooHighException &e) {
			std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
		}
		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "========== [3] Form[sign=1, exec=3], Bureaucrat[5], can't sign ==========" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BureA", 5);
			Form form = Form("FormA", false, 1, 3);

			std::cout << "BureA(5) sign to formA(1)" << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << form << std::endl;

			bureaucrat.signForm(form);
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
		} catch (const Bureaucrat::GradeTooHighException &e) {
			std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
		} catch (const Form::GradeTooLowException &e) {
			std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
		} catch (const Form::GradeTooHighException &e) {
			std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
		}		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "========== [4] Form[sign=1, exec=5]=Form[10, 20], Bure(12) ==========" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BureA", 10);
			Form formA = Form("FormA", false, 1, 5);
			Form formB = Form("FormB", false, 10, 20);
			std::cout << "formA:" << formA << std::endl;
			std::cout << "formB:" << formB << std::endl;
			std::cout << std::endl;

			std::cout << "formA=formB, formA.setNAme('formA')" << std::endl;
			formA = formB;
			formA.setName("formA");
			std::cout << "formA:" << formA << std::endl;
			std::cout << "formB:" << formB << std::endl;
			std::cout << std::endl;

			std::cout << "BureA(10) sign to formB(10)" << std::endl;
			bureaucrat.signForm(formB);
			std::cout << "formA:" << formA << std::endl;
			std::cout << "formB:" << formB << std::endl;
			std::cout << std::endl;

			std::cout << "BureA(10)->(8)" << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //9
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade(); //8
			std::cout << bureaucrat << std::endl;
			std::cout << std::endl;

			std::cout << "BureA(8) sign to formA(10)" << std::endl;
			bureaucrat.signForm(formA);
			std::cout << "formA:" << formA << std::endl;
			std::cout << "formB:" << formB << std::endl;

		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
		} catch (const Bureaucrat::GradeTooHighException &e) {
			std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
		} catch (const Form::GradeTooLowException &e) {
			std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
		} catch (const Form::GradeTooHighException &e) {
			std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
		}		std::cout << "\n" << std::endl;
	}
	{
		std::cout << " ==========[5] FormA[sign=1, exec=5], FormB=Form(FormA), Bure(1) ==========" << std::endl;
		try {
			Bureaucrat bureaucrat = Bureaucrat("BureA", 1);
			Form formA = Form("FormA", false, 1, 5);

			std::cout << "formB=Form(formA), formB.setNAme('formB')" << std::endl;
			Form formB = Form(formA);
			formB.setName("FromB");
			std::cout << bureaucrat << std::endl;
			std::cout << "formA:" << formA << std::endl;
			std::cout << "formB:" << formB << std::endl;
			std::cout << std::endl;

			std::cout << "BureA(1) sign to formA(3)" << std::endl;
			formA.beSigned(bureaucrat);
			std::cout << "formA:" << formA << std::endl;
			std::cout << "formB:" << formB << std::endl;
			std::cout << std::endl;

			std::cout << "BureA(1) sign to formB(3)" << std::endl;
			formB.beSigned(bureaucrat);
			std::cout << "formA:" << formA << std::endl;
			std::cout << "formB:" << formB << std::endl;
			std::cout << std::endl;

			std::cout << "BureA(1)->(4) and sign to B(3)" << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.decrementGrade(); //2
			bureaucrat.decrementGrade(); //3
			bureaucrat.decrementGrade(); //4
			std::cout << bureaucrat << std::endl;
			formB.beSigned(bureaucrat);
			std::cout << "formA:" << formA << std::endl;
			std::cout << "formB:" << formB << std::endl;

		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
		} catch (const Bureaucrat::GradeTooHighException &e) {
			std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
		} catch (const Form::GradeTooLowException &e) {
			std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
		} catch (const Form::GradeTooHighException &e) {
			std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
		}		std::cout << "\n" << std::endl;
	}
	{
		std::cout << "========== [6] signForm(), beSigned() ==========" << std::endl;
		{
			try {
				std::cout << "1) signForm -> beSigned" << std::endl;

				Bureaucrat bureaucrat = Bureaucrat("BureA", 1);
				Form form = Form("FormA", false, 1, 30);

				std::cout << bureaucrat << std::endl;
				std::cout << form << std::endl;
				std::cout << std::endl;

				std::cout << "bureaucrat.signForm(form) : " << std::endl;
				bureaucrat.signForm(form);
				std::cout << form << std::endl;
				std::cout << std::endl;

				std::cout << "form.beSigned(bureaucrat) : " << std::endl;
				form.beSigned(bureaucrat);
				std::cout << form << std::endl;
				std::cout << std::endl;

			} catch (const Bureaucrat::GradeTooLowException &e) {
				std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
			} catch (const Bureaucrat::GradeTooHighException &e) {
				std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
			} catch (const Form::GradeTooLowException &e) {
				std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
			} catch (const Form::GradeTooHighException &e) {
				std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
			}		std::cout << "\n" << std::endl;
		}
		{
			try {
				std::cout << "2) beSigned -> signForm" << std::endl;
				Bureaucrat bureaucrat = Bureaucrat("BureA", 1);
				Form form = Form("FormA", false, 1, 30);

				std::cout << bureaucrat << std::endl;
				std::cout << form << std::endl;
				std::cout << std::endl;

				std::cout << "form.beSigned(bureaucrat) : " << std::endl;
				form.beSigned(bureaucrat);
				std::cout << form << std::endl;
				std::cout << std::endl;

				std::cout << "bureaucrat.signForm(form) : " << std::endl;
				bureaucrat.signForm(form);
				std::cout << form << std::endl;
				std::cout << std::endl;

			} catch (const Bureaucrat::GradeTooLowException &e) {
				std::cerr << "catch Bureaucrat::GradeTooLowException:[" << e.what() << "]" << std::endl;
			} catch (const Bureaucrat::GradeTooHighException &e) {
				std::cerr << "catch Bureaucrat::GradeTooHighException:[" << e.what() << "]" << std::endl;
			} catch (const Form::GradeTooLowException &e) {
				std::cerr << "catch Form::GradeTooLowException:[" << e.what() << "]" << std::endl;
			} catch (const Form::GradeTooHighException &e) {
				std::cerr << "catch Form::GradeTooHighException:[" << e.what() << "]" << std::endl;
			}		std::cout << "\n" << std::endl;
		}
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
