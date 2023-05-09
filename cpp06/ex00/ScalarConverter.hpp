#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>

#define SETW 10

//todo: static class ScalarConverter
class ScalarConverter {
public:
	// staticメンバはオブジェクトを生成せずに利用できるため、staticクラスはインスタンス化の必要性がない
//	ScalarConverter(const ScalarConverter &scalarConverter);
//	~ScalarConverter();
//	ScalarConverter &operator=(const ScalarConverter &scalarConverter);

	static void		convert(std::string &str);
	static void		convert_to_char(std::string &num_str);
	static void		convert_to_int(std::string &num_str);
	static void		convert_to_float(std::string &num_str);
	static void		convert_to_double(std::string &num_str);

private:
	// staticクラスはインスタンス化が必要ないため、インスタンス化を禁止
	ScalarConverter();
	~ScalarConverter();

	static std::string get_num_str(std::string &str);
	static std::string &space_trim(std::string &str);
	static std::string &remove_suffix_f(std::string &str);

	static int convert_str_to_int(std::string &num_str, bool *err);
	static size_t ft_strlen_ns(char *s);
	static bool is_digit_after_decimal_point(const char *s);

	static size_t count_chr_in_str(const char chr, const std::string str);

	static bool is_pos_inf(std::string &str);
	static bool is_neg_inf(std::string &str);
	static bool is_nan(std::string &str);

};