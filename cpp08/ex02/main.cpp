#include <climits>
#include <iostream>
#include "MutantStack.hpp"

void test_subject() {
	std::cout << std::string(70, '=') << std::endl;
	std::cout << BOLD "[TEST] subject" RESET << std::endl;
	std::cout << std::string(70, '-') << std::endl;
	try {
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << CYAN "push(5)" RESET << std::endl;
		std::cout << CYAN "push(17)" RESET << std::endl;
		std::cout << "top : " << mstack.top() << "\n" << std::endl;


		mstack.pop();
		std::cout << CYAN "pop()" RESET << std::endl;
		std::cout << "size : " << mstack.size() << "\n" << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		/* [...] */
		mstack.push(0);
		std::cout << CYAN "push(3)" RESET << std::endl;
		std::cout << CYAN "push(5)" RESET << std::endl;
		std::cout << CYAN "push(737)" RESET << std::endl;
		std::cout << CYAN "push(0)" RESET << std::endl;
		std::cout << std::endl;

		mstack.display_info();

		std::cout << CYAN "it = begin()" RESET << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		std::cout << "*it : " <<  *it << std::endl;
		std::cout << std::endl;

		std::cout << CYAN "ite = end()" RESET << std::endl;
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << "*ite: " <<  *ite << std::endl;
		std::cout << std::endl;

		std::cout << CYAN "++it;" RESET << std::endl;
		std::cout << "*it : " <<  *it << std::endl;
		++it;
		std::cout << CYAN "--it;" RESET << std::endl;
		std::cout << "*it : " <<  *it << std::endl;
		--it;
		std::cout << std::endl;

		std::cout << CYAN "it: begin -> end" RESET << std::endl;
		while (it != ite) {
			std::cout << "*it : " <<  *it << std::endl;
			++it;
		}
		std::cout << std::endl;

		std::stack<int> s(mstack);
		std::cout << CYAN "std::stack<int> s(mstack)" RESET << std::endl;
		std::cout << "s.size: "  << s.size() << std::endl;
		std::cout << "s.top : "  << s.top() << std::endl;
		std::cout << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test_method() {
	std::cout << std::string(70, '=') << std::endl;
	std::cout << BOLD "[TEST] method: empty, size, push, pop, top" RESET << std::endl;
	std::cout << std::string(70, '-') << std::endl;
	try {
		MutantStack<int> mstack;

		std::cout << CYAN "MutantStack<int> mstack;" RESET << std::endl;
		mstack.display_info();

		std::cout << CYAN "mstack.push(42);" RESET << std::endl;
		mstack.push(42);
		mstack.display_info();

		std::cout << CYAN "mstack.pop();" RESET << std::endl;
		mstack.pop();
		mstack.display_info();

		std::cout << CYAN "mstack.top();" RESET << std::endl;
		try {
			std::cout << "  top: "<< mstack.top() << std::endl;
		} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		}
		mstack.display_info();

		std::cout << CYAN "mstack.push(-1);" RESET << std::endl;
		mstack.push(-1);
		mstack.display_info();

		std::cout << CYAN "mstack.top();" RESET << std::endl;
		try {
			std::cout << "  top: "<< mstack.top() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		mstack.display_info();

		std::cout << CYAN "mstack.pop();" RESET << std::endl;
		try {
			mstack.pop();
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		mstack.display_info();

		std::cout << CYAN "mstack.pop();" RESET << std::endl;
		try {
			mstack.pop();
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		mstack.display_info();

		std::cout << CYAN "mstack.top();" RESET << std::endl;
		try {
			std::cout << "  top: "<< mstack.top() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		mstack.display_info();

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test_constructor() {
	std::cout << std::string(70, '=') << std::endl;
	std::cout << BOLD "[TEST] constructor" RESET << std::endl;
	std::cout << std::string(70, '-') << std::endl;
	{
		std::cout << BOLD_UNDERLINE "1) int" RESET << std::endl;
		try {
			MutantStack<int> s;
			std::cout << CYAN "MutantStack<int> s" RESET << std::endl;
			s.display_info();

			std::cout << CYAN "push(1)" RESET << std::endl;
			std::cout << CYAN "push(INT_MIN)" RESET << std::endl;
			std::cout << CYAN "push(INT_MAX)" RESET << std::endl;
			s.push(1);
			s.push(INT_MIN);
			s.push(INT_MAX);
			s.display_info();

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "2) long" RESET << std::endl;
		try {
			MutantStack<long> s;
			std::cout << CYAN "MutantStack<long> s" RESET << std::endl;
			s.display_info();

			std::cout << CYAN "push(1)" RESET << std::endl;
			std::cout << CYAN "push(LONG_MIN)" RESET << std::endl;
			std::cout << CYAN "push(LONG_MAX)" RESET << std::endl;
			s.push(1);
			s.push(LONG_MIN);
			s.push(LONG_MAX);
			s.display_info();

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "3) std::string" RESET << std::endl;
		try {
			MutantStack<std::string> s;
			std::cout << CYAN "MutantStack<string> s" RESET << std::endl;
			s.display_info();

			std::cout << CYAN "push(\"1\")" RESET << std::endl;
			std::cout << CYAN "push(\"A\")" RESET << std::endl;
			std::cout << CYAN "push(\"\")" RESET << std::endl;
			std::cout << CYAN "push(\"test\")" RESET << std::endl;
			s.push("1");
			s.push("A");
			s.push("");
			s.push("test");
			s.display_info();
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void test_copy_constructor() {
	std::cout << std::string(70, '=') << std::endl;
	std::cout << BOLD "[TEST] copy constructor" RESET << std::endl;
	std::cout << std::string(70, '-') << std::endl;
	{
		std::cout << BOLD_UNDERLINE "1) copy() = MutantStack(src())" RESET << std::endl;
		try {
			std::cout << CYAN "MutantStack<int> src;" RESET << std::endl;
			MutantStack<int> src;
			std::cout << CYAN "MutantStack<int> copy = src;" RESET << std::endl;
			MutantStack<int> copy = MutantStack<int>(src);
			std::cout << std::endl;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "copy.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				src.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				copy.push(std::rand() % 10);
			}

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src = copy;" RESET << std::endl;
			src = copy;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "2) copy() = MutantStack(non empty src)" RESET<< std::endl;
		try {
			std::cout << CYAN "MutantStack<int> src;" RESET << std::endl;
			MutantStack<int> src;
			std::cout << CYAN "src.push(RANDOM) x 5" RESET << std::endl;
			for (int i = 0; i < 5; ++i) {
				src.push(std::rand() % 10);
			}

			std::cout << CYAN "MutantStack<int> copy = src;" RESET << std::endl;
			MutantStack<int> copy = MutantStack<int>(src);
			std::cout << std::endl;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "copy.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				src.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				copy.push(std::rand() % 10);
			}

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src = copy;" RESET << std::endl;
			src = copy;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "3) non empyt copy = MutantStack(src())" RESET << std::endl;
		try {
			std::cout << CYAN "MutantStack<int> src;" RESET << std::endl;
			MutantStack<int> src;

			std::cout << CYAN "MutantStack<int> copy;" RESET << std::endl;
			MutantStack<int> copy;

			std::cout << CYAN "copy.push(RANDOM) x 10" RESET << std::endl;
			for (int i = 0; i < 10; ++i) {
				copy.push(std::rand() % 10);
			}

			std::cout << CYAN "copy = src;" RESET << std::endl;
			copy = MutantStack<int>(src);
			std::cout << std::endl;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "copy.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				src.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				copy.push(std::rand() % 10);
			}

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src = copy;" RESET << std::endl;
			src = copy;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "4) non empyt copy = MutantStack(non empty src)" RESET << std::endl;
		try {
			std::cout << CYAN "MutantStack<int> src;" RESET << std::endl;
			MutantStack<int> src;

			std::cout << CYAN "MutantStack<int> copy;" RESET << std::endl;
			MutantStack<int> copy;

			std::cout << CYAN "src.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "copy.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				src.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				copy.push(std::rand() % 10);
			}

			std::cout << CYAN "copy = src;" RESET << std::endl;
			copy = MutantStack<int>(src);
			std::cout << std::endl;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "copy.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				src.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				copy.push(std::rand() % 10);
			}

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src = copy;" RESET << std::endl;
			src = copy;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "5) std::stack stk = std::stack(mstack())" RESET << std::endl;
		try {
			std::cout << CYAN "MutantStack<int> mstack;" RESET << std::endl;
			MutantStack<int> mstack;

			std::cout << CYAN "std::stack<int> stk = mstack;" RESET << std::endl;
			std::stack<int> stk = std::stack<int>(mstack);
			std::cout << std::endl;

			std::cout << "mstack:" << std::endl;
			mstack.display_info();

			std::cout << "stk:" << std::endl;
			std::cout << " *size  : " << stk.size() << std::endl;
			std::cout << " *empty : " << std::boolalpha << stk.empty() << std::endl;
			std::cout << " *top   : ";
			if (stk.empty()) {
				std::cout << "empty" << std::endl;
			} else {
				std::cout << stk.top() << std::endl;
			}
			std::cout << std::endl;

			std::cout << CYAN "mstack.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "stk.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				mstack.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				stk.push(std::rand() % 10);
			}

			std::cout << "mstack:" << std::endl;
			mstack.display_info();

			std::cout << "stk:" << std::endl;
			std::cout << " *size  : " << stk.size() << std::endl;
			std::cout << " *empty : " << std::boolalpha << stk.empty() << std::endl;
			std::cout << " *top   : ";
			if (stk.empty()) {
				std::cout << "empty" << std::endl;
			} else {
				std::cout << stk.top() << std::endl;
			}
			std::cout << std::endl;

			std::cout << CYAN "mstack = stk;" RESET << std::endl;
			mstack = stk;

			std::cout << "mstack:" << std::endl;
			mstack.display_info();

			std::cout << "stk:" << std::endl;
			std::cout << " *size  : " << stk.size() << std::endl;
			std::cout << " *empty : " << std::boolalpha << stk.empty() << std::endl;
			std::cout << " *top   : ";
			if (stk.empty()) {
				std::cout << "empty" << std::endl;
			} else {
				std::cout << stk.top() << std::endl;
			}
			std::cout << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "6) std::stack stk = std::stack(non empty mstack)" RESET << std::endl;
		try {
			std::cout << CYAN "MutantStack<int> mstack;" RESET << std::endl;
			MutantStack<int> mstack;
			std::cout << CYAN "mstack.push(RANDOM) x 5" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				mstack.push(std::rand() % 10);
			}

			std::cout << CYAN "std::stack<int> stk = mstack;" RESET << std::endl;
			std::stack<int> stk = std::stack<int>(mstack);
			std::cout << std::endl;

			std::cout << "mstack:" << std::endl;
			mstack.display_info();

			std::cout << "stk:" << std::endl;
			std::cout << " *size  : " << stk.size() << std::endl;
			std::cout << " *empty : " << std::boolalpha << stk.empty() << std::endl;
			std::cout << " *top   : ";
			if (stk.empty()) {
				std::cout << "empty" << std::endl;
			} else {
				std::cout << stk.top() << std::endl;
			}
			std::cout << std::endl;

			std::cout << CYAN "mstack.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "stk.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				mstack.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				stk.push(std::rand() % 10);
			}

			std::cout << "mstack:" << std::endl;
			mstack.display_info();

			std::cout << "stk:" << std::endl;
			std::cout << " *size  : " << stk.size() << std::endl;
			std::cout << " *empty : " << std::boolalpha << stk.empty() << std::endl;
			std::cout << " *top   : ";
			if (stk.empty()) {
				std::cout << "empty" << std::endl;
			} else {
				std::cout << stk.top() << std::endl;
			}
			std::cout << std::endl;

			std::cout << CYAN "mstack = stk;" RESET << std::endl;
			mstack = stk;

			std::cout << "mstack:" << std::endl;
			mstack.display_info();

			std::cout << "stk:" << std::endl;
			std::cout << " *size  : " << stk.size() << std::endl;
			std::cout << " *empty : " << std::boolalpha << stk.empty() << std::endl;
			std::cout << " *top   : ";
			if (stk.empty()) {
				std::cout << "empty" << std::endl;
			} else {
				std::cout << stk.top() << std::endl;
			}
			std::cout << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void test_copy_assignment() {
	std::cout << std::string(70, '=') << std::endl;
	std::cout << BOLD "[TEST] copy assignment" RESET << std::endl;
	std::cout << std::string(70, '-') << std::endl;
	{
		std::cout << BOLD_UNDERLINE "1) copy() = src()" RESET << std::endl;
		try {
			std::cout << CYAN "MutantStack<int> src;" RESET << std::endl;
			MutantStack<int> src;
			std::cout << CYAN "MutantStack<int> copy = src;" RESET << std::endl;
			MutantStack<int> copy = src;
			std::cout << std::endl;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "copy.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				src.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				copy.push(std::rand() % 10);
			}

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src = copy;" RESET << std::endl;
			src = copy;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "2) copy() = non empty src" RESET<< std::endl;
		try {
			std::cout << CYAN "MutantStack<int> src;" RESET << std::endl;
			MutantStack<int> src;
			std::cout << CYAN "src.push(RANDOM) x 5" RESET << std::endl;
			for (int i = 0; i < 5; ++i) {
				src.push(std::rand() % 10);
			}

			std::cout << CYAN "MutantStack<int> copy = src;" RESET << std::endl;
			MutantStack<int> copy = src;
			std::cout << std::endl;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "copy.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				src.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				copy.push(std::rand() % 10);
			}

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src = copy;" RESET << std::endl;
			src = copy;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "3) non empyt copy = src()" RESET << std::endl;
		try {
			std::cout << CYAN "MutantStack<int> src;" RESET << std::endl;
			MutantStack<int> src;

			std::cout << CYAN "MutantStack<int> copy;" RESET << std::endl;
			MutantStack<int> copy;

			std::cout << CYAN "copy.push(RANDOM) x 10" RESET << std::endl;
			for (int i = 0; i < 10; ++i) {
				copy.push(std::rand() % 10);
			}

			std::cout << CYAN "copy = src;" RESET << std::endl;
			copy = src;
			std::cout << std::endl;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "copy.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				src.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				copy.push(std::rand() % 10);
			}

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src = copy;" RESET << std::endl;
			src = copy;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "4) non empyt copy = non empty src" RESET << std::endl;
		try {
			std::cout << CYAN "MutantStack<int> src;" RESET << std::endl;
			MutantStack<int> src;

			std::cout << CYAN "MutantStack<int> copy;" RESET << std::endl;
			MutantStack<int> copy;

			std::cout << CYAN "src.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "copy.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				src.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				copy.push(std::rand() % 10);
			}

			std::cout << CYAN "copy = src;" RESET << std::endl;
			copy = src;
			std::cout << std::endl;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "copy.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				src.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				copy.push(std::rand() % 10);
			}

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

			std::cout << CYAN "src = copy;" RESET << std::endl;
			src = copy;

			std::cout << "src:" << std::endl;
			src.display_info();

			std::cout << "copy:" << std::endl;
			copy.display_info();

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "5) std::stack stk = mstack()" RESET << std::endl;
		try {
			std::cout << CYAN "MutantStack<int> mstack;" RESET << std::endl;
			MutantStack<int> mstack;

			std::cout << CYAN "std::stack<int> stk = mstack;" RESET << std::endl;
			std::stack<int> stk = mstack;
			std::cout << std::endl;

			std::cout << "mstack:" << std::endl;
			mstack.display_info();

			std::cout << "stk:" << std::endl;
			std::cout << " *size  : " << stk.size() << std::endl;
			std::cout << " *empty : " << std::boolalpha << stk.empty() << std::endl;
			std::cout << " *top   : ";
			if (stk.empty()) {
				std::cout << "empty" << std::endl;
			} else {
				std::cout << stk.top() << std::endl;
			}
			std::cout << std::endl;

			std::cout << CYAN "mstack.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "stk.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				mstack.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				stk.push(std::rand() % 10);
			}

			std::cout << "mstack:" << std::endl;
			mstack.display_info();

			std::cout << "stk:" << std::endl;
			std::cout << " *size  : " << stk.size() << std::endl;
			std::cout << " *empty : " << std::boolalpha << stk.empty() << std::endl;
			std::cout << " *top   : ";
			if (stk.empty()) {
				std::cout << "empty" << std::endl;
			} else {
				std::cout << stk.top() << std::endl;
			}
			std::cout << std::endl;

			std::cout << CYAN "mstack = stk;" RESET << std::endl;
			mstack = stk;

			std::cout << "mstack:" << std::endl;
			mstack.display_info();

			std::cout << "stk:" << std::endl;
			std::cout << " *size  : " << stk.size() << std::endl;
			std::cout << " *empty : " << std::boolalpha << stk.empty() << std::endl;
			std::cout << " *top   : ";
			if (stk.empty()) {
				std::cout << "empty" << std::endl;
			} else {
				std::cout << stk.top() << std::endl;
			}
			std::cout << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "6) std::stack stk = non empty mstack" RESET << std::endl;
		try {
			std::cout << CYAN "MutantStack<int> mstack;" RESET << std::endl;
			MutantStack<int> mstack;
			std::cout << CYAN "mstack.push(RANDOM) x 5" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				mstack.push(std::rand() % 10);
			}

			std::cout << CYAN "std::stack<int> stk = mstack;" RESET << std::endl;
			std::stack<int> stk = mstack;
			std::cout << std::endl;

			std::cout << "mstack:" << std::endl;
			mstack.display_info();

			std::cout << "stk:" << std::endl;
			std::cout << " *size  : " << stk.size() << std::endl;
			std::cout << " *empty : " << std::boolalpha << stk.empty() << std::endl;
			std::cout << " *top   : ";
			if (stk.empty()) {
				std::cout << "empty" << std::endl;
			} else {
				std::cout << stk.top() << std::endl;
			}
			std::cout << std::endl;

			std::cout << CYAN "mstack.push(RANDOM) x 5" RESET << std::endl;
			std::cout << CYAN "stk.push(RANDOM) x 10" RESET << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < 5; ++i) {
				mstack.push(std::rand() % 10);
			}
			for (int i = 0; i < 10; ++i) {
				stk.push(std::rand() % 10);
			}

			std::cout << "mstack:" << std::endl;
			mstack.display_info();

			std::cout << "stk:" << std::endl;
			std::cout << " *size  : " << stk.size() << std::endl;
			std::cout << " *empty : " << std::boolalpha << stk.empty() << std::endl;
			std::cout << " *top   : ";
			if (stk.empty()) {
				std::cout << "empty" << std::endl;
			} else {
				std::cout << stk.top() << std::endl;
			}
			std::cout << std::endl;

			std::cout << CYAN "mstack = stk;" RESET << std::endl;
			mstack = stk;

			std::cout << "mstack:" << std::endl;
			mstack.display_info();

			std::cout << "stk:" << std::endl;
			std::cout << " *size  : " << stk.size() << std::endl;
			std::cout << " *empty : " << std::boolalpha << stk.empty() << std::endl;
			std::cout << " *top   : ";
			if (stk.empty()) {
				std::cout << "empty" << std::endl;
			} else {
				std::cout << stk.top() << std::endl;
			}
			std::cout << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void test_iterator() {
	std::cout << std::string(70, '=') << std::endl;
	std::cout << BOLD "[TEST] iterator" RESET << std::endl;
	std::cout << std::string(70, '-') << std::endl;
	{
		std::cout << BOLD_UNDERLINE "1) iterator" RESET << std::endl;
		try {
			std::cout << CYAN "MutantStack<int> mstack;" RESET << std::endl;
			std::cout << std::endl;
			MutantStack<int> mstack;

			std::cout << CYAN "push(0), push(1), ..., push(9)" RESET << std::endl;
			for (int i = 0; i < 10; ++i) {
				mstack.push(i);
			}
			mstack.display_info();

			std::cout << CYAN "itr = begin() -> end(), itr *= 2" RESET << std::endl;
			for (MutantStack<int>::iterator itr = mstack.begin(); itr != mstack.end(); ++itr) {
				*itr *= 2;
			}
			mstack.display_info();

			std::cout << CYAN "const itr = begin() -> end(), cout" RESET << std::endl;
			std::cout << " mstack:";
			for (MutantStack<int>::const_iterator itr = mstack.begin(); itr != mstack.end(); ++itr) {
				std::cout << *itr << " ";
			}
			std::cout << std::endl;

			// std::cout << CYAN "const itr = begin() -> end(), *itr *= 2" RESET << std::endl;
			// // can't compile
			// std::cout << " mstack:";
			// for (MutantStack<int>::const_iterator itr = mstack.begin(); itr != mstack.end(); ++itr) {
			// 	*itr *= 2;
			// }

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "2) reverse iterator" RESET << std::endl;
		try {
			std::cout << CYAN "MutantStack<int> mstack;" RESET << std::endl;
			std::cout << std::endl;
			MutantStack<int> mstack;

			std::cout << CYAN "push(0), push(1), ..., push(9)" RESET << std::endl;
			for (int i = 0; i < 10; ++i) {
				mstack.push(i);
			}
			mstack.display_info();

			std::cout << CYAN "ritr = rbegin() -> rend(), itr *= 2" RESET << std::endl;
			for (MutantStack<int>::reverse_iterator itr = mstack.rbegin(); itr != mstack.rend(); ++itr) {
				*itr *= 2;
			}
			mstack.display_info();

			std::cout << CYAN "const ritr = rbegin() -> rend(), cout" RESET << std::endl;
			std::cout << " mstack:";
			for (MutantStack<int>::const_reverse_iterator itr = mstack.rbegin(); itr != mstack.rend(); ++itr) {
				std::cout << *itr << " ";
			}
			std::cout << std::endl;

			// std::cout << CYAN "const ritr = rbegin() -> rend(), *itr *= 2" RESET << std::endl;
			// // can't compile
			// std::cout << " mstack:";
			// for (MutantStack<int>::const_reverse_iterator itr = mstack.rbegin(); itr != mstack.rend(); ++itr) {
			// 	*itr *= 2;
			// }

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void test_compare_with_list() {
	std::cout << std::string(70, '=') << std::endl;
	std::cout << BOLD "[TEST] compare with std::list" RESET << std::endl;
	std::cout << std::string(70, '-') << std::endl;
	{
		std::cout << BOLD_UNDERLINE "1) method" RESET << std::endl;
		try {
			std::cout << CYAN "create" RESET << std::endl;
			std::cout << " std::list<int> lst;" << std::endl;
			std::cout << " MutantStack<int> mstack;" << std::endl;
			std::cout << std::endl;
			std::list<int> lst;
			MutantStack<int> mstack;

			std::cout << CYAN "size()" RESET << std::endl;
			std::cout << " lst.size()    : " << lst.size() << std::endl;
			std::cout << " mstack.size() : " << mstack.size() << std::endl;
			std::cout << std::endl;

			std::cout << CYAN "empty()" RESET << std::endl;
			std::cout << " lst.empty()    : " << std::boolalpha << lst.empty() << std::endl;
			std::cout << " mstack.empty() : " << std::boolalpha << mstack.empty() << std::endl;
			std::cout << std::endl;

			std::cout << CYAN "push(0), push(1), ..., push(9)" RESET << std::endl;
			for (int i = 0; i < 10; ++i) {
				lst.push_back(i);
				mstack.push(i);
			}
			std::cout << std::endl;

			std::cout << CYAN "size()" RESET << std::endl;
			std::cout << " lst.size()    : " << lst.size() << std::endl;
			std::cout << " mstack.size() : " << mstack.size() << std::endl;
			std::cout << std::endl;

			std::cout << CYAN "empty()" RESET << std::endl;
			std::cout << " lst.empty()    : " << std::boolalpha << lst.empty() << std::endl;
			std::cout << " mstack.empty() : " << std::boolalpha << mstack.empty() << std::endl;
			std::cout << std::endl;

			std::cout << CYAN "last element" RESET << std::endl;
			std::cout << " lst.back()   : " << lst.back() << std::endl;
			std::cout << " mstack.top() : " << mstack.top() << std::endl;
			std::cout << std::endl;

			std::cout << CYAN "pop back" RESET << std::endl;
			std::cout << std::endl;
			lst.pop_back();
			mstack.pop();

			std::cout << CYAN "size()" RESET << std::endl;
			std::cout << " lst.size()    : " << lst.size() << std::endl;
			std::cout << " mstack.size() : " << mstack.size() << std::endl;
			std::cout << std::endl;

			std::cout << CYAN "empty()" RESET << std::endl;
			std::cout << " lst.empty()    : " << std::boolalpha << lst.empty() << std::endl;
			std::cout << " mstack.empty() : " << std::boolalpha << mstack.empty() << std::endl;
			std::cout << std::endl;

			std::cout << CYAN "last element" RESET << std::endl;
			std::cout << " lst.back()   : " << lst.back() << std::endl;
			std::cout << " mstack.top() : " << mstack.top() << std::endl;
			std::cout << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << BOLD_UNDERLINE "2) iterator" RESET << std::endl;
		try {
			std::cout << CYAN "create" RESET << std::endl;
			std::cout << " std::list<int> lst;" << std::endl;
			std::cout << " MutantStack<int> mstack;" << std::endl;
			std::cout << std::endl;
			std::list<int> lst;
			MutantStack<int> mstack;

			std::cout << CYAN "size()" RESET << std::endl;
			std::cout << " lst.size()    : " << lst.size() << std::endl;
			std::cout << " mstack.size() : " << mstack.size() << std::endl;
			std::cout << std::endl;

			std::cout << CYAN "empty()" RESET << std::endl;
			std::cout << " lst.empty()    : " << std::boolalpha << lst.empty() << std::endl;
			std::cout << " mstack.empty() : " << std::boolalpha << mstack.empty() << std::endl;
			std::cout << std::endl;

			std::cout << CYAN "push(0), push(1), ..., push(9)" RESET << std::endl;
			for (int i = 0; i < 10; ++i) {
				lst.push_back(i);
				mstack.push(i);
			}
			std::cout << std::endl;

			std::cout << CYAN "itr: begin() -> end()" RESET << std::endl;
			std::cout << " lst    :[";
			for (std::list<int>::const_iterator itr = lst.begin(); itr != lst.end(); ++itr) {
				std::cout << *itr;
				std::list<int>::const_iterator next = itr;
				if (++next != lst.end()) {
					std::cout << " ";;
				}
			}
			std::cout << "]" << std::endl;

			std::cout << " mstack :[";
			for (MutantStack<int>::const_iterator itr = mstack.begin(); itr != mstack.end(); ++itr) {
				std::cout << *itr;
				MutantStack<int>::const_iterator next = itr;
				if (++next != mstack.end()) {
					std::cout << " ";;
				}

			}
			std::cout << "]" << std::endl;
			std::cout << std::endl;

			std::cout << CYAN "itr: rbegin() -> rend(), *itr *2" RESET << std::endl;

			std::cout << " lst    :[";
			for (std::list<int>::reverse_iterator itr = lst.rbegin(); itr != lst.rend(); ++itr) {
				*itr *= 2;
				std::cout << *itr;
				std::list<int>::reverse_iterator next = itr;
				if (++next != lst.rend()) {
					std::cout << " ";;
				}
			}
			std::cout << "]" << std::endl;

			std::cout << " mstack :[";
			for (MutantStack<int>::reverse_iterator itr = mstack.rbegin(); itr != mstack.rend(); ++itr) {
				*itr *= 2;
				std::cout << *itr;
				MutantStack<int>::reverse_iterator next = itr;
				if (++next != mstack.rend()) {
					std::cout << " ";;
				}

			}
			std::cout << "]" << std::endl;
			std::cout << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	std::srand(time(NULL));

	test_subject();
	test_constructor();
	test_copy_constructor();
	test_copy_assignment();
	test_method();
	test_iterator();
	test_compare_with_list();
	return 0;
}

#ifdef __APPLE__

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q a.out");
}

#endif
