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

# define SETW	10

enum literal_type {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_ERROR
};

class ScalarConverter {
 public:
	static void convert(const std::string &str);

 private:
	// staticクラスはインスタンス化が必要ないため、インスタンス化を禁止
	ScalarConverter();
	~ScalarConverter();

	static enum literal_type judge_literal_type(const std::string &str);

	static bool is_literal_char(const std::string &str);
	static bool is_literal_int(const std::string &str);
	static bool is_literal_float(const std::string &str);
	static bool is_literal_double(const std::string &str);

	static void display_impossible();

	static char convert_to_char(const std::string &num_str);
	static int convert_to_int(const std::string &num_str);
	static float convert_to_float(const std::string &num_str);
	static double convert_to_double(const std::string &num_str);

	static std::string remove_suffix_f(const std::string &str);

	static int convert_str_to_int(const std::string &num_str, bool *err);
	static float convert_str_to_float(const std::string &num_str, bool *err);
	static double convert_str_to_double(const std::string &num_str, bool *err);

	static float get_out_of_range_value(const std::string &num_str);

	static bool is_str_inf(const std::string &str);
	static bool is_str_nan(const std::string &str);
	static bool is_str_inff(const std::string &str);
	static bool is_str_nanf(const std::string &str);

	static bool is_head_space(const std::string &num_str);
	static bool has_negative_exponent(const std::string &num_str);
	static bool has_valid_exponent(const std::string &num_str);
	static bool is_hex(const std::string &num_str);
};
