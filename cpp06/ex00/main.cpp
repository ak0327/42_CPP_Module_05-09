#include <climits>
#include <cfloat>
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

#ifndef DEBUG

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "[Error] invalid argument. Input: ./convert <char/int/float/double literal>" << std::endl;
		return 1;
 	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

#else

void test(const std::string &str) {

	std::cout.setf(std::ios::left);
	std::cout << "[" << str << "]" << std::endl;
	ScalarConverter::convert(str);
	std::cout << std::endl;
}

int main() {

	std::cout << "====================== SUCCESS ======================" << std::endl;
	test("0");
	test("+0");
	test("-0");
	test(".0");
	test("-.0");
	test(".0f");
	test("0.");
	test("0.f");

	std::cout << "-------------------------------------" << std::endl;

	test("' '");
	test("'*'");
	test("'-'");
	test("'1'");
	test("'9'");
	test("'A'");
	test("'a'");
	test("'~'");

	std::cout << "-------------------------------------" << std::endl;

	test("31");
	test("32");
	test("90");
	test("126");
	test("127");
	test("128");

	std::cout << "-------------------------------------" << std::endl;

	test("42.0f");
	test("42.1");
	test("42.9");

	std::cout << "-------------------------------------" << std::endl;

	test("inf");
	test("inff");
	test("+inf");
	test("+inff");
	test("-inf");
	test("-inff");
	test("nan");
	test("nanf");

	std::cout << "-------------------------------------" << std::endl;

	test("-1.0");

	test("255");
	test("256");

	test("10000.f");
	test("10000.00");

	test("2147483647");
	test("2147483648"); // impossible
	test("2147483648f");
	test("2147483648.0");
	test("-2147483648");
	test("-2147483649"); // impossible
	test("-2147483649f");
	test("-2147483649.0");

	test("1E+1000");  // inf
	test("-1E1000");  // -inf
	test("1E-1000");  // 0.0
	test("-1E-1000");  // -0.0
	test("0E+0000");  // 0.0

	test("3.402823e+38");
	test("-3.402823e+38");
	test("1.797693e+308");
	test("-1.797693e+308");

	std::cout << std::endl;
	std::cout << "======================  NG ====================== " << std::endl;

	test("hoge");
	test("42.xx");
	test("INT_MAX");
	test("42.0ff");
	test("ff");
	test("ff.0");
	test("..42");
	test("-1E--1000");
	test(" +-1E--1000");
	test("1E-100.0");
	test("1E-10.00");
	test("1E-10.");
	test("0x");
	test("-.-0");
	test("-+.-0");
	test("");
	test(" ");
	test("  ");
	test(" +0");
	test("  100");
	test(" +0 ");
	test("+0 ");
	test("a");
	test("-");
	test("*");
	test("~");
	test(" 'a'");
	test("0x12");
	test("0X12");
	test("0x5f");
	test("0xff");
	test("0xFF");

	std::cout << std::endl;
	return 0;
}

#endif