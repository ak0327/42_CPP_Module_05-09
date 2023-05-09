#include "ScalarConverter.hpp"

#define COLOR_RED		"\x1b[31m"
#define COLOR_GREEN		"\x1b[32m"
#define COLOR_YELLOW	"\x1b[33m"
#define COLOR_BLUE		"\x1b[34m"
#define COLOR_MAGENTA	"\x1b[35m"
#define COLOR_CYAN		"\x1b[36m"
#define COLOR_RESET		"\x1b[0m"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string &str) {
	std::string num_str;

	num_str = get_num_str(str);

//	std::cout << "num_str:" << num_str << std::endl;

	convert_to_char(num_str);
	convert_to_int(num_str);
	convert_to_float(num_str);
	convert_to_double(num_str);
}


void ScalarConverter::convert_to_char(std::string &num_str) {
	int		int_num;
	char 	chr;
	bool	is_convert_err;

	int_num = convert_str_to_int(num_str, &is_convert_err);
//	std::cout << "num_str:" << num_str << ", int_num:" << int_num << ", err:" << std::boolalpha << is_convert_err << std::endl;

	std::cout << std::setw(SETW) << "  char" << ": " << std::ends;
	chr = static_cast<char>(int_num);
	if (is_convert_err || !isascii(chr)) {
		std::cout << COLOR_RED"impossible"COLOR_RESET << std::endl;
		return ;
	}
	if (isprint(chr)) {
		std::cout << "'" << chr << "'" <<  std::endl;
	} else {
		std::cout << COLOR_YELLOW"Non displayable"COLOR_RESET << std::endl;
	}
}

void	ScalarConverter::convert_to_int(std::string &num_str) {
	int 	int_num;
	bool	is_convert_err;

	std::cout << std::setw(SETW) << "  int" << ": " << std::ends;

	int_num = convert_str_to_int(num_str, &is_convert_err);
	if (is_convert_err) {
		std::cout << COLOR_RED"impossible"COLOR_RESET << std::endl;
		return ;
	}
	std::cout << int_num << std::endl;
}

void	ScalarConverter::convert_to_float(std::string &num_str) {
	float	 float_num;
	size_t	idx;

	std::cout << std::setw(SETW) << "  float" << ": " << std::ends;
	try {
		float_num = std::stof(num_str, &idx);
	}
	catch (const std::exception &e) {
		std::cout << COLOR_RED"impossible"COLOR_RESET << std::endl;
		return ;
	}
	if (num_str[idx]) {
		std::cout << COLOR_RED"impossible"COLOR_RESET << std::endl;
	} else {
		std::cout << float_num << std::ends;

		if (std::isinf(float_num) || std::isnan(float_num)) {
			std::cout << std::endl;
			return ;
		}

		if (count_chr_in_str('.', num_str) == 0) {
			std::cout << ".0f" << std::endl;
		} else if (num_str.length() && num_str[num_str.length() - 1] == '.') {
			std::cout << "0f" << std::endl;
		} else {
			std::cout << "f" << std::endl;
		}

	}
}

// todo
// 0    -> 0.0f
// 0.1  -> 0.1f
// 10.1 -> 10.1f
// 10.  -> 10.0f
void	ScalarConverter::convert_to_double(std::string &num_str) {
	float	double_num;
	size_t	idx;

	std::cout << std::setw(SETW) << "  double" << ": " << std::ends;
	try {
		double_num = std::stod(num_str, &idx);
	}
	catch (const std::exception &e) {
		std::cout << COLOR_RED"impossible"COLOR_RESET << std::endl;
		return ;
	}

	if (num_str[idx]) {
		std::cout << COLOR_RED"impossible"COLOR_RESET << std::endl;
	} else {
		std::cout << double_num << "" << std::ends;

		if (std::isinf(double_num) || std::isnan(double_num)) {
			std::cout << std::endl;
			return ;
		}

		if (count_chr_in_str('.', num_str) == 0) {
			std::cout << ".0" << std::ends;
		} else if (num_str.length() && num_str[num_str.length() - 1] == '.') {
			std::cout << "0" << std::ends;
		}
		std::cout << std::endl;
	}
}


size_t ScalarConverter::ft_strlen_ns(char *s) {
	size_t i;

	i = 0;
	while (s && s[i]) {
		i++;
	}
	return i;
}


bool ScalarConverter::is_digit_after_decimal_point(const char *s) {
	size_t	i;

	if (!s || s[0] != '.') {
		return false;
	}
	i = 1;
	while (isdigit(s[i])) {
		i++;
	}
	if (s[i]) {
		return false;
	}
	return true;
}

int ScalarConverter::convert_str_to_int(std::string &num_str, bool *err) {
	long	lnum;
	char 	*end;


	*err = true;
	if (is_pos_inf(num_str) || is_neg_inf(num_str) || is_nan(num_str)) {
		return 0;
	}
	if (num_str.empty()) {
		return 0;
	}
	lnum = std::strtol(num_str.c_str(), &end, 10);
//	std::cout << "stol : lnum=" << lnum << ", end:" << end << std::endl;
	if (ft_strlen_ns(end) > 0 && !is_digit_after_decimal_point(end)) {
		return 0;
	}
	if (lnum < INT_MIN) {
		return INT_MIN;
	}
	if (INT_MAX < lnum) {
		return INT_MAX;
	}
	*err = false;
	return static_cast<int>(lnum);
}




std::string ScalarConverter::get_num_str(std::string &str) {
	std::string num_str;
	std::cout << "get_num_str:: [" << str << "] -> [" << std::ends;
	num_str = space_trim(str);
	num_str = remove_suffix_f(str);
	std::cout << num_str << "]" << std::endl;
	return (num_str);
}

std::string &ScalarConverter::space_trim(std::string &str) {
	const std::string space = " ";

	str.erase(str.find_last_not_of(space) + 1);
	str.erase(0, str.find_first_not_of(space));
	return (str);
}

std::string &ScalarConverter::remove_suffix_f(std::string &str) {
	size_t len;

	if (str == "inf" || str == "-inf")
		return (str);
	len = str.length();
	if (len == 0) {
		return (str);
	}
	if (str[len - 1] != 'f') {
		return (str);
	}
	str.resize(str.size() - 1);
	return (str);
}

size_t ScalarConverter::count_chr_in_str(const char chr, const std::string str) {
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (str[i]) {
		if (str[i] == chr) {
			cnt++;
		}
		i++;
	}
	return cnt;
}

bool ScalarConverter::is_pos_inf(std::string &str) {
	return (str == "inf" || str == "+inf" || str == "inff");
}

bool ScalarConverter::is_neg_inf(std::string &str) {
	return (str == "-inf" || str == "-inff");
}

bool ScalarConverter::is_nan(std::string &str) {
	return (str == "nan" || str == "nanf");
}