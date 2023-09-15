#pragma once

# include <algorithm>
# include <exception>
# include <iterator>
# include <iostream>
# include <stack>
# include <list>

# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"
# define UNDERLINE		"\033[4m"
# define BOLD_UNDERLINE	"\033[1;4m"

template <typename T>
class MutantStack : public std::stack<T> {
 public:
	/* constructor, operator */
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack<T> &other);
	MutantStack<T> &operator=(const MutantStack<T> &rhs);
	MutantStack<T> &operator=(const std::stack<T> &rhs);

	/* member function */
	const T &top() const;
	bool empty() const;
	size_t size() const;

	void push(const T &value);
	void pop();

	/* original function */
	void display_info() const;
	void display_data() const;

	/* iterator */
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	iterator begin();
	const_iterator begin() const;

	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;

	iterator end();
	const_iterator end() const;

	reverse_iterator rend();
	const_reverse_iterator rend() const;

};

////////////////////////////////////////////////////////////////////////////////
/* constructor, operator */
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs) {
	if (this == &rhs) {
		return *this;
	}
	std::stack<T>::operator=(rhs);
	return *this;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const std::stack<T> &rhs) {
	if (this == &rhs) {
		return *this;
	}
	std::stack<T>::operator=(rhs);
	return *this;
}

////////////////////////////////////////////////////////////////////////////////
/* member function */
template <typename T>
const T &MutantStack<T>::top() const {
	if (empty()) {
		throw std::invalid_argument(YELLOW "[Error] stack is empty" RESET);
	}
	return std::stack<T>::top();
}

template <typename T>
bool MutantStack<T>::empty() const {
	return std::stack<T>::empty();
}

template <typename T>
size_t MutantStack<T>::size() const {
	return std::stack<T>::size();
}

template <typename T>
void MutantStack<T>::push(const T &value) {
	std::stack<T>::push(value);
}

template <typename T>
void MutantStack<T>::pop() {
	if (empty()) {
		throw std::invalid_argument(YELLOW "[Error] stack is empty" RESET);
	}
	std::stack<T>::pop();
}

template <typename T>
void MutantStack<T>::display_info() const {
	std::cout << "----------[stack info]----------" << std::endl;
	std::cout << " *stack : "; display_data();
	std::cout << " *size  : " << std::stack<T>::size() << std::endl;
	std::cout << " *empty : " << std::boolalpha << std::stack<T>::empty() << std::endl;
	std::cout << " *top   : ";
	try {
		std::cout << top() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------\n" << std::endl;
}

template <typename T>
void MutantStack<T>::display_data() const {
	std::cout << "[";
	for (const_iterator itr = begin(); itr != end(); ++itr) {
		std::cout << *itr;
		const_iterator next = itr;
		++next;
		if (next != end()) {
			std::cout << " ";
		}
	}
	std::cout << "]" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
/* iterator */
template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const {
	return static_cast<const_iterator>(std::stack<T>::c.begin());
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin() {
	return std::stack<T>::c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin() const {
	return static_cast<const_reverse_iterator>(std::stack<T>::c.rbegin());
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
	return std::stack<T>::c.end();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const {
	return static_cast<const_iterator>(std::stack<T>::c.end());
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend() {
	return std::stack<T>::c.rend();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend() const {
	return static_cast<const_reverse_iterator>(std::stack<T>::c.rend());
}
