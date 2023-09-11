#include <iostream>
#include "whatever.hpp"

int main(void) {
	{
		std::cout << "-------------------- subject --------------------" << std::endl;
		int a = 2;
		int b = 3;

		::swap( a, b );

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::cout << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

		std::cout << std::endl;
	}
	{
		std::cout << "-------------------- different value --------------------" << std::endl;
		long a = 10;
		long b = 1;

		std::cout << "1) before swap:" << std::endl;
		std::cout << "  a:" << a << ", &a:" << &a << std::endl;
		std::cout << "  b:" << b << ", &b:" << &b << "\n" << std::endl;
 		::swap(a, b);
		std::cout << "2) after swap:" << std::endl;
		std::cout << "  a:" << a << ", &a:" << &a << std::endl;
		std::cout << "  b:" << b << ", &b:" << &b << "\n" <<  std::endl;

		std::cout << "min(a, b):" << ::min(a, b) << ", &min(a,b):" << &::min(a, b) << std::endl;
		std::cout << "max(a, b):" << ::max(a, b) << ", &max(a,b):" << &::max(a, b) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------- same value --------------------" << std::endl;
		long a = 10;
		long b = 10;

		std::cout << "1) before swap:" << std::endl;
		std::cout << "  a:" << a << ", &a:" << &a << std::endl;
		std::cout << "  b:" << b << ", &b:" << &b << "\n" << std::endl;
		::swap(a, b);
		std::cout << "2) after swap:" << std::endl;
		std::cout << "  a:" << a << ", &a:" << &a << std::endl;
		std::cout << "  b:" << b << ", &b:" << &b << "\n" <<  std::endl;

		std::cout << "min(a, b):" << ::min(a, b) << ", &min(a,b):" << &::min(a, b) << std::endl;
		std::cout << "max(a, b):" << ::max(a, b) << ", &max(a,b):" << &::max(a, b) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------- double --------------------" << std::endl;
		double a = -1;
		double b = 42;

		std::cout << "1) before swap:" << std::endl;
		std::cout << "  a:" << a << ", &a:" << &a << std::endl;
		std::cout << "  b:" << b << ", &b:" << &b << "\n" << std::endl;
		::swap(a, b);
		std::cout << "2) after swap:" << std::endl;
		std::cout << "  a:" << a << ", &a:" << &a << std::endl;
		std::cout << "  b:" << b << ", &b:" << &b << "\n" <<  std::endl;

		std::cout << "min(a, b):" << ::min(a, b) << ", &min(a,b):" << &::min(a, b) << std::endl;
		std::cout << "max(a, b):" << ::max(a, b) << ", &max(a,b):" << &::max(a, b) << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
