#include <sstream>
#include <cmath>
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
			// std::cout << "TYPE_CHAR" << std::endl;
			chr = convert_to_char(str);
			display_convert_result(chr);
			break;
		case TYPE_INT:
			// std::cout << "TYPE_INT" << std::endl;
			int_val = convert_to_int(str);
			display_convert_result(int_val);
			break;
		case TYPE_FLOAT:
			// std::cout << "TYPE_FLOAT" << std::endl;
			float_val = convert_to_float(str);
			display_convert_result(float_val);
			break;
		case TYPE_DOUBLE:
			// std::cout << "TYPE_DOUBLE" << std::endl;
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

	if (is_head_space(str) || is_hex(str)) {
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
	bool is_convert_err;
	float float_num;
	std::string str_wo_f;

	if (is_head_space(str) || is_hex(str)) {
		return false;
	}
	if (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf") {
		return true;
	}
	size_t f_pos = str.find('f');
	if (f_pos == std::string::npos) {
		return false;
	}
	if (f_pos + 1 != str.size()) {
		return false;
	}
	str_wo_f = remove_suffix_f(str);
	float_num = convert_str_to_float(str_wo_f, &is_convert_err);
	if (is_convert_err) {
		return false;
	}
	(void)float_num;
	return true;
}

bool ScalarConverter::is_literal_double(const std::string &str) {
	bool is_convert_err;
	float double_num;

	if (is_head_space(str) || is_hex(str)) {
		return false;
	}
	if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan") {
		return true;
	}
	if (str.find('.') == std::string::npos && str.find_first_of("eE") == std::string::npos) {
		return false;
	}
	double_num = convert_str_to_float(str, &is_convert_err);
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
	bool is_convert_err;

	return convert_str_to_int(num_str, &is_convert_err);
}

float ScalarConverter::convert_to_float(const std::string &num_str) {
	bool is_convert_err;
	std::string str_wo_f;

	str_wo_f = remove_suffix_f(num_str);
	return convert_str_to_float(str_wo_f, &is_convert_err);
}

double ScalarConverter::convert_to_double(const std::string &num_str) {
	bool is_convert_err;

	return convert_str_to_double(num_str, &is_convert_err);
}

float ScalarConverter::convert_str_to_float(const std::string &num_str, bool *err) {
	float	float_num;
	size_t	idx;
	std::string float_str;
	std::ostringstream oss;

	*err = true;
	if (is_head_space(num_str) || is_hex(num_str)) {
		return 0;
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
	*err = false;
	return float_num;
}

double ScalarConverter::convert_str_to_double(const std::string &num_str, bool *err) {
	double	double_num;
	size_t	idx;
	std::string double_str;
	std::ostringstream oss;

	*err = true;
	if (is_head_space(num_str) || is_hex(num_str)) {
		return 0;
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
	*err = false;
	return double_num;
}

////////////////////////////////////////////////////////////////////////////////

/* ************************************ */
/*             helper funcs             */
/* ************************************ */

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

bool ScalarConverter::is_digit_after_decimal_point(const std::string &s) {
	size_t i = 0;

	if (s[i] != '.') {
		return false;
	}
	i++;
	while (isdigit(s[i])) {
		i++;
	}
	if (s[i]) {
		return false;
	}
	return true;
}

bool ScalarConverter::is_valid_fraction(const std::string &s) {
	size_t i = 0;

	if (s[i] == '-' || s[i] == '+') {
		i++;
	}
	if (s[i] != '.') {
		return false;
	}
	i++;
	while (isdigit(s[i])) {
		i++;
	}
	if (s[i]) {
		return false;
	}
	return true;
}

int ScalarConverter::convert_str_to_int(const std::string &num_str, bool *err) {
	int		int_num;
	size_t	idx;
	std::string endstr;

	*err = true;

	try {
		int_num = std::stoi(num_str, &idx, 10);
		endstr = num_str.substr(idx);
		if (num_str[idx] != '\0' && !is_digit_after_decimal_point(endstr)) {
			return 0;
		}
	} catch (std::out_of_range const &e) {
		return 0;
	} catch (std::exception const &e) {
		if (!is_valid_fraction(num_str)) {
			return 0;
		}
		int_num = 0;
	}
	*err = false;
	return int_num;
}

std::string ScalarConverter::remove_suffix_f(const std::string &str) {
	size_t	f_pos;
	std::string removed_str;

	f_pos = str.rfind('f');
	if (f_pos == std::string::npos) {
		return (str);
	}
	if (f_pos != str.size() - 1) {
		return (str);
	}
	removed_str = str;
	removed_str.resize(str.size() - 1);
	return (removed_str);
}
