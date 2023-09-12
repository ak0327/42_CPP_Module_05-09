#include <cmath>
#include <sstream>
#include "Display.hpp"
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}


void ScalarConverter::convert(const std::string &str) {
	enum literal_type type = judge_literal_type(str);
	char chr;
	int int_val;
	float float_val;
	double double_val;

	switch (type) {
		case TYPE_CHAR:
			// std::cout << COLOR_GREEN "char" COLOR_RESET << std::endl;
			chr = convert_to_char(str);
			display_convert_result(chr);
			break;
		case TYPE_INT:
			// std::cout << COLOR_GREEN "int" COLOR_RESET << std::endl;
			int_val = convert_to_int(str);
			display_convert_result(int_val);
			break;
		case TYPE_FLOAT:
			// std::cout << COLOR_GREEN "float" COLOR_RESET << std::endl;
			float_val = convert_to_float(str);
			display_convert_result(float_val);
			break;
		case TYPE_DOUBLE:
			// std::cout << COLOR_GREEN "double" COLOR_RESET << std::endl;
			double_val = convert_to_double(str);
			display_convert_result(double_val);
			break;
		default:
			display_impossible();
	}
}

////////////////////////////////////////////////////////////////////////////////

void ScalarConverter::display_impossible() {
	const std::string impossible = COLOR_RED "impossible" COLOR_RESET;

	std::cout << std::setw(SETW) << "  char" << ": " << impossible << std::endl;
	std::cout << std::setw(SETW) << "  int" << ": " << impossible << std::endl;
	std::cout << std::setw(SETW) << "  float" << ": " << impossible << std::endl;
	std::cout << std::setw(SETW) << "  double" << ": " << impossible << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

enum literal_type ScalarConverter::judge_literal_type(const std::string &str) {
	if (is_head_space(str) || is_hex(str)) {
		return TYPE_ERROR;
	}
	if (is_literal_char(str)) {
		return TYPE_CHAR;
	}
	if (is_literal_int(str)) {
		return TYPE_INT;
	}
	if (is_literal_float(str)) {
		return TYPE_FLOAT;
	}
	if (is_literal_double(str)) {
		return TYPE_DOUBLE;
	}
	return TYPE_ERROR;
}

bool ScalarConverter::is_literal_char(const std::string &str) {
	if (str.size() != 3) {
		return false;
	}
	return str[0] == '\'' && isascii(str[1]) && str[2] == '\'';
}

bool ScalarConverter::is_literal_int(const std::string &str) {
	int 	int_num;
	bool	is_convert_err;

	if (is_str_inf(str) || is_str_nan(str)){
		return false;
	}
	if (is_str_inff(str) || is_str_nanf(str)){
		return false;
	}
	if (str.find('.') != std::string::npos) {
		return false;
	}
	int_num = convert_str_to_int(str, &is_convert_err);
	if (is_convert_err) {
		return false;
	}
	(void)int_num;
	return true;
}

bool ScalarConverter::is_literal_float(const std::string &str) {
	size_t	f_pos;
	bool	is_convert_err;
	float	float_num;
	std::string str_rm_f;

	if (is_str_inff(str) || is_str_nanf(str)){
		return true;
	}
	f_pos = str.find('f');
	if (f_pos == std::string::npos || f_pos + 1 != str.size()) {
		return false;
	}
	str_rm_f = remove_suffix_f(str);
	float_num = convert_str_to_float(str_rm_f, &is_convert_err);
	if (is_convert_err) {
		return false;
	}
	(void)float_num;
	return true;
}

bool ScalarConverter::is_literal_double(const std::string &str) {
	bool	is_convert_err;
	float	double_num;

	if (is_str_inf(str) || is_str_nan(str)){
		return true;
	}
	if (str.find('.') == std::string::npos && str.find_first_of("eE") == std::string::npos) {
		return false;
	}
	double_num = convert_str_to_double(str, &is_convert_err);
	if (is_convert_err) {
		return false;
	}
	(void)double_num;
	return true;
}

////////////////////////////////////////////////////////////////////////////////

char ScalarConverter::convert_to_char(const std::string &num_str) {
	return num_str[1];
}

int ScalarConverter::convert_to_int(const std::string &num_str) {
	return convert_str_to_int(num_str, NULL);
}

float ScalarConverter::convert_to_float(const std::string &num_str) {
	std::string str_wo_f;

	str_wo_f = remove_suffix_f(num_str);
	return convert_str_to_float(str_wo_f, NULL);
}

double ScalarConverter::convert_to_double(const std::string &num_str) {
	return convert_str_to_double(num_str, NULL);
}

int ScalarConverter::convert_str_to_int(const std::string &num_str, bool *err) {
	int		int_num;
	size_t	idx;

	if (err) {
		*err = true;
	}
	try {
		int_num = std::stoi(num_str, &idx, 10);
		if (num_str[idx] != '\0') {
			return 0;
		}
	} catch (std::exception const &e) {
		return 0;
	}
	if (err) {
		*err = false;
	}
	return int_num;
}

float ScalarConverter::convert_str_to_float(const std::string &num_str, bool *err) {
	float	float_num;
	size_t	idx;

	if (err) {
		*err = true;
	}
	try {
		float_num = std::stof(num_str, &idx);
		if (num_str[idx]) {
			return 0;
		}
	} catch (const std::out_of_range &e) {
		if (!has_valid_exponent(num_str)) {
			return 0;
		} else {
			float_num = get_out_of_range_value(num_str);
		}
	} catch (const std::exception &e) {
		return 0;
	}
	if (err) {
		*err = false;
	}
	return float_num;
}

double ScalarConverter::convert_str_to_double(const std::string &num_str, bool *err) {
	double	double_num;
	size_t	idx;

	if (err) {
		*err = true;
	}
	try {
		double_num = std::stod(num_str, &idx);
		if (num_str[idx]) {
			return 0;
		}
	} catch (const std::out_of_range &e) {
		if (!has_valid_exponent(num_str)) {
			return 0;
		}
		double_num = static_cast<double>(get_out_of_range_value(num_str));
	} catch (const std::exception &e) {
		return 0;
	}
	if (err) {
		*err = false;
	}
	return double_num;
}

////////////////////////////////////////////////////////////////////////////////

/* ************************************ */
/*             helper funcs             */
/* ************************************ */

bool ScalarConverter::is_str_inf(const std::string &str) {
	return str == "inf" || str == "+inf" || str == "-inf";
}

bool ScalarConverter::is_str_nan(const std::string &str) {
	return str == "nan";
}

bool ScalarConverter::is_str_inff(const std::string &str) {
	return str == "inff" || str == "+inff" || str == "-inff";
}

bool ScalarConverter::is_str_nanf(const std::string &str) {
	return str == "nanf";
}

bool ScalarConverter::is_head_space(const std::string &num_str) {
	return num_str.size() >= 2 && num_str[0] == ' ';
}

bool ScalarConverter::is_hex(const std::string &num_str) {
	std::string prefix_str;

	if (num_str.size() < 2) {
		return false;
	}
	prefix_str = num_str.substr(0, 2);
	return prefix_str == "0x" || prefix_str == "0X";
}

float ScalarConverter::get_out_of_range_value(const std::string &num_str) {
	if (has_negative_exponent(num_str)) {
		if (num_str[0] == '-') {
			return -0.0;
		}
		return 0.0;
	}
	if (num_str[0] == '-') {
		return -INFINITY;
	}
	return INFINITY;
}

bool ScalarConverter::has_negative_exponent(const std::string &num_str) {
	size_t e_pos;

	e_pos = num_str.find_first_of("Ee");
	if (e_pos == std::string::npos) {
		return false;
	}
	return num_str[e_pos + 1] == '-';
}

bool ScalarConverter::has_valid_exponent(const std::string &num_str) {
	size_t e_pos;

	e_pos = num_str.find_first_of("Ee");
	if (e_pos == std::string::npos) {
		return true;
	}
	if (num_str[e_pos + 1] == '-' || num_str[e_pos + 1] == '+') {
		e_pos++;
	}
	for (size_t i = e_pos + 1; i < num_str.length(); ++i) {
		if (!isdigit(num_str[i])) {
			return false;
		}
	}
	return true;
}

std::string ScalarConverter::remove_suffix_f(const std::string &str) {
	size_t	f_pos;
	std::string removed_str;

	f_pos = str.rfind('f');
	if (f_pos == std::string::npos || f_pos != str.size() - 1) {
		return (str);
	}
	removed_str = str;
	removed_str.resize(str.size() - 1);
	return (removed_str);
}
