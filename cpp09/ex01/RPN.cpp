#include <climits>
#include <iostream>
#include <iomanip>
#include <string>
#include "RPN.hpp"

#define RESET		"\033[0m"
#define CYAN		"\033[36m"

RPN::RPN() : succeed_(false), calc_result_(), num_stack_() {}

RPN::RPN(const char *expression) : succeed_(false), calc_result_(), num_stack_() {
    rpn(std::string(expression));
}

RPN::RPN(const std::string &expression) : succeed_(false), calc_result_(), num_stack_() {
    rpn(expression);
}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs) {
	if (this == &rhs) {
		return *this;
	}
	this->succeed_ = rhs.succeed_;
	this->calc_result_ = rhs.calc_result_;
	this->num_stack_ = rhs.num_stack_;
	return *this;
}

void RPN::rpn(const std::string &expression) {
    int num, num1, num2;
    char c, op;

    for (std::size_t pos = 0; pos < expression.length(); ++pos) {
        c = expression[pos];

        if (is_delimiter(c)) {
            continue;
        }
        if (is_num(c)) {
            num = to_digit(c);
            this->num_stack_.push(num);
            continue;
        }
        if (is_operator(c)) {
            op = c;
            if (this->num_stack_.size() < 2) {
                return;
            }
            num2 = this->num_stack_.top();
            this->num_stack_.pop();
            num1 = this->num_stack_.top();
            this->num_stack_.pop();

            if (!is_valid_operand(num1, num2, op)) {
                return;
            }

            switch (op) {
                case '+':
                    num = num1 + num2;
                    break;
                case '-':
                    num = num1 - num2;
                    break;
                case '*':
                    num = num1 * num2;
                    break;
                case '/':
                    num = num1 / num2;
                    break;
                default:
                    return;
            }
            // std::cout << CYAN << " "
            // << std::right << std::setw(10) << num1
            // << " " << op << " "
            // << std::left << std::setw(10) << num2
            // << " = "
            // << std::right << std::setw(10)<< num << RESET << std::endl;
            this->num_stack_.push(num);
            continue;
        }
        return;
    }

    if (this->num_stack_.size() != 1) {
        return;
    }
    this->calc_result_ = num_stack_.top();
    this->num_stack_.pop();
    this->succeed_ = true;
}

bool RPN::is_succeed() { return this->succeed_; }
int RPN::get_calc_result() { return this->calc_result_; }
bool RPN::is_num(char c) { return std::isdigit(c); }

bool RPN::is_operator(char c) {
	return std::string(OPERATOR).find(c) != std::string::npos;
}

bool RPN::is_delimiter(char c) {
	return std::string(DELIMITER).find(c) != std::string::npos;
}

int RPN::to_digit(char c) { return c - '0'; }

bool RPN::is_valid_operand(int num1, int num2, char op) {
	switch (op) {
		case '+':
			return !is_add_overflow(num1, num2) && !is_add_underflow(num1, num2);
		case '-':
			return !is_sub_overflow(num1, num2) && !is_sub_underflow(num1, num2);
		case '*':
			return !is_mul_overflow(num1, num2) && !is_mul_underflow(num1, num2);
		case '/':
			return num2 != 0 && !is_div_overflow(num1, num2);
		default:
			return false;
	}
}

// INT_MAX < a + b
//           ^   ^
//           +   +
bool RPN::is_add_overflow(int num1, int num2) {
	return 0 < num1 && INT_MAX - num1 < num2;
}

// a + b < INT_MIN
bool RPN::is_add_underflow(int num1, int num2) {
	return num1 < 0 && num2 < INT_MIN - num1;
}

// INT_MAX < a - b
//           ^   ^
//           +   -
bool RPN::is_sub_overflow(int num1, int num2) {
	return num2 < 0 && INT_MAX + num2 < num1;
}

// a - b < INT_MIN
// ^   ^
// -   +
bool RPN::is_sub_underflow(int num1, int num2) {
	return 0 < num2 && num1 < INT_MIN + num2;
}

// INT_MAX < a * b
bool RPN::is_mul_overflow(int num1, int num2) {
	if (num1 == 0 || num2 == 0) {
		return false;
	}
	if (num1 == -1) {
		return num2 == INT_MIN;
	}
	if (num2 == -1) {
		return num1 == INT_MIN;
	}

	if (0 < num1) {
		if (0 < num2) {
			return INT_MAX / num2 < num1;
		} else {
			return num2 < INT_MIN / num1;
		}
	} else {
		if (0 < num2) {
			return num1 < INT_MIN / num2;
		} else {
			if (num1 == INT_MIN || num2 == INT_MIN) {
				return true;
			}
			return num2 < INT_MAX / num1;
		}
	}
}

// a * b < INT_MIN
bool RPN::is_mul_underflow(int num1, int num2) {
	if (num1 == 0 || num2 == 0) {
		return false;
	}

	if (0 < num1) {
		if (0 < num2) {
			return false;
		} else {
			return num2 < INT_MIN / num1;
		}
	} else {
		if (0 < num2) {
			return num1 < INT_MIN / num2;
		} else {
			return false;
		}
	}
}

bool RPN::is_div_overflow(int num1, int num2) {
	return num1 == INT_MIN && num2 == -1;
}
