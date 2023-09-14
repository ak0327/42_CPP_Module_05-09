#include <climits>
#include <iostream>
#include <deque>
#include <list>
#include <set>
#include <vector>
#include "easyfind.hpp"

#define OK	1
#define KO	0

template <typename T>
void display_input(const T &container, int value) {
	typename T::const_iterator itr;
	typename T::const_iterator next;

	std::cout << "data:[";
	for (itr = container.begin(); itr != container.end(); ++itr) {
		std::cout << *itr;
		next = itr;
		if (++next != container.end()) {
			std::cout << ", ";
		}
	}
	std::cout << "], value:" << value << std::endl;
}

template <typename T>
size_t get_size(const T &container) {
	size_t size = 0;
	typename T::const_iterator itr;

	for (itr = container.begin(); itr != container.end(); ++itr) {
		size++;
	}
	return size;
}

template <typename T>
int test(const T &container, int value, bool expected_find, int test_count) {
	int result;

	std::cout << " TEST No." << test_count << ", ";

	if (get_size(container) < 1000) {
		display_input(container, value);
	} else {
		std::cout << "data:[ ... ], value:" << value << std::endl;
	}

	try {
		typename T::const_iterator itr = easyfind(container, value);

		if (expected_find) {
			std::cout << "  value found: *itr=" << *itr << std::endl;
			result = OK;
		} else {
			result = KO;
		}
	} catch (const std::exception &e) {
		std::cout << "  value not found: " << e.what() << std::endl;
		if (!expected_find) {
			result = OK;
		} else {
			result = KO;
		}
	}

	std::cout << "  Result : ";
	if (result == OK) {
		std::cout << COLOR_GREEN "OK" COLOR_RESET << std::endl;
	} else {
		std::cout << COLOR_RED "KO" COLOR_RESET << std::endl;
	}
	return result;
}

template <typename T>
int test(T &container, int value, bool expected_find, int test_count) {
	int result;

	std::cout << " TEST No." << test_count << ", ";

	if (get_size(container) < 1000) {
		display_input(container, value);
	} else {
		std::cout << "data:[ ... ], value:" << value << std::endl;
	}

	try {
		typename T::iterator itr = easyfind(container, value);

		if (expected_find && *itr == value) {
			std::cout << "  value found: *itr=" << *itr << std::endl;
			result = OK;
		} else {
			result = KO;
		}
	} catch (const std::exception &e) {
		std::cout << "  value not found: " << e.what() << std::endl;
		if (!expected_find) {
			result = OK;
		} else {
			result = KO;
		}
	}

	std::cout << "  Result : ";
	if (result == OK) {
		std::cout << COLOR_GREEN "OK" COLOR_RESET << std::endl;
	} else {
		std::cout << COLOR_RED "KO" COLOR_RESET << std::endl;
	}
	return result;
}

int main() {
	int ok = 0;
	int test_count = 0;
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "   [1] deque" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		{
			int data[] = {1, 2, 3};
			std::deque<int> dq(data, data + 3);

			ok += test(dq, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			std::deque<int> dq(data, data + 3);

			ok += test(dq, -1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 1, 1};
			std::deque<int> dq(data, data + 3);

			ok += test(dq, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			std::deque<int> dq;

			ok += test(dq, 1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			const std::deque<int> dq(data, data + 3);

			ok += test(dq, 1, true, ++test_count);
			std::cout << std::endl;
		}
		std::cout << std::endl;
		{
			std::deque<int> dq;
			for (int i = 0; i < 10001; ++i) {
				dq.push_back(i);
			}

			ok += test(dq, 10000, true, ++test_count);
			std::cout << std::endl;
		}
		std::cout << std::endl;
		{
			std::deque<int> dq;
			for (int i = 0; i < 10001; ++i) {
				dq.push_back(i);
			}

			ok += test(dq, INT_MAX, false, ++test_count);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "   [2] list" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		{
			int data[] = {1, 2, 3};
			std::list<int> ls(data, data + 3);

			ok += test(ls, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			std::list<int> ls(data, data + 3);

			ok += test(ls, -1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 1, 1};
			std::list<int> ls(data, data + 3);

			ok += test(ls, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			std::list<int> ls;

			ok += test(ls, 1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			const std::list<int> ls(data, data + 3);

			ok += test(ls, 1, true, ++test_count);
			std::cout << std::endl;
		}
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "   [3] set" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		{
			int data[] = {1, 2, 3};
			std::set<int> st(data, data + 3);

			ok += test(st, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			std::set<int> st(data, data + 3);

			ok += test(st, -1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 1, 1};
			std::set<int> st(data, data + 3);

			ok += test(st, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			std::set<int> st;

			ok += test(st, 1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			const std::set<int> st(data, data + 3);

			ok += test(st, 1, true, ++test_count);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "   [4] vector" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		{
			int data[] = {1, 2, 3};
			std::vector<int> vec(data, data + 3);

			ok += test(vec, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			std::vector<int> vec(data, data + 3);

			ok += test(vec, -1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 1, 1};
			std::vector<int> vec(data, data + 3);

			ok += test(vec, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			std::vector<int> vec;

			ok += test(vec, 1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			const std::vector<int> vec(data, data + 3);

			ok += test(vec, 1, true, ++test_count);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "===============================================" << std::endl;
	std::cout << "        RESULT: OK " << ok << " / ALL " << test_count << std::endl;
	std::cout << "                                    -> " <<
	(ok == test_count ? COLOR_GREEN "ALL OK" COLOR_RESET :  COLOR_RED "KO" COLOR_RESET) << std::endl;
	std::cout << "===============================================" << std::endl;
	return 0;
}

#ifdef __APPLE__

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}

#endif
