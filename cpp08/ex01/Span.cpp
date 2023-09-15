#include <algorithm>
#include <climits>
#include <exception>
#include <iostream>
#include <ostream>
#include <sstream>
#include "Span.hpp"

/* constructor, operator */
Span::Span() : max_size_(0),
			   shortest_span_(UINT_MAX),
			   longest_span_(0),
			   data_(std::set<int>()) {}

Span::Span(unsigned int n) : max_size_(n),
							 shortest_span_(UINT_MAX),
							 longest_span_(0),
							 data_(std::set<int>()) {}

Span::Span(const Span &other) : max_size_(other.max_size_),
								shortest_span_(other.shortest_span_),
								longest_span_(other.longest_span_),
								data_(other.data_) {}

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
	if (this == &rhs) {
		return *this;
	}
	max_size_ = rhs.max_size_;
	shortest_span_ = rhs.shortest_span_;
	longest_span_ = rhs.longest_span_;
	data_ = rhs.data_;
	return *this;
}

////////////////////////////////////////////////////////////////////////////////
/* member function */
// addNumber
void Span::addNumber(int num) {
	if (data_.size() == max_size_) {
		throw std::invalid_argument(YELLOW "[Error] Span is full" RESET);
	}
	data_.insert(num);
	update_shortest_span(num);
	update_longest_span();
}

template <typename Container>
void Span::addContainerNumbers(const Container &c) {
	typename Container::const_iterator itr;

	for (itr = c.begin(); itr != c.end(); ++itr) {
		addNumber(*itr);
	}
}

void Span::addNumbers(const std::deque<int> &dq) {
	addContainerNumbers(dq);
}

void Span::addNumbers(const std::list<int> &lst) {
	addContainerNumbers(lst);
}

void Span::addNumbers(const std::set<int> &st) {
	addContainerNumbers(st);
}

void Span::addNumbers(const std::vector<int> &vec) {
	addContainerNumbers(vec);
}

void Span::addNumbers(const int *start, const int *stop) {
	if (!start || !stop) {
		throw std::invalid_argument(YELLOW "[Error] invalid argument" RESET);
	}
	if (stop < start) {
		throw std::invalid_argument(YELLOW "[Error] invalid argument" RESET);
	}
	for (int *ptr = const_cast<int *>(start); ptr != stop; ++ptr) {
		addNumber(*ptr);
	}
}

/* addRangeNumber */
void Span::addRangeNumber(int start, int stop, int step) {
	// std::cout << "addRangeNumber:" << start << "->" << stop << "/" << step << std::endl;

	if (data_.size() == max_size_) {
		throw std::invalid_argument("[Error] Span is full");
	}
	try {
		assert_range_param(start, stop, step);
		if (step > 0) {
			addPositiveRangeNumber(start, stop, step);
		} else {
			addNegativeRangeNumber(start, stop, step);
		}
	} catch (const std::invalid_argument &e) {
		throw;
	}
}

void Span::assert_range_param(int start, int stop, int step) const {
	// std::cout << "assert:" << start << "->" << stop << "/" << step << std::endl;
	if (step == 0) {
		throw std::invalid_argument(YELLOW "[Error] Invalid argument: invalid step" RESET);
	}
	if (start < stop && step < 0) {
		throw std::invalid_argument(YELLOW "[Error] Invalid argument: invalid range" RESET);
	}
	if (start > stop && step > 0) {
		throw std::invalid_argument(YELLOW "[Error] Invalid argument: invalid range" RESET);
	}
}

void Span::addPositiveRangeNumber(int start, int stop, int step) {
	// std::cout << "pos range" << std::endl;
	for (int i = start; i < stop; i += step) {
		// std::cout << "i:" << i << std::endl;
		addNumber(i);
		if (INT_MAX - step < i) {
			// std::cout << "lhs:" << INT_MAX - i << ", step:" << step << std::endl;
			// std::cout << "break" << std::endl;
			break;
		}
	}
}

void Span::addNegativeRangeNumber(int start, int stop, int step) {
	// std::cout << "neg range" << std::endl;
	int neg_step = step * (-1);
	for (int i = start; stop < i; i -= neg_step) {
		addNumber(i);
		if (i < INT_MIN - step) {
			break;
		}
	}
}

/* shortestSpan */
unsigned int Span::shortestSpan() const {
	if (data_.size() < MIN_TO_GET_SPAN) {
		throw std::invalid_argument(YELLOW "[Error] Lack numbers to find span" RESET);
	}
	return shortest_span_;
}

/* longestSpan */
unsigned int Span::longestSpan() const {
	if (data_.size() < MIN_TO_GET_SPAN) {
		throw std::invalid_argument(YELLOW "[Error] Lack numbers to find span" RESET);
	}
	return longest_span_;
}

void Span::update_shortest_span(int num) {
	std::set<int>::iterator pos, prev, next;
	unsigned int span_pos_to_prev, span_pos_to_next;

	pos = data_.find(num);
	next = pos; ++next;
	if (pos != data_.begin()) {
		prev = pos; --prev;
		span_pos_to_prev = *pos - *prev;
		shortest_span_ = std::min(shortest_span_, span_pos_to_prev);
	}
	if (next != data_.end()) {
		span_pos_to_next = *next - *pos;
		shortest_span_ = std::min(shortest_span_, span_pos_to_next);
	}
}

void Span::update_longest_span() {
	std::set<int>::iterator begin, end;
	unsigned int span_begin_to_end;

	begin = data_.begin();
	end = data_.end(); --end;
	if (end == data_.begin()) {
		return;
	}
	span_begin_to_end = *end - *begin;
	longest_span_ = std::max(longest_span_, span_begin_to_end);
}

std::set<int> Span::get_data() const { return data_; }

size_t Span::get_size() const { return data_.size(); }

////////////////////////////////////////////////////////////////////////////////

static std::string get_data_str(const std::set<int> &st) {
	std::ostringstream oss;

	oss << "[";
	for (std::set<int>::iterator itr = st.begin(); itr != st.end(); ++itr) {
		oss << *itr;
		std::set<int>::iterator next = itr; ++next;
		if (next != st.end()) {
			oss << ", ";
		}
	}
	oss << "]";
	return oss.str();
}

std::ostream &operator<<(std::ostream &os, const Span &span) {
	ssize_t span_min, span_max;
	try {
		span_min = span.shortestSpan();
	} catch (const std::exception &e) {
		span_min = -1;
	}
	try {
		span_max = span.longestSpan();
	} catch (const std::exception &e) {
		span_max = -1;
	}

	os << " data:" << get_data_str(span.get_data()) << std::endl;
	os << " size:" << span.get_size() << std::endl;
	os << " min :" << span_min << std::endl;
	os << " max :" << span_max << std::endl;

	return os;
}
