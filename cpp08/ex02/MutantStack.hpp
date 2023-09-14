#pragma once

# include <algorithm>
# include <exception>
# include <iterator>
# include <iostream>
# include <stack>
# include <list>

# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET	"\x1b[0m"

template <typename T>
class MutantStack {
 public:
	/* constructor, operator */
	MutantStack();
	~MutantStack();
	MutantStack<T>(const MutantStack<T> &other);

	MutantStack<T> &operator=(const MutantStack<T> &rhs);
	operator std::stack<T>() const;

	/* member function */
	const T &top() const;
	bool empty() const;
	size_t size() const;

	void push(const T &value);
	void pop();

	void display_info() const;
	void display_data() const;


	/* iterator */
	typedef typename std::list<T>::iterator iterator;
	typedef typename std::list<T>::const_iterator const_iterator;

	iterator begin();
	const_iterator begin() const;

	iterator rbegin();
	const_iterator rbegin() const;

	iterator end();
	const_iterator end() const;

	iterator rend();
	const_iterator rend() const;

 private:
	std::stack<T> data_;
	std::list<T> itr_;

};

////////////////////////////////////////////////////////////////////////////////
/* constructor, operator */
template <typename T>
MutantStack<T>::MutantStack() : data_(), itr_() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other)
		: data_(other.data_), itr_(other.itr_) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs) {
	if (this == &rhs) {
		return *this;
	}
	data_ = rhs.data_;
	itr_ = rhs.itr_;
	return *this;
}

template <typename T>
MutantStack<T>::operator std::stack<T>() const {
	return data_;
}

////////////////////////////////////////////////////////////////////////////////
/* member function */
template <typename T>
const T &MutantStack<T>::top() const {
	if (data_.empty()) {
		throw std::invalid_argument(COLOR_YELLOW "[Error] stack is empty" COLOR_RESET);
	}
	return data_.top();
}

template <typename T>
bool MutantStack<T>::empty() const {
	return data_.empty();
}

template <typename T>
size_t MutantStack<T>::size() const {
	return data_.size();
}

template <typename T>
void MutantStack<T>::push(const T &value) {
	data_.push(value);
	itr_.push_back(data_.top());
}

template <typename T>
void MutantStack<T>::pop() {
	data_.pop();
	itr_.pop_back();
}

template <typename T>
void MutantStack<T>::display_info() const {
	std::cout << "----------[stack info]----------" << std::endl;
	std::cout << " *stack : "; display_data();
	std::cout << " *size  : " << size() << std::endl;
	std::cout << " *empty : " << std::boolalpha << empty() << std::endl;
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
	for (const_iterator itr = itr_.begin(); itr != itr_.end(); ++itr) {
		std::cout << *itr;
		const_iterator next = itr;
		++next;
		if (next != itr_.end()) {
			std::cout << " ";
		}
	}
	std::cout << " (top)" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
/* iterator */
template <typename T>
typename std::list<T>::iterator MutantStack<T>::begin() {
	return itr_.begin();
}

template <typename T>
typename std::list<T>::const_iterator MutantStack<T>::begin() const {
	return itr_.begin();
}

template <typename T>
typename std::list<T>::iterator MutantStack<T>::rbegin() {
	return itr_.rbegin();
}

template <typename T>
typename std::list<T>::const_iterator MutantStack<T>::rbegin() const {
	return itr_.rbegin();
}

template <typename T>
typename std::list<T>::iterator MutantStack<T>::end() {
	return itr_.end();
}

template <typename T>
typename std::list<T>::const_iterator MutantStack<T>::end() const {
	return itr_.end();
}

template <typename T>
typename std::list<T>::iterator MutantStack<T>::rend() {
	return itr_.rend();
}

template <typename T>
typename std::list<T>::const_iterator MutantStack<T>::rend() const {
	return itr_.rend();
}
