#include <climits>
#include <exception>
#include <iostream>
#include <set>
#include "Span.hpp"

int main() {
	{
		std::cout << "-------------------- subject --------------------" << std::endl;
		try {
			Span span(5);
			std::cout << span << std::endl;

			span.addNumber(6);
			std::cout << span << std::endl;

			span.addNumber(3);
			std::cout << span << std::endl;

			span.addNumber(17);
			std::cout << span << std::endl;

			span.addNumber(9);
			std::cout << span << std::endl;

			span.addNumber(11);
			std::cout << span << std::endl;

			std::cout << " shortestSpan:" << span.shortestSpan() << std::endl;
			std::cout << " longestSpan:" << span.longestSpan() << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------- test --------------------" << std::endl;
		try {
			Span span(10);
			std::cout << span << std::endl;

			span.addNumber(1);
			std::cout << span << std::endl;

			span.addNumber(2);
			std::cout << span << std::endl;

			span.addNumber(10);
			std::cout << span << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------- test --------------------" << std::endl;
		try {
			Span span(0);
			std::cout << span << std::endl;

			span.addNumber(1);
			std::cout << span << std::endl;

			span.addNumber(2);
			std::cout << span << std::endl;

			span.addNumber(10);
			std::cout << span << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------- test --------------------" << std::endl;
		try {
			Span span(1);
			std::cout << span << std::endl;

			span.addNumber(1);
			std::cout << span << std::endl;

			span.addNumber(1);
			std::cout << span << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------- test --------------------" << std::endl;
		try {
			Span span(10);
			std::cout << span << std::endl;

			for (int i = 0; i < 100; ++i) {
				span.addNumber(1);
			}
			std::cout << span << std::endl;

			span.addNumber(10);
			std::cout << span << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "-------------------- test --------------------" << std::endl;
		try {
			Span span(10);
			std::cout << span << std::endl;

			span.addNumber(0);
			std::cout << span << std::endl;

			span.addNumber(INT_MIN);
			std::cout << span << std::endl;

			span.addNumber(INT_MAX);
			std::cout << span << std::endl;

			span.addNumber(INT_MAX - 1);
			std::cout << span << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "-------------------- copy assignment --------------------" << std::endl;
		try {
			Span sp1(10);

			sp1.addNumber(0);
			sp1.addNumber(1);
			sp1.addNumber(2);

			Span sp2 = sp1;

			sp1.addNumber(42);
			sp2.addNumber(-42);

			std::cout << "sp1:" << sp1 << std::endl;
			std::cout << "sp2:" << sp2 << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------- copy constructor --------------------" << std::endl;
		try {
			Span sp1(10);

			sp1.addNumber(0);
			sp1.addNumber(1);
			sp1.addNumber(2);

			Span sp2 = Span(sp1);

			sp1.addNumber(42);
			sp2.addNumber(-42);

			std::cout << " sp1:" << sp1 << std::endl;
			std::cout << " sp2:" << sp2 << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------- addRangeNumber --------------------" << std::endl;
		{
			std::cout << " 1) range(0, 9)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, 9);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 2) range(0, 10)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, 10);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 3) range(0, 11)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, 11);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 4) range(0, 10, 0)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, 10, 0);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 5) range(0, 10, -1)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, 10, -1);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}

		{
			std::cout << " 6) range(0, 1, INT_MAX)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, 1, INT_MAX);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 7) range(0, 0, 1)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, 0, 1);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 8) range(0, 0, -1)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, 0, -1);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 8) range(0, -5)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, -5);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 9) range(0, -5, -1)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, -5, -1);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 10) range(0, -5, 10)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, -5, -10);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 11) range(0, -5, -10)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, -5, -10);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 11) range(0, -5, INT_MIN)" << std::endl;
			try {
				Span sp(10);

				sp.addRangeNumber(0, -5, INT_MIN);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 12) range(0, 101, 2)" << std::endl;
			try {
				Span sp(100);

				sp.addRangeNumber(0, 101, 2);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 13) range(-100, 101, 2)" << std::endl;
			try {
				Span sp(101);

				sp.addRangeNumber(-100, 101, 2);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 14) range(INT_MIN + 10, INT_MIN, -1)" << std::endl;
			try {
				Span sp(100);

				sp.addRangeNumber(INT_MIN + 10, INT_MIN, -1);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 15) range(INT_MIN + 10, INT_MIN, -2)" << std::endl;
			try {
				Span sp(100);

				sp.addRangeNumber(INT_MIN + 10, INT_MIN, -2);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 16) range(INT_MIN + 10, INT_MIN, -100)" << std::endl;
			try {
				Span sp(100);

				sp.addRangeNumber(INT_MIN + 10, INT_MIN, -100);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 17) range(0, 10)" << std::endl;
			try {
				Span sp(1000001);

				sp.addRangeNumber(0, 11);

				std::cout << " sp:" << sp << std::endl;
			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 18) range(10, -1, -1)" << std::endl;
			try {
				Span sp(1000001);

				sp.addRangeNumber(10, -1, -1);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}

		{
			std::cout << " 19) range(0, -11 -1)" << std::endl;
			try {
				Span sp(1000001);

				sp.addRangeNumber(0, -11, -1);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 20) range(-10, 1)" << std::endl;
			try {
				Span sp(1000001);

				sp.addRangeNumber(-10, 1);
				std::cout << " sp:" << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 21) range(0, 100000)" << std::endl;
			try {
				Span sp(1000001);

				sp.addRangeNumber(0, 1000000);
				sp.addNumber(INT_MIN);

				std::cout << " shortestSpan:" << sp.shortestSpan() << std::endl;
				std::cout << " longestSpan:" << sp.longestSpan() << std::endl;
				std::cout << " size:" << sp.get_size() << std::endl;
			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << " 22) range(0, -1000000, -1)" << std::endl;
			try {
				Span sp(1000001);

				sp.addRangeNumber(0, -1000000, -1);
				sp.addNumber(INT_MAX);

				std::cout << " shortestSpan:" << sp.shortestSpan() << std::endl;
				std::cout << " longestSpan:" << sp.longestSpan() << std::endl;
				std::cout << " size:" << sp.get_size() << std::endl;
			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
	}
	return 0;
}

#ifdef __APPLE__

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}

#endif
