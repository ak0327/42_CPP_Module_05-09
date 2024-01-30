#pragma once

# include <map>

# define SUCCESS	0
# define FAILURE	1
# define GET_RATE_ERROR -1.0f

# define TIMESTAMP_DELIMITER	'-'
# define NULL_CHAR				'\0'
# define DECIMAL_POINT			'.'
# define SIGN_PLUS				'+'
# define SIGN_MINUS				'-'
# define COMMA					","
# define INPUT_DELIMITER		" | "
# define PRICE_DATA_PATH		"./data.csv"
# define DATA_CSV_HEADER		"date,exchange_rate"

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define GRAY			"\033[90m"

namespace lib {

int to_digit(const char &c);
int to_integer_num(const std::string &str, std::size_t *end, bool *is_overflow);
float to_float_num(const std::string &str, bool *succeed);

}


struct Date {
 public:
	int year_;
	int month_;
	int day_;

	Date();
	Date(const std::string &timestamp);
	Date(const Date &other);
	~Date();

	Date &operator=(const Date &rhs);
	bool operator<(const Date &rhs) const;

 private:
	int parse_timestamp(const std::string &timestamp);
	int validate_date() const;
	bool is_leap_year(int year) const;
};

class BitcoinExchange {
 public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void exchange(const char *file_path);

 private:
	std::map<Date, float> data_;

	std::map<Date, float> get_price_data(std::ifstream &ifs);
};

std::ostream &operator<<(std::ostream &out, const std::map<Date, float> &data);
