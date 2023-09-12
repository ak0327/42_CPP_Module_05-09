#pragma once

# include <stdexcept>
# include <iostream>
//Implement a function template iter that takes 3 parameters and returns nothing.
// • The first parameter is the address of an array.
// • The second one is the length of the array.
// • The third one is a function that will be call on every element of the array.

template <typename T>
void iter(const T *addr, const size_t len, void (*func)(const T&)) {
	std::cout << "called: void iter(const T *addr, size_t len, void func(const T&))" << std::endl;
	if (!addr || len == 0 || !func) {
		throw std::invalid_argument("[Error] invalid argument");
	}
	for (size_t i = 0; i < len; ++i) {
		func(addr[i]);
	}
}

template <typename T>
void iter(T *addr, const size_t len, void (*func)(T&)) {
	std::cout << "called: void iter(T *addr, size_t len, void func(T&))" << std::endl;
	if (!addr || len == 0 || !func) {
		throw std::invalid_argument("[Error] invalid argument");
	}
	for (size_t i = 0; i < len; ++i) {
		func(addr[i]);
	}
}

template <typename T>
void print_arr(const T &val) {
	std::cout << val << " ";
}
