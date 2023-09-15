#include <climits>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <set>
#include "Span.hpp"

void test_subject() {
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

void test_copy() {
	{
		std::cout << "-------------------- default constructor --------------------" << std::endl;
		try {
			Span sp1;
			Span sp2 = Span();

			std::cout << " sp1:" << sp1 << std::endl;
			std::cout << " sp2:" << sp2 << std::endl;

			std::cout << "sp1.add(1)" << std::endl;
			sp1.addNumber(1);

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
}

void test_simple() {
	{
		std::cout << "-------------------- test --------------------" << std::endl;
		try {
			std::cout << CYAN "span(10)" RESET << std::endl;
			Span span(10);
			std::cout << span << std::endl;

			std::cout << CYAN "add(1)" RESET << std::endl;
			span.addNumber(1);
			std::cout << span << std::endl;

			std::cout << CYAN "add(2)" RESET << std::endl;
			span.addNumber(2);
			std::cout << span << std::endl;

			std::cout << CYAN "add(10)" RESET << std::endl;
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
			std::cout << CYAN "span(0)" RESET << std::endl;
			Span span(0);
			std::cout << span << std::endl;

			std::cout << CYAN "add(1)" RESET << std::endl;
			span.addNumber(1);
			std::cout << span << std::endl;

			std::cout << CYAN "add(2)" RESET << std::endl;
			span.addNumber(2);
			std::cout << span << std::endl;

			std::cout << CYAN "add(10)" RESET << std::endl;
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
			std::cout << CYAN "span(1)" RESET << std::endl;
			Span span(1);
			std::cout << span << std::endl;

			std::cout << CYAN "add(1)" RESET << std::endl;
			span.addNumber(1);
			std::cout << span << std::endl;

			std::cout << CYAN "add(1)" RESET << std::endl;
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
			std::cout << CYAN "span(10)" RESET << std::endl;
			Span span(10);
			std::cout << span << std::endl;

			std::cout << CYAN "add(1) x 100" RESET << std::endl;
			for (int i = 0; i < 100; ++i) {
				span.addNumber(1);
			}
			std::cout << span << std::endl;

			std::cout << CYAN "add(10)" RESET << std::endl;
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
			std::cout << CYAN "span(10)" RESET << std::endl;
			Span span(10);
			std::cout << span << std::endl;

			std::cout << CYAN "add(0)" RESET << std::endl;
			span.addNumber(0);
			std::cout << span << std::endl;

			std::cout << CYAN "add(INT_MIN)" RESET << std::endl;
			span.addNumber(INT_MIN);
			std::cout << span << std::endl;

			std::cout << CYAN "add(INT_MAX)" RESET << std::endl;
			span.addNumber(INT_MAX);
			std::cout << span << std::endl;

			std::cout << CYAN "add(INT_MAX - 1)" RESET << std::endl;
			span.addNumber(INT_MAX - 1);
			std::cout << span << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}

void test_add_numbers() {
	std::cout << "-------------------- addNumbers --------------------" << std::endl;
	{
		std::cout << " 1) addNumbers(const int *start, const int *stop)" << std::endl;
		{
			std::cout << CYAN " 1-1) sp([1, 2, 3, 4, 5])" RESET << std::endl;

			try {
				std::cout << CYAN "  int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(values, values + 5);" RESET << std::endl;
				std::cout << std::endl;
				int values[] = {1, 2, 3, 4, 5};
				Span sp(10);

				sp.addNumbers(values, values + 5);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << CYAN " 1-2) sp(const [1, 2, 3, 4, 5])" RESET << std::endl;
			try {
				std::cout << CYAN "  const int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(values, values + 5);" RESET << std::endl;
				std::cout << std::endl;

				const int values[] = {1, 2, 3, 4, 5};
				Span sp(10);

				sp.addNumbers(values, values + 5);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << CYAN " 1-3) sp([1, 2, 3, 4, 5])" RESET << std::endl;

			try {
				std::cout << CYAN "  int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(values, values);" RESET << std::endl;
				std::cout << std::endl;

				const int values[] = {1, 2, 3, 4, 5};
				Span sp(10);

				sp.addNumbers(values, values);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		{
			std::cout << CYAN " 1-4) invalid addNumbers" RESET << std::endl;

			try {
				std::cout << CYAN "  int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(values + 5, values);" RESET << std::endl;
				std::cout << std::endl;

				const int values[] = {1, 2, 3, 4, 5};
				Span sp(10);

				sp.addNumbers(values + 5, values);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << " 2) addNumbers(deque)" << std::endl;
		{
			std::cout << CYAN " 2-1) sp([1, 2, 3, 4, 5])" RESET << std::endl;

			try {
				std::cout << CYAN "  int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  std::deque<int> dq(values, values + 5);" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(deque);" RESET << std::endl;
				std::cout << std::endl;

				int values[] = {1, 2, 3, 4, 5};
				std::deque<int> dq(values, values + 5);
				Span sp(10);

				sp.addNumbers(dq);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << CYAN " 2-2) sp(const [1, 2, 3, 4, 5])" RESET << std::endl;

			try {
				std::cout << CYAN "  const int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  const std::deque<int> dq(values, values + 5);" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(deque);" RESET << std::endl;
				std::cout << std::endl;

				const int values[] = {1, 2, 3, 4, 5};
				const std::deque<int> dq(values, values + 5);
				Span sp(10);

				sp.addNumbers(dq);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << CYAN " 2-3) empty container" RESET << std::endl;

			try {
				std::cout << CYAN "  int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  std::deque<int> dq;" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(deque);" RESET << std::endl;
				std::cout << std::endl;

				std::deque<int> dq;
				Span sp(10);

				sp.addNumbers(dq);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << " 3) addNumbers(forward_list)" << std::endl;
		std::cout << "delete: C++11" << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " 4) addNumbers(list)" << std::endl;
		{
			std::cout << CYAN " 4-1) sp([1, 2, 3, 4, 5])" RESET << std::endl;

			try {
				std::cout << CYAN "  int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  std::list<int> lst(values, values + 5);" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(lst);" RESET << std::endl;
				std::cout << std::endl;

				int values[] = {1, 2, 3, 4, 5};
				std::list<int> lst(values, values + 5);
				Span sp(10);

				sp.addNumbers(lst);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << CYAN " 4-2) sp(const [1, 2, 3, 4, 5])" RESET << std::endl;

			try {
				std::cout << CYAN "  const int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  const std::list<int> lst(values, values + 5);" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(lst);" RESET << std::endl;
				std::cout << std::endl;

				const int values[] = {1, 2, 3, 4, 5};
				const std::list<int> lst(values, values + 5);
				Span sp(10);

				sp.addNumbers(lst);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << CYAN " 4-3) empty container" RESET << std::endl;

			try {
				std::cout << CYAN "  int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  std::list<int> lst;" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(lst);" RESET << std::endl;
				std::cout << std::endl;

				std::list<int> lst;
				Span sp(10);

				sp.addNumbers(lst);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << " 5) addNumbers(set)" << std::endl;
		{
			std::cout << CYAN " 5-1) sp([1, 2, 3, 4, 5])" RESET << std::endl;

			try {
				std::cout << CYAN "  int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  std::set<int> st(values, values + 5);" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(st);" RESET << std::endl;
				std::cout << std::endl;

				int values[] = {1, 2, 3, 4, 5};
				std::set<int> st(values, values + 5);
				Span sp(10);

				sp.addNumbers(st);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << CYAN " 5-2) sp(const [1, 2, 3, 4, 5])" RESET << std::endl;

			try {
				std::cout << CYAN "  const int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  const std::set<int> st(values, values + 5);" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(st);" RESET << std::endl;
				std::cout << std::endl;

				const int values[] = {1, 2, 3, 4, 5};
				const std::set<int> st(values, values + 5);
				Span sp(10);

				sp.addNumbers(st);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << CYAN " 5-3) empty container" RESET << std::endl;

			try {
				std::cout << CYAN "  int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  std::set<int> st;" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(st);" RESET << std::endl;
				std::cout << std::endl;

				std::set<int> st;
				Span sp(10);

				sp.addNumbers(st);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << " 6) addNumbers(vector)" << std::endl;
		{
			std::cout << CYAN " 6-1) sp([1, 2, 3, 4, 5])" RESET << std::endl;

			try {
				std::cout << CYAN "  int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  std::vector<int> vec(values, values + 5);" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(vec);" RESET << std::endl;
				std::cout << std::endl;

				int values[] = {1, 2, 3, 4, 5};
				std::vector<int> vec(values, values + 5);
				Span sp(10);

				sp.addNumbers(vec);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << CYAN " 6-2) sp(const [1, 2, 3, 4, 5])" RESET << std::endl;

			try {
				std::cout << CYAN "  const int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  const std::vector<int> vec(values, values + 5);" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(vec);" RESET << std::endl;
				std::cout << std::endl;

				const int values[] = {1, 2, 3, 4, 5};
				const std::vector<int> vec(values, values + 5);
				Span sp(10);

				sp.addNumbers(vec);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << CYAN " 6-3) empty container" RESET << std::endl;

			try {
				std::cout << CYAN "  int values[] = {1, 2, 3, 4, 5};" RESET << std::endl;
				std::cout << CYAN "  std::vector<int> vec;" RESET << std::endl;
				std::cout << CYAN "  Span sp(10);" RESET << std::endl;
				std::cout << CYAN "  sp.addNumbers(vec);" RESET << std::endl;
				std::cout << std::endl;

				std::vector<int> vec;
				Span sp(10);

				sp.addNumbers(vec);

				std::cout << sp << std::endl;

			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

void test_add_range_numbers() {
	std::cout << "-------------------- addRangeNumber --------------------" << std::endl;
	{
		std::cout << CYAN " 1) range(0, 9)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, 9);" RESET << std::endl;
			sp.addRangeNumber(0, 9);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 2) range(0, 10)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, 10);" RESET << std::endl;
			sp.addRangeNumber(0, 10);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 3) range(0, 11)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, 11);" RESET << std::endl;
			try {
				sp.addRangeNumber(0, 11);
			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 4) range(0, 10, 0), invalid argument" RESET << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, 10, 0);" RESET << std::endl;
			sp.addRangeNumber(0, 10, 0);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 5) range(0, 10, -1), invalid argument" RESET << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, 10, -1);" RESET << std::endl;
			sp.addRangeNumber(0, 10, -1);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN " 6) range(0, 1, INT_MAX)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, 1, INT_MAX);" RESET << std::endl;
			sp.addRangeNumber(0, 1, INT_MAX);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 7) range(0, 0, 1)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, 0, 1);" RESET << std::endl;
			sp.addRangeNumber(0, 0, 1);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 8) range(0, 0, -1)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, 0, -1);" RESET << std::endl;
			sp.addRangeNumber(0, 0, -1);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 8) range(0, -5), invalid argument" RESET << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, -5);" RESET << std::endl;
			sp.addRangeNumber(0, -5);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 9) range(0, -5, -1)" << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, -5, -1);" RESET << std::endl;
			sp.addRangeNumber(0, -5, -1);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 10) range(0, -5, 10)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, -5, -10);" RESET << std::endl;
			sp.addRangeNumber(0, -5, -10);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 11) range(0, -5, -10)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, -5, -10);" RESET << std::endl;
			sp.addRangeNumber(0, -5, -10);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 11) range(0, -5, INT_MIN)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(10)" RESET << std::endl;
			Span sp(10);

			std::cout << CYAN " sp.addRangeNumber(0, -5, INT_MIN);" RESET << std::endl;
			sp.addRangeNumber(0, -5, INT_MIN);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 12) range(0, 101, 2)" RESET << std::endl;
		try {
			Span sp(100);

			std::cout << CYAN " sp.addRangeNumber(0, 101, 2);" RESET << std::endl;
			sp.addRangeNumber(0, 101, 2);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 13) range(-100, 101, 2)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(101)" RESET << std::endl;
			Span sp(101);

			std::cout << CYAN " sp.addRangeNumber(-100, 101, 2);" RESET << std::endl;
			sp.addRangeNumber(-100, 101, 2);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 14) range(INT_MIN + 10, INT_MIN, -1)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(100)" RESET << std::endl;
			Span sp(100);

			std::cout << CYAN " sp.addRangeNumber(INT_MIN + 10, INT_MIN, -1);" RESET << std::endl;
			sp.addRangeNumber(INT_MIN + 10, INT_MIN, -1);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 15) range(INT_MIN + 10, INT_MIN, -2)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(100)" RESET << std::endl;
			Span sp(100);

			std::cout << CYAN " sp.addRangeNumber(INT_MIN + 10, INT_MIN, -1);" RESET << std::endl;
			sp.addRangeNumber(INT_MIN + 10, INT_MIN, -2);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 16) range(INT_MIN + 10, INT_MIN, -100)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(100)" RESET << std::endl;
			Span sp(100);

			std::cout << CYAN " sp.addRangeNumber(INT_MIN + 10, INT_MIN, -100);" RESET << std::endl;
			sp.addRangeNumber(INT_MIN + 10, INT_MIN, -100);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 17) range(0, 10)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(100)" RESET << std::endl;
			Span sp(100);

			std::cout << CYAN " sp.addRangeNumber(0, 11);" RESET << std::endl;
			sp.addRangeNumber(0, 11);

			std::cout << " sp:" << sp << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 18) range(10, -1, -1)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(100)" RESET << std::endl;
			Span sp(100);

			std::cout << CYAN " sp.addRangeNumber(10, -1, -1);" RESET << std::endl;
			sp.addRangeNumber(10, -1, -1);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << CYAN " 19) range(0, -11 -1)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(100)" RESET << std::endl;
			Span sp(100);

			std::cout << CYAN " sp.addRangeNumber(0, -11, -1);" RESET << std::endl;
			sp.addRangeNumber(0, -11, -1);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 20) range(-10, 1)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(100)" RESET << std::endl;
			Span sp(100);

			std::cout << CYAN " sp.addRangeNumber(-10, 1);" RESET << std::endl;
			sp.addRangeNumber(-10, 1);
			std::cout << " sp:" << sp << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 21) range(0, 100000)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(1000001)" RESET << std::endl;
			Span sp(1000001);

			std::cout << CYAN " sp.addRangeNumber(0, 1000000);" RESET << std::endl;
			sp.addRangeNumber(0, 1000000);

			std::cout << CYAN " sp.addNumber(INT_MIN);" RESET << std::endl;
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
		std::cout << CYAN " 22) range(0, -1000000, -1)" RESET << std::endl;
		try {
			std::cout << CYAN " sp(1000001)" RESET << std::endl;
			Span sp(1000001);

			std::cout << CYAN " sp.addRangeNumber(0, -1000000, -1);" RESET << std::endl;
			sp.addRangeNumber(0, -1000000, -1);

			std::cout << CYAN " sp.addNumber(INT_MAX);" RESET << std::endl;
			sp.addNumber(INT_MAX);

			std::cout << " shortestSpan:" << sp.shortestSpan() << std::endl;
			std::cout << " longestSpan:" << sp.longestSpan() << std::endl;
			std::cout << " size:" << sp.get_size() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void test_many_numbers() {
	{
		std::cout << CYAN " 1) 10,000 numbers" RESET << std::endl;
		try {
			std::cout << CYAN " std::vector<int> vec" RESET << std::endl;
			std::vector<int> vec;

			std::cout << CYAN " add random 10,000 values" RESET << std::endl;
			for (int i = 0; i < 10000; ++i) {
				vec.push_back(rand());
			}

			std::cout << CYAN " sp(10010)" RESET << std::endl;
			Span sp(10010);

			std::cout << CYAN " sp.addNumbers(vec)" RESET << std::endl;
			sp.addNumbers(vec);

			std::cout << " SPAN INFO" << std::endl;
			std::cout << "  size:" << sp.get_size() << std::endl;
			std::cout << "  min :" << sp.shortestSpan() << std::endl;
			std::cout << "  max :" << sp.longestSpan() << std::endl;
			std::cout << std::endl;

			std::cout << CYAN " sp.add(INT_MIN, INT_MAX, INT_MAX - 1)" RESET << std::endl;
			sp.addNumber(INT_MIN);
			sp.addNumber(INT_MAX);
			sp.addNumber(INT_MAX - 1);

			std::cout << " SPAN INFO" << std::endl;
			std::cout << "  size:" << sp.get_size() << std::endl;
			std::cout << "  min :" << sp.shortestSpan() << std::endl;
			std::cout << "  max :" << sp.longestSpan() << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 2) 100,000 numbers" RESET << std::endl;
		try {
			std::cout << CYAN " std::vector<int> vec" RESET << std::endl;
			std::vector<int> vec;

			std::cout << CYAN " add random 100,000 values" RESET << std::endl;
			for (int i = 0; i < 100000; ++i) {
				vec.push_back(rand());
			}

			std::cout << CYAN " sp(100010)" RESET << std::endl;
			Span sp(100010);
			std::cout << CYAN " sp.addNumbers(vec)" RESET << std::endl;
			sp.addNumbers(vec);

			std::cout << " SPAN INFO" << std::endl;
			std::cout << "  size:" << sp.get_size() << std::endl;
			std::cout << "  min :" << sp.shortestSpan() << std::endl;
			std::cout << "  max :" << sp.longestSpan() << std::endl;
			std::cout << std::endl;

			std::cout << CYAN " sp.add(INT_MIN, INT_MAX, INT_MAX - 1)" RESET << std::endl;
			sp.addNumber(INT_MIN);
			sp.addNumber(INT_MAX);
			sp.addNumber(INT_MAX - 1);

			std::cout << " SPAN INFO" << std::endl;
			std::cout << "  size:" << sp.get_size() << std::endl;
			std::cout << "  min :" << sp.shortestSpan() << std::endl;
			std::cout << "  max :" << sp.longestSpan() << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << CYAN " 3) 1000,000 numbers" RESET << std::endl;
		try {
			std::cout << CYAN " std::vector<int> vec" RESET << std::endl;
			std::vector<int> vec;

			std::cout << CYAN " add random 1000,000 values" RESET << std::endl;
			for (int i = 0; i < 1000000; ++i) {
				vec.push_back(rand());
			}

			std::cout << CYAN " sp(1000010)" RESET << std::endl;
			Span sp(1000010);
			std::cout << CYAN " sp.addNumbers(vec)" RESET << std::endl;
			sp.addNumbers(vec);

			std::cout << " SPAN INFO" << std::endl;
			std::cout << "  size:" << sp.get_size() << std::endl;
			std::cout << "  min :" << sp.shortestSpan() << std::endl;
			std::cout << "  max :" << sp.longestSpan() << std::endl;
			std::cout << std::endl;

			std::cout << CYAN " sp.add(INT_MIN, INT_MAX, INT_MAX - 1)" RESET << std::endl;
			sp.addNumber(INT_MIN);
			sp.addNumber(INT_MAX);
			sp.addNumber(INT_MAX - 1);

			std::cout << " SPAN INFO" << std::endl;
			std::cout << "  size:" << sp.get_size() << std::endl;
			std::cout << "  min :" << sp.shortestSpan() << std::endl;
			std::cout << "  max :" << sp.longestSpan() << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}

int main() {
	srand(time(NULL));
	test_subject();
	test_copy();
	test_simple();
	test_add_numbers();
	test_add_range_numbers();
	test_many_numbers();
	return 0;
}

#ifdef __APPLE__

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}

#endif
