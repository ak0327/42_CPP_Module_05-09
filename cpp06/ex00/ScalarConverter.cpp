#include <sstream>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::display_convert_result(const std::string &str) {
	const int SETW = 10;
	std::string num_str = get_num_str(str);

	std::string char_str = convert_to_char(num_str);
	std::string int_str = convert_to_int(num_str);
	std::string float_str = convert_to_float(num_str);
	std::string double_str = convert_to_double(num_str);

	std::cout << std::setw(SETW) << "  char" << ": " << char_str << std::endl;
	std::cout << std::setw(SETW) << "  int" << ": " << int_str << std::endl;
	std::cout << std::setw(SETW) << "  float" << ": " << float_str << std::endl;
	std::cout << std::setw(SETW) << "  double" << ": " << double_str << std::endl;
}

std::string ScalarConverter::convert_to_char(const std::string &num_str) {
	int		int_num;
	char 	chr;
	bool	is_convert_err;
	std::string char_str;

	if (is_head_space(num_str)) {
		return COLOR_RED "impossible" COLOR_RESET;
	}

	int_num = convert_str_to_int(num_str, &is_convert_err);
	chr = static_cast<char>(int_num);

	if (is_convert_err || !isascii(int_num)) {
		char_str =  COLOR_RED "impossible" COLOR_RESET;
	} else if (!isprint(chr)) {
		char_str =  COLOR_YELLOW "Non displayable" COLOR_RESET;
	} else {
		char_str =  "'" + std::string(1, chr) + "'";
	}
	return char_str;
}

std::string ScalarConverter::convert_to_int(const std::string &num_str) {
	int 	int_num;
	bool	is_convert_err;
	std::string int_str;
	std::ostringstream oss;

	if (is_head_space(num_str)) {
		return COLOR_RED "impossible" COLOR_RESET;
	}

	int_num = convert_str_to_int(num_str, &is_convert_err);
	if (is_convert_err) {
		int_str = COLOR_RED "impossible" COLOR_RESET;
	} else {
		oss << int_num;
		int_str = oss.str();
	}
	return int_str;
}

std::string ScalarConverter::convert_to_float(const std::string &num_str) {
	float	float_num;
	size_t	idx;
	std::string float_str;
	std::ostringstream oss;

	if (is_head_space(num_str)) {
		return COLOR_RED "impossible" COLOR_RESET;
	}

	try {
		float_num = std::stof(num_str, &idx);
		if (num_str[idx]) {
			float_str = COLOR_RED "impossible" COLOR_RESET;
		} else {
			oss << std::fixed << std::setprecision(1) << float_num << "f";
			float_str = oss.str();
		}
	} catch (const std::out_of_range &e) {
		if (!has_valid_exponent(num_str)) {
			float_str = COLOR_RED "impossible" COLOR_RESET;
		} else {
			float_str = get_out_of_range_value(num_str);
			float_str += "f";
		}
	} catch (const std::exception &e) {
		float_str = COLOR_RED "impossible" COLOR_RESET;
	}
	return float_str;
}

std::string ScalarConverter::convert_to_double(const std::string &num_str) {
	double	double_num;
	size_t	idx;
	std::string double_str;
	std::ostringstream oss;

	if (is_head_space(num_str)) {
		return COLOR_RED "impossible" COLOR_RESET;
	}

	try {
		double_num = std::stod(num_str, &idx);
		if (num_str[idx]) {
			double_str = COLOR_RED "impossible" COLOR_RESET;
		} else {
			oss << std::fixed << std::setprecision(1) << double_num;
			double_str = oss.str();
		}
	} catch (const std::out_of_range &e) {
		if (!has_valid_exponent(num_str)) {
			double_str = COLOR_RED "impossible" COLOR_RESET;
		} else {
			double_str = get_out_of_range_value(num_str);
		}
	} catch (const std::exception &e) {
		double_str = COLOR_RED "impossible" COLOR_RESET;
	}
	return double_str;
}

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

std::string ScalarConverter::get_out_of_range_value(const std::string &num_str) {
	std::string value;

	if (has_negative_exponent(num_str)) {
		if (num_str[0] == '-') {
			value = "-0.0";
		} else {
			value = "0.0";
		}
	} else {
		if (num_str[0] == '-') {
			value = "-inf";
		} else {
			value = "inf";
		}
	}
	return value;
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
	int		int_num, base_num;
	size_t	idx;
	std::string endstr;

	*err = true;

	try {
		base_num = is_hex(num_str) ? 16 : 10;
		int_num = std::stoi(num_str, &idx, base_num);
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

bool ScalarConverter::is_char_literal(const std::string &num_str) {
	if (num_str.size() != 3) {
		return false;
	}
	return num_str[0] == '\'' && isascii(num_str[1]) && num_str[2] == '\'';
}

std::string ScalarConverter::get_num_str(const std::string &str) {
	std::string num_str;
	std::ostringstream oss;

	if (is_char_literal(str)) {
		oss << static_cast<int>(str[1]);
		return oss.str();
	}
	num_str = remove_suffix_f(str);
	return (num_str);
}

std::string ScalarConverter::remove_suffix_f(const std::string &str) {
	size_t	f_pos;
	std::string removed_str;

	if (str.empty() || is_hex(str)) {
		return (str);
	}
	if (str == "inf" || str == "+inf" || str == "-inf") {
		return (str);
	}
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
