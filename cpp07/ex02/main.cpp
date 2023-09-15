#include <climits>
#include <cstdlib>
#include <iostream>
#include "Array.hpp"

template <typename T>
void print_arr(Array<T> arr) {
	size_t i = 0;
	size_t size = arr.size();

	std::cout << COLOR_CYAN "arr(" << arr.size() << ") [";
	while (i < size) {
		std::cout << arr[i];
		i++;
		if (i < size) {
			std::cout << ", ";
		}
	}
	std::cout << "]" COLOR_RESET << std::endl;
}

int main() {
	{
		std::cout << "--------------- subject ---------------" << std::endl;
		srand(time(NULL));
		const int MAX_VAL = 750;

		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];

		for (int i = 0; i < MAX_VAL; i++) {
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++) {
			if (mirror[i] != numbers[i]) {
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}

		try {
			numbers[-2] = 0;
		} catch(const std::exception& e) {
			std::cerr << "out of range1: " << e.what() << '\n';
		}

		try {
			numbers[MAX_VAL] = 0;
		} catch(const std::exception& e) {
			std::cerr <<  "out of range2: " << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++) {
			numbers[i] = rand();
		}
		delete [] mirror;//
		std::cout << std::endl;
	}
	{
		std::cout << "--------------- default constructor ---------------" << std::endl;
		{
			std::cout << "[1] int: arr(10)" << std::endl;
			try {
				size_t size = 10;
				Array<int> arr(size);

				std::cout << " 1) arr(10)" << std::endl;
				print_arr(arr);
				std::cout << std::endl;

				std::cout << " 2) arr[i] = rand() % 10" << std::endl;
				for (size_t i = 0; i < size; ++i) {
					arr[i] = rand() % 10;
				}
				print_arr(arr);
				std::cout << std::endl;

			} catch (std::exception const &e) {
				std::cerr << e.what() << "\n" << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << "[2] char: arr(10)" << std::endl;
			try {
				size_t size = 10;
				Array<char> arr(size);

				std::cout << "  1) arr(10)" << std::endl;
				print_arr(arr);
				std::cout << std::endl;

				std::cout << "  2) arr[i] = char 'a'~'j'" << std::endl;
				for (size_t i = 0; i < size; ++i) {
					arr[i] = static_cast<char>(i + 'a');
				}
				print_arr(arr);
				std::cout << std::endl;

			} catch (std::exception const &e) {
				std::cerr << e.what() << "\n" << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << "[3] string: arr(10)" << std::endl;
			try {
				size_t size = 10;
				Array<std::string> arr(size);

				std::cout << "  1) arr(10)" << std::endl;
				print_arr(arr);
				std::cout << std::endl;

				std::cout << "  2) arr[i] = std::string A or B" << std::endl;
				for (size_t i = 0; i < size; ++i) {
					if (i % 2 == 0) {
						arr[i] = "A";
					} else {
						arr[i] = "B";
					}
				}
				print_arr(arr);
				std::cout << std::endl;

			} catch (std::exception const &e) {
				std::cerr << e.what() << "\n" << std::endl;
			}
			std::cout << std::endl;
		}
	}
	{
		std::cout << "--------------- copy constructor ---------------" << std::endl;
		{
			std::cout << "[1] int: copy = Array(src(10))" << std::endl;
			try {
				size_t size = 10;
				Array<int> src(size);
				Array<int> copy = Array<int>(src);

				std::cout << " 1) pirnt src, copy" << std::endl;
				std::cout << "  src :"; print_arr(src);
				std::cout << "  copy:"; print_arr(copy);
				std::cout << std::endl;

				std::cout << " 2) change src elem" << std::endl;
				for (size_t i = 0; i < size; ++i) {
					src[i] = rand() % 10;
				}
				std::cout << std::endl;

				std::cout << " 3) pirnt src, copy" << std::endl;
				std::cout << "  src :"; print_arr(src);
				std::cout << "  copy:"; print_arr(copy);
				std::cout << std::endl;

				std::cout << " 4) destruct src" << std::endl;
				src.~Array(); std::cout << std::endl;

				std::cout << " 5) pirnt copy" << std::endl;
				std::cout << "  copy:"; print_arr(copy);
				std::cout << std::endl;


			} catch (std::exception const &e) {
				std::cerr << e.what() << "\n" << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << "[2] int: copy = Array(src)" << std::endl;
			try {
				Array<int> src;
				Array<int> copy = Array<int>(src);

				std::cout << " pirnt src, copy" << std::endl;
				std::cout << "  src :"; print_arr(src);
				std::cout << "  copy:"; print_arr(copy);
				std::cout << std::endl;

				std::cout << "  copy[0] = " << copy[0] << std::endl;

			} catch (std::exception const &e) {
				std::cerr << e.what() << "\n" << std::endl;
			}
			std::cout << std::endl;
		}
	}
	{
		std::cout << "--------------- copy assignment ---------------" << std::endl;
		{
			std::cout << "[1] int: copy(10) = src(1)" << std::endl;
			try {
				size_t src_size = 1;
				Array<int> src(src_size);
				src[0] = 42;

				size_t copy_size = 10;
				Array<int> copy(copy_size);
				for (size_t i = 0; i < copy_size; ++i) {
					copy[i] = rand() % 10;
				}

				std::cout << " 1) pirnt src, copy" << std::endl;
				std::cout << "  src :"; print_arr(src);
				std::cout << "  copy:"; print_arr(copy);
				std::cout << std::endl;

				std::cout << " 2) copy = src" << std::endl;
				copy = src;
				std::cout << std::endl;

				std::cout << " 3) pirnt src, copy" << std::endl;
				std::cout << "  src :"; print_arr(src);
				std::cout << "  copy:"; print_arr(copy);
				std::cout << std::endl;

				std::cout << std::endl;

			} catch (std::exception const &e) {
				std::cerr << e.what() << "\n" << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << "[2] int: copy(1) = src(10)" << std::endl;
			try {
				size_t src_size = 10;
				Array<int> src(src_size);
				for (size_t i = 0; i < src_size; ++i) {
					src[i] = rand() % 10;
				}

				size_t copy_size = 1;
				Array<int> copy(copy_size);
				copy[0] = 42;

				std::cout << " 1) pirnt src, copy" << std::endl;
				std::cout << "  src :"; print_arr(src);
				std::cout << "  copy:"; print_arr(copy);
				std::cout << std::endl;

				std::cout << " 2) copy = src" << std::endl;
				copy = src;
				std::cout << std::endl;

				std::cout << " 3) pirnt src, copy" << std::endl;
				std::cout << "  src :"; print_arr(src);
				std::cout << "  copy:"; print_arr(copy);
				std::cout << std::endl;

				std::cout << std::endl;

			} catch (std::exception const &e) {
				std::cerr << e.what() << "\n" << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << "[3] long: copy = src(10)" << std::endl;
			try {
				size_t size = 10;
				Array<long> src(size);
				Array<long> copy = src;

				std::cout << " 1) pirnt src, copy" << std::endl;
				std::cout << "  src :"; print_arr(src);
				std::cout << "  copy:"; print_arr(copy);
				std::cout << std::endl;

				std::cout << " 2) change src elem" << std::endl;
				for (size_t i = 0; i < size; ++i) {
					src[i] = rand() % 10;
				}
				std::cout << std::endl;

				std::cout << " 3) pirnt src, copy" << std::endl;
				std::cout << "  src :"; print_arr(src);
				std::cout << "  copy:"; print_arr(copy);
				std::cout << std::endl;

				std::cout << " 4) destruct src" << std::endl;
				src.~Array();
				std::cout << std::endl;

				std::cout << " 5) pirnt copy" << std::endl;
				std::cout << "  copy:"; print_arr(copy);
				std::cout << std::endl;

			} catch (std::exception const &e) {
				std::cerr << e.what() << "\n" << std::endl;
			}
			std::cout << std::endl;
		}
		{
			std::cout << "[4] long: copy = src" << std::endl;
			try {
				Array<long> src;
				Array<long> copy = src;

				std::cout << " 1) pirnt src, copy" << std::endl;
				std::cout << "  src :"; print_arr(src);
				std::cout << "  copy:"; print_arr(copy);
				std::cout << std::endl;

			} catch (std::exception const &e) {
				std::cerr << e.what() << "\n" << std::endl;
			}
			std::cout << std::endl;
		}

	}
	// can't compile
	// {
	// 	std::cout << "--------------- copy assignment <int> -> <long> ---------------" << std::endl;
	// 	try {
	// 		size_t size = 10;
	// 		Array<int> src(size);
	// 		Array<long> copy = src;
	//
	// 	} catch (std::exception const &e) {
	// 		std::cerr << e.what() << "\n" << std::endl;
	// 	}
	// 	std::cout << std::endl;
	// }
	{
		std::cout << "--------------- size() ---------------" << std::endl;
		try {
			Array<int> arr1;
			std::cout << " 1) int: arr1; arr1.size() : " << arr1.size() << std::endl;
			std::cout << std::endl;

			Array<int> arr2(0);
			std::cout << " 2) int: arr2(0); arr2.size() : " << arr2.size() << std::endl;
			std::cout << std::endl;

			Array<int> arr3(1000);
			std::cout << " 3) int: arr3(1000); arr3.size() : " << arr3.size() << std::endl;
			std::cout << std::endl;

		} catch (std::exception const &e) {
			std::cerr << e.what() << "\n" << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "--------------- error : index out of range ---------------" << std::endl;
		{
			try {
				Array<int> arr;
				std::cout << " 1) int: arr(); arr[0] : " << arr[0] << std::endl;
			} catch (std::exception const &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			try {
				Array<int> arr;
				std::cout << " 2) int: arr(); assign 1 to arr[0]..." << std::endl;
				arr[0] = 1;
			} catch (std::exception const &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			try {
				Array<int> arr;
				std::cout << " 3) int: arr(); arr[1] : " << arr[1] << std::endl;
			} catch (std::exception const &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			try {
				Array<int> arr(10);
				std::cout << " 4) int: arr(10); arr[9] : " << arr[9] << std::endl;
			} catch (std::exception const &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			try {
				Array<int> arr(10);
				std::cout << " 5) int: arr(10); arr[10] : " << arr[9] << std::endl;
			} catch (std::exception const &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		{
			try {
				Array<int> arr(10);
				std::cout << " 6) int: arr(10); arr[-1] : " << arr[-1] << std::endl;
			} catch (std::exception const &e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "--------------- operator[] ---------------" << std::endl;
		{
			{
				std::cout << " 1) int: arr(10); arr[1]" << std::endl;
				try {
					Array<int> arr(10);
					std::cout << "  arr[1] : " << arr[1] << "\n" << std::endl;

					std::cout << "  arr[1] = 42" << std::endl;
					arr[1] = 42;
					std::cout << "  arr[1] : " << arr[1] << std::endl;
				} catch (std::exception const &e) {
					std::cerr << e.what() << "\n" << std::endl;
				}
				std::cout << std::endl;
			}
			{
				std::cout << " 2) int: const arr(10); arr[1]" << std::endl;
				try {
					const Array<int> arr(10);
					std::cout << "  const arr[1] : " << arr[1] << std::endl;

					// can't compile
//					std::cout << "  arr[1] = 42" << std::endl;
//					arr[1] = 42;
//					std::cout << "  arr[1] = " << arr[1] << std::endl;
				} catch (std::exception const &e) {
					std::cerr << e.what() << "\n" << std::endl;
				}
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;

	}
	// {
	// 	std::cout << "--------------- error : big size ---------------" << std::endl;
	// 	try {
	// 		Array<int> arr(UINT_MAX);
	// 		std::cout << "Array<int> arr(UINT_MAX); arr.size() = " << arr.size() << std::endl;
	// 		std::cout << "Array<int> arr[UINT_MAX - 1] = " << arr[UINT_MAX - 1] << std::endl;
	// 		std::cout << "Array<int> arr[UINT_MAX] = " << arr[UINT_MAX] << std::endl;
	// 	} catch (std::exception const &e) {
	// 		std::cerr << e.what() << "\n" << std::endl;
	// 	}
	// 	std::cout << std::endl;
	//
	// }
	// {
	// 	std::cout << "--------------- big1 = big2 ---------------" << std::endl;
	// 	try {
	// 		Array<int> big1(UINT_MAX);
	// 		Array<int> big2(UINT_MAX);
	// 		Array<int> big3 = big2;
	// 	} catch (std::exception const &e) {
	// 		std::cerr << e.what() << "\n" << std::endl;
	// 	}
	// 	std::cout << std::endl;
	// }
	return 0;
}

#ifdef __APPLE__

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}

#endif
