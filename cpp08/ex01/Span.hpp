#pragma once

# include <set>
# include <ostream>

class Span {
 public:
	Span(unsigned int n);
	Span(const Span &other);
	~Span();

	Span &operator=(const Span &rhs);

	void addNumber(int num);
	void addRangeNumber(int start, int stop, int step = 1);

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	std::set<int> get_data() const;
	size_t get_size() const;

 private:

	unsigned int max_size_;
	unsigned int shortest_span_;
	unsigned int longest_spen_;
	std::set<int> data_;

	void update_shortest_span(int num);
	void update_longest_span();
	void addPositiveRangeNumber(int start, int stop, int step);
	void addNegativeRangeNumber(int start, int stop, int step);
};

std::ostream &operator<<(std::ostream &os, const Span &span);
