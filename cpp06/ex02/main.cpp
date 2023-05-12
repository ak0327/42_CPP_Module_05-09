#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate();
void identify(Base &p);
void identify(Base &p);

Base *generate() {
	std::srand(std::time(NULL));

	switch (rand() % 3) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			break ;
	}
	return NULL;
}

void identify(Base *p) {
	if (!p) {
		throw std::invalid_argument("invalid argument");
	}
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	}
	else if(dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	}
	else if(dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
	else {
		throw std::invalid_argument("unexpected pointer");
	}
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		static_cast<void>(a);
		return ;
	}
	catch (const std::bad_cast &e) {}

	try {
		B &b = dynamic_cast<B &>(p);
		static_cast<void>(b);
		return ;
	}
	catch (const std::bad_cast &e) {}

	try {
		C &c = dynamic_cast<C &>(c);
		static_cast<void>(c);
		return ;
	}
	catch (const std::bad_cast &e) {}

	throw std::invalid_argument("unexpected ref pointer");
}

int main() {
	try {
		Base *ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Base *ptr = NULL;
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}