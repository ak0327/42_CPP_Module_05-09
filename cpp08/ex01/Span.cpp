#include <algorithm>
#include <climits>
#include <exception>
#include <iostream>
#include <ostream>
#include <sstream>
#include "Span.hpp"

Span::Span(unsigned int n) : max_size_(n),
							 shortest_span_(UINT_MAX),
							 longest_spen_(0),
							 data_(std::set<int>()) {}

Span::Span(const Span &other) : max_size_(other.max_size_),
								shortest_span_(other.shortest_span_),
								longest_spen_(other.longest_spen_),
								data_(other.data_) {}

Span::~Span() {}

Span &Span::operator=(const Span &rhs) {
	if (this == &rhs) {
		return *this;
	}
	max_size_ = rhs.max_size_;
	shortest_span_ = rhs.shortest_span_;
	longest_spen_ = rhs.longest_spen_;
	data_ = rhs.data_;
	return *this;
}

void Span::addNumber(int num) {
	if (data_.size() == max_size_) {
		throw std::invalid_argument("[Error] Span is full");
	}
	data_.insert(num);
	update_shortest_span(num);
	update_longest_span();
}

void assert_range_param(int start, int stop, int step) {
	// std::cout << "assert:" << start << "->" << stop << "/" << step << std::endl;
	if (step == 0) {
		throw std::invalid_argument("[Error] Invalid argument: invalid step");
	}
	if (start < stop && step < 0) {
		throw std::invalid_argument("[Error] Invalid argument: invalid range");
	}
	if (start > stop && step > 0) {
		throw std::invalid_argument("[Error] Invalid argument: invalid range");
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

unsigned int Span::shortestSpan() const {
	if (data_.size() < 2) {
		throw std::invalid_argument("[Error] Lack numbers to find span");
	}
	return shortest_span_;
}

unsigned int Span::longestSpan() const {
	if (data_.size() < 2) {
		throw std::invalid_argument("[Error] Lack numbers to find span");
	}
	return longest_spen_;
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
	longest_spen_ = std::max(longest_spen_, span_begin_to_end);
}

std::set<int> Span::get_data() const { return data_; }

size_t Span::get_size() const { return data_.size(); }

std::string get_data_str(const std::set<int> &st) {
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
