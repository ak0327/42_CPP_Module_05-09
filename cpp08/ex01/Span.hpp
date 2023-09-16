#pragma once

# include <deque>
# include <list>
# include <set>
# include <vector>
# include <ostream>

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

# define MIN_TO_GET_SPAN	2

class Span {
 public:
	/* constructor, operator*/
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	~Span();

	Span &operator=(const Span &rhs);

	/* add single number */
	void addNumber(int num);

	/* add numbers */
	void addNumbers(const int *start, const int *stop);
	void addNumbers(const std::deque<int>& dq);
	void addNumbers(const std::list<int>& lst);
	void addNumbers(const std::set<int>& st);
	void addNumbers(const std::vector<int>& vec);

	/* add range number */
	void addRangeNumber(int start, int stop, int step = 1);

	/* span */
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	/* getter */
	std::set<int> get_data() const;
	size_t get_size() const;

 private:
	unsigned int max_size_;
	unsigned int num_count_;
	unsigned int shortest_span_;
	unsigned int longest_span_;
	std::set<int> data_;

	void update_shortest_span(int num);
	void update_longest_span();
	void addPositiveRangeNumber(int start, int stop, int step);
	void addNegativeRangeNumber(int start, int stop, int step);
	void assert_range_param(int start, int stop, int step) const;

	template <typename Container>
	void addContainerNumbers(const Container &c);
};

std::ostream &operator<<(std::ostream &os, const Span &span);
