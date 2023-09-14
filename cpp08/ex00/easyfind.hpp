#pragma once

# include <algorithm>
# include <exception>
# include <typeinfo>
# include <vector>

# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET	"\x1b[0m"

template <typename T>
typename T::const_iterator easyfind(const T &container, int find_value) {
//	std::cout << COLOR_MAGENTA "const easyfind called" COLOR_RESET << std::endl;
	typename T::const_iterator itr = std::find(container.begin(), container.end(), find_value);
	if (itr == container.end()) {
		throw std::runtime_error(COLOR_YELLOW "[Error] value not found" COLOR_RESET);
	}
	return itr;
}

template <typename T>
typename T::iterator easyfind(T &container, int find_value) {
//	std::cout << COLOR_CYAN "easyfind called" COLOR_RESET << std::endl;
	typename T::iterator itr = std::find(container.begin(), container.end(), find_value);
	if (itr == container.end()) {
		throw std::runtime_error(COLOR_YELLOW "[Error] value not found" COLOR_RESET);
	}
	return itr;
}
