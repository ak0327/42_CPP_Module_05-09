#include <ctime>
#include <exception>
#include <iostream>
#include <stdlib.h>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"

Base *generate();
void identify(Base &p);
void identify(Base &p);

Base *generate() {
	try {
		switch (std::rand() % 3) {
			case 0:
				std::cout << "generate: A" << std::endl;
				return new A;
			case 1:
				std::cout << "generate: B" << std::endl;
				return new B;
			case 2:
				std::cout << "generate: C" << std::endl;
				return new C;
			default:
				break ;
		}
	}
	catch (std::bad_alloc const &e) {
		throw std::runtime_error("[Error] Fail to allocate memory");
	}
	return NULL;
}

void identify(Base *p) {
	std::cout << "identify(Base *p)" << std::endl;
	if (!p) {
		throw std::invalid_argument("[Error] Invalid argument");
	}
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "identify: argument class is A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "identify: argument class is B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "identify: argument class is C" << std::endl;
	}
	else {
		throw std::invalid_argument("[Error] Unexpected pointer");
	}
}

void identify(Base &p) {
	std::cout << "identify(Base &p)" << std::endl;
	try {
		A &a = dynamic_cast<A &>(p);
		static_cast<void>(a);
		std::cout << "identify: argument class is A" << std::endl;
		return ;
	}
	catch (std::exception const &e) {}

	try {
		B &b = dynamic_cast<B &>(p);
		static_cast<void>(b);
		std::cout << "identify: argument class is B" << std::endl;
		return ;
	}
	catch (std::exception const &e) {}

	try {
		C &c = dynamic_cast<C &>(p);
		static_cast<void>(c);
		std::cout << "identify: argument class is C" << std::endl;
		return ;
	}
	catch (std::exception const &e) {}

	throw std::invalid_argument("[Error] Unexpected ref pointer");
}

int main() {
	std::srand(std::time(NULL));

	{
		try {
			std::cout << "---------- test identify(Base *p) ----------" << std::endl;
			Base *ptr = generate();
			identify(ptr);
			delete ptr;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		try {
			std::cout << "---------- test identify(Base &p) ----------" << std::endl;
			Base *ptr = generate();
			Base &ref = *ptr;
			identify(ref);
			delete ptr;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		try {
			std::cout << "---------- identify(NULL) ----------" << std::endl;
			Base *ptr = NULL;
			identify(ptr);
			identify(*ptr);
			delete ptr;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "---------- identify *D ----------" << std::endl;
		Base *ptr = new D;
		try {
			identify(ptr);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		delete ptr;
		std::cout << std::endl;
	}
	{
		std::cout << "---------- identify &D ----------" << std::endl;
		Base *ptr = new D;
		try {
			Base &ref = *ptr;
			identify(ref);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		delete ptr;
		std::cout << std::endl;
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
