#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

/* /////////////////////////
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
///////////////////////// */

// char:ascii code

// If a conversion does not make any sense or overflows,
// display a message to inform the user that the type conversion is impossible.

void test(std::string str) {

	std::cout.setf(std::ios::left);
	std::cout << "[" << str << "]" << std::endl;
	ScalarConverter::convert(str);
//	std::cout << std::setw(w) << "  char" << ": " <<  ScalarConverter::convert_to_char(str) << std::endl;
//	std::cout << std::setw(w) << "  int" << ": " <<  ScalarConverter::convert_to_int(str) << std::endl;
//	std::cout << std::setw(w) << "  float" << ": " <<  ScalarConverter::convert_to_float(str) << std::endl;
//	std::cout << std::setw(w) << "  double" << ": " << ScalarConverter::convert_to_double(str) << std::endl;
	std::cout << std::endl;
}

int main() {

	std::cout << "====================== SUCCESS ======================" << std::endl;
	test("0");
	test("nan");
	test("42.0f");
	std::cout << std::endl;
	test("10");
	test("1111111111111111111111111111111111111111111111111111111111111");
	test("inf");
	test("inff");
	test("+inf");
	test("+inff");
	test("-inf");
	test("-inff");
	test("nanf");
	test("   42   ");
	test(".0");
	test(".0f");
	test("0.");
	test("0.f");
	test("10000.f");
	test("10000.00");
	test("048");
	test("90.0");
	test("32.0000f");
	test("126.0000");


	std::cout << "\n\n" << std::endl;

	std::cout << "======================  NG ====================== " << std::endl;
	test("a");
	test("42.xx");
	test("");
	test("INT_MAX");

//	system("leaks convert");
	return 0;
}
