#pragma once

# include <cfloat>
# include <climits>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include "ScalarConverter.hpp"

# define PRECISION	1

template <typename T>
std::string convert_to_char_str(const T &val) {
	char chr_val;

	if (std::isnan(val) || std::isinf(val)) {
		return COLOR_RED "impossible" COLOR_RESET;
	}
	if (val < CHAR_MIN || CHAR_MAX < val) {
		return COLOR_RED "impossible" COLOR_RESET;
	}
	chr_val = static_cast<char>(val);
	if (isprint(chr_val)) {
		return "'" + std::string(1, chr_val) + "'";
	}
	return COLOR_YELLOW "Non displayable" COLOR_RESET;
}

template <typename T>
std::string convert_to_int_str(const T &val) {
	std::ostringstream oss;

	if (std::isnan(val) || std::isinf(val)) {
		return COLOR_RED "impossible" COLOR_RESET;
	}
	if (val < INT_MIN || INT_MAX < val) {
		return COLOR_RED "impossible" COLOR_RESET;
	}
	oss << static_cast<int>(val);
	return oss.str();
}

template <typename T>
std::string convert_to_float_str(const T &val) {
	std::ostringstream oss;
	float float_val;

	float_val = static_cast<float>(val);
	if (std::isinf(float_val)) {
		if (float_val < 0) {
			return "-inff";
		}
		return "inff";
	}
	if (std::isnan(float_val)) {
		return "nanf";
	}
	oss << std::fixed << std::setprecision(PRECISION) << float_val << "f";
	return oss.str();
}

template <typename T>
std::string convert_to_double_str(const T &val) {
	std::ostringstream oss;
	double double_val;

	double_val = static_cast<double>(val);
	if (std::isinf(double_val)) {
		if (double_val < 0) {
			return "-inf";
		}
		return "inf";
	}
	if (std::isnan(double_val)) {
		return "nan";
	}
	oss << std::fixed << std::setprecision(PRECISION) << double_val;
	return oss.str();
}

template <typename T>
void display_convert_result(const T &val) {

	std::cout << std::setw(SETW) << "  char" << ": " << convert_to_char_str(val) << std::endl;
	std::cout << std::setw(SETW) << "  int" << ": " << convert_to_int_str(val) << std::endl;
	std::cout << std::setw(SETW) << "  float" << ": " << convert_to_float_str(val) << std::endl;
	std::cout << std::setw(SETW) << "  double" << ": " << convert_to_double_str(val) << std::endl;
}
