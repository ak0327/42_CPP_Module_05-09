#include <iostream>
#include "MutantStack.hpp"

int main() {
	{
		std::cout << "==================== subject ====================" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << "push(5)" << std::endl;
		std::cout << "push(17)" << std::endl;
		std::cout << "top : " << mstack.top() << "\n" << std::endl;


		mstack.pop();
		std::cout << "pop()" << std::endl;
		std::cout << "size : " << mstack.size() << "\n" << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		/* [...] */
		mstack.push(0);
		std::cout << "push(3)" << std::endl;
		std::cout << "push(5)" << std::endl;
		std::cout << "push(737)" << std::endl;
		std::cout << "push(0)" << std::endl;
		std::cout << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;

		std::cout << "it: begin -> end" << std::endl;
		while (it != ite) {
			std::cout << "*it : " <<  *it << std::endl;
			++it;
		}
		std::cout << std::endl;

		std::stack<int> s(mstack);
		std::cout << "std::stack<int> s(mstack)" << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "==================== test 1: push, pop ====================" << std::endl;
		MutantStack<int> mstack;
		mstack.display_info();

		std::cout << "push(1)" << std::endl;
		mstack.push(1);
		mstack.display_info();

		std::cout << "push(2)" << std::endl;
		mstack.push(2);
		mstack.display_info();


		std::cout << "pop()" << std::endl;
		mstack.pop();
		mstack.display_info();

		std::cout << std::endl;
	}
	{
		std::cout << "==================== test2: itr ====================" << std::endl;
		MutantStack<int> mstack;

		for (int i = 0; i < 10; ++i) {
			mstack.push(i);
		}
		mstack.display_info();

		std::cout << "itr = begin()" << std::endl;
		MutantStack<int>::iterator itr = mstack.begin();
		std::cout << "*itr : " << *itr << std::endl;
		std::cout << "++itr" << std::endl;
		++itr;
		std::cout << "*itr : " << *itr << std::endl;
		std::cout << std::endl;

		MutantStack<int>::iterator itr2;
		itr2 = mstack.begin();
		std::cout << "*itr2 : " << *itr2 << std::endl;

		std::cout << std::endl;
	}
	{
		std::cout << "==================== std::stack s = mstack ====================" << std::endl;
		MutantStack<int> mstack;

		for (int i = 0; i < 10; ++i) {
			mstack.push(i);
		}
		mstack.display_info();

		std::stack<int> s = mstack;
		std::cout << "std::stack<int> s(mstack)" << std::endl;
		std::cout << "s.size():" << s.size() << std::endl;
		std::cout << "s.top():" << s.top() << std::endl;
		std::cout << std::endl;

		s.pop();
		std::cout << "s.pop()" << std::endl;
		std::cout << "s.size():" << s.size() << std::endl;
		std::cout << "s.top():" << s.top() << std::endl;

		std::cout << std::endl;
	}
	{
		std::cout << "==================== std::stack s(mstack) ====================" << std::endl;
		MutantStack<int> mstack;

		for (int i = 0; i < 10; ++i) {
			mstack.push(i);
		}
		mstack.display_info();

		std::stack<int> s(mstack);
		std::cout << "std::stack<int> s(mstack)" << std::endl;
		std::cout << "s.size():" << s.size() << std::endl;
		std::cout << "s.top():" << s.top() << std::endl;
		std::cout << std::endl;

		s.pop();
		std::cout << "s.pop()" << std::endl;
		std::cout << "s.size():" << s.size() << std::endl;
		std::cout << "s.top():" << s.top() << std::endl;

		std::cout << std::endl;
	}
	{
		std::cout << "==================== copy constructor ====================" << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "==================== copy assignment ====================" << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "==================== iterator ====================" << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "==================== const iterator ====================" << std::endl;
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
