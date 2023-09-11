#include <iostream>
#include "iter.hpp"

void twice(int &val) {
	val *= 2;
}

template <typename T>
void print_arr(const T &val) {
	std::cout << val << " ";
}

int main(void) {
	{
		std::cout << "--------------- 1) print_arr ---------------" << std::endl;
		try {
			const int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			size_t size = sizeof(arr) / sizeof(arr[0]);
			iter(arr, size, print_arr);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "--------------- 2) twice ---------------" << std::endl;
		try {
			int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			size_t size = sizeof(arr) / sizeof(arr[0]);
			iter(arr, size, twice);
			iter(arr, size, print_arr);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "--------------- 3) error: iter(NULL, size, func) ---------------" << std::endl;
		try {
			iter(static_cast<int *>(NULL), 10, print_arr);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "--------------- 4) error: size=0 ---------------" << std::endl;
		try {
			int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			iter(arr, 0, print_arr);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "--------------- 5) error: iter(arr, size, NULL) ---------------" << std::endl;
		try {
			int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			size_t size = sizeof(arr) / sizeof(arr[0]);
			iter(arr, size, static_cast<void(*)(int&)>(NULL));
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}
