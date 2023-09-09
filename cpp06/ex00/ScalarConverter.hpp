#pragma once

# include <climits>
# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>

# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET	"\x1b[0m"


class ScalarConverter {
 public:
	static void display_convert_result(const std::string &str);
	static std::string convert_to_char(const std::string &num_str);
	static std::string convert_to_int(const std::string &num_str);
	static std::string convert_to_float(const std::string &num_str);
	static std::string convert_to_double(const std::string &num_str);

 private:
	// staticクラスはインスタンス化が必要ないため、インスタンス化を禁止
	ScalarConverter();
	~ScalarConverter();

	static std::string get_num_str(const std::string &str);
	static std::string remove_suffix_f(const std::string &str);

	static int convert_str_to_int(const std::string &num_str, bool *err);
	static bool is_digit_after_decimal_point(const std::string &substr);
	static bool is_head_space(const std::string &num_str);
	static bool is_valid_fraction(const std::string &num_str);
	static bool has_negative_exponent(const std::string &num_str);
	static bool has_valid_exponent(const std::string &num_str);
	static std::string get_out_of_range_value(const std::string &num_str);
	static bool is_char_literal(const std::string &num_str);
	static bool is_hex(const std::string &num_str);
};
