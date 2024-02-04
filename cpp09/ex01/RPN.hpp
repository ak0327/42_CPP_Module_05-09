#pragma once

# include <stack>
# include <string>

# define DELIMITER	" \t"
# define OPERATOR	"+-/*"

class RPN {
 public:
	RPN();
    RPN(const char *expression);
	RPN(const std::string &expression);
	RPN(const RPN &other);
	~RPN();

	RPN &operator=(const RPN &rhs);

	bool is_succeed();
	int get_calc_result();

	static bool is_valid_operand(int num1, int num2, char op);
	static bool is_add_overflow(int num1, int num2);
	static bool is_add_underflow(int num1, int num2);
	static bool is_sub_overflow(int num1, int num2);
	static bool is_sub_underflow(int num1, int num2);
	static bool is_mul_overflow(int num1, int num2);
	static bool is_mul_underflow(int num1, int num2);
	static bool is_div_overflow(int num1, int num2);

 private:
	bool succeed_;
	int calc_result_;
	std::stack<int> num_stack_;

    void rpn(const std::string &expression);

	bool is_operator(char c);
	bool is_num(char c);
	bool is_delimiter(char c);
	int to_digit(char c);
};
