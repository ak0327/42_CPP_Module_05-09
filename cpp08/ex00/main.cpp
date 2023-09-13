#include <iostream>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
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
int test(const T &container, int value, bool expected_find, int test_count) {
	int result;

	std::cout << " TEST No." << test_count << ", ";

	display_input(container, value);

	try {
		int find_value = easyfind(container, value);

		if (expected_find && value == find_value) {
			std::cout << "  value found: " << value << std::endl;
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
			std::deque<int> dq(data, std::end(data));

			ok += test(dq, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			std::deque<int> dq(data, std::end(data));

			ok += test(dq, -1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 1, 1};
			std::deque<int> dq(data, std::end(data));

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
			const std::deque<int> dq(data, std::end(data));

			ok += test(dq, 1, true, ++test_count);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "   [2] forward_list" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		{
			int data[] = {1, 2, 3};
			std::forward_list<int> ls(data, std::end(data));

			ok += test(ls, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			std::forward_list<int> ls(data, std::end(data));

			ok += test(ls, -1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 1, 1};
			std::forward_list<int> ls(data, std::end(data));

			ok += test(ls, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			std::forward_list<int> ls;

			ok += test(ls, 1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			const std::forward_list<int> ls(data, std::end(data));

			ok += test(ls, 1, true, ++test_count);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "   [3] list" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		{
			int data[] = {1, 2, 3};
			std::list<int> ls(data, std::end(data));

			ok += test(ls, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			std::list<int> ls(data, std::end(data));

			ok += test(ls, -1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 1, 1};
			std::list<int> ls(data, std::end(data));

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
			const std::list<int> ls(data, std::end(data));

			ok += test(ls, 1, true, ++test_count);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "   [4] set" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		{
			int data[] = {1, 2, 3};
			std::set<int> st(data, std::end(data));

			ok += test(st, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			std::set<int> st(data, std::end(data));

			ok += test(st, -1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 1, 1};
			std::set<int> st(data, std::end(data));

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
			const std::set<int> st(data, std::end(data));

			ok += test(st, 1, true, ++test_count);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "   [5] vector" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		{
			int data[] = {1, 2, 3};
			std::vector<int> vec(data, std::end(data));

			ok += test(vec, 1, true, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 2, 3};
			std::vector<int> vec(data, std::end(data));

			ok += test(vec, -1, false, ++test_count);
			std::cout << std::endl;
		}
		{
			int data[] = {1, 1, 1};
			std::vector<int> vec(data, std::end(data));

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
			const std::vector<int> vec(data, std::end(data));

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
