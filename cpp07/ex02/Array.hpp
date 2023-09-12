#pragma once

# include <iostream>
# include <stdexcept>

# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET	"\x1b[0m"

template <typename T>
class Array {
 public:
	// Construction with no parameter:
	// Creates an empty array.
	Array();

	// Construction with an unsigned int n as a parameter:
	// Creates an array of n elements initialized by default.
	Array(unsigned int n);

	// Construction by copy.
	// modifying either the original array or its copy after copying musn’t affect the other array.
	Array(const Array &other);

	~Array();

	// assignment operator.
	// modifying either the original array or its copy after copying musn’t affect the other array.
	Array<T> &operator=(const Array &rhs);

	// Elements can be accessed through the subscript operator: [ ].
	const T &operator[](size_t idx) const;
	T &operator[](size_t idx);

	// A member function size() that returns the number of elements in the array.
	unsigned int size() const;

 private:
	unsigned int size_;
	T *arr_;

};

// Construction with no parameter:
template <typename T>
Array<T>::Array() : size_(0), arr_(NULL) {
	try {
		arr_ = new T[size_]();
	} catch (const std::bad_alloc &e) {
		throw;
	}
}

// Construction with an unsigned int n as a parameter:
template <typename T>
Array<T>::Array(unsigned int n) : size_(0), arr_(NULL) {
	try {
		arr_ = new T[n]();
	} catch (const std::bad_alloc &e) {
		throw;
	}
	size_ = n;
}

// Construction by copy
template <typename T>
Array<T>::Array(const Array &other) : size_(0), arr_(NULL) {
	try {
		arr_ = new T[other.size()]();
	} catch (const std::bad_alloc &e) {
		throw;
	}
	size_ = other.size();
	for (size_t i = 0; i < size_; ++i) {
		arr_[i] = other.arr_[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] arr_;
	arr_ = NULL;
	size_ = 0;
}

// assignment operator.
template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs) {
	if (this == &rhs) {
		return *this;
	}

	T *tmp;
	try {
		tmp = new T[rhs.size()]();
	} catch (const std::bad_alloc &e) {
		throw;
	}

	delete[] arr_;
	arr_ = tmp;
	size_ = rhs.size();
	for (size_t i = 0; i < size_; ++i) {
		arr_[i] = rhs.arr_[i];
	}
	return *this;
}

template <typename T>
const T &Array<T>::operator[](size_t idx) const {
	if (!arr_) {
		throw std::runtime_error(COLOR_RED "[Error] Fatal error" COLOR_RESET);
	}
	if (size() <= idx) {
		throw std::out_of_range(COLOR_YELLOW "[Error] Index out of range" COLOR_RESET);
	}
	return arr_[idx];
}

template <typename T>
T &Array<T>::operator[](size_t idx) {
	return const_cast<T&>(
			static_cast<const Array&>(*this)[idx]
	);
}

template <typename T>
unsigned int Array<T>::size() const { return size_; }
