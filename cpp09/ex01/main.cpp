#include <cstdlib>
#include <iostream>
#include "RPN.hpp"

# define RESET		"\033[0m"
# define YELLOW		"\033[33m"

# define INPUT_ERR_MSG	"[Error] ./RPN \"inverted Polish mathematical expression\""
# define CALC_ERR_MSG	"[Error] calc error"

int main(int argc, char **argv) {
	const std::size_t EXPRESSION_IDX = 1;
	std::string expression;
	RPN rpn;

	if (argc != 2) {
		std::cout << YELLOW << INPUT_ERR_MSG << RESET << std::endl;
		return EXIT_FAILURE;
	}

	expression = std::string(argv[EXPRESSION_IDX]);
	rpn = RPN(expression);

	if (!rpn.is_succeed()) {
		std::cout << YELLOW << CALC_ERR_MSG << RESET << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << rpn.get_calc_result() << std::endl;
	return EXIT_SUCCESS;
}
