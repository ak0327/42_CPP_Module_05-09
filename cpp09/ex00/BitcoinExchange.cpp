#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream ifs;

	ifs.open(PRICE_DATA_PATH, std::ifstream::in);
	if (!ifs.is_open()) {
		throw std::invalid_argument("data.csv not found.");
	}

	this->data_ = get_price_data(ifs);
	// std::cout << this->data_;
	ifs.close();
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}


BitcoinExchange::~BitcoinExchange() {}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this == &rhs) {
		return *this;
	}
	data_ = rhs.data_;
	return *this;
}


void skip_header(std::ifstream &ifs, const std::string &header) {
	std::string line;

	std::getline(ifs, line);
	if (line == header) {
		return;
	}
	throw std::invalid_argument("Header invalid.");
}

void split_line_by_delimiter(const std::string &line,
							 const std::string &delimiter,
							 std::string &date,
							 std::string &value) {
	std::size_t delim_pos;

	delim_pos = line.find(delimiter);
	if (delim_pos == std::string::npos) {
		std::stringstream ss;
		ss << std::left << std::setw(28) << "Data invalid." << " => " + line;
		std::string error_msg = ss.str();
		throw std::invalid_argument(error_msg);
	}
	if (delim_pos == 0 || delim_pos + delimiter.length() == line.length()) {
		std::stringstream ss;
		ss << std::left << std::setw(28) << "Data invalid." << " => " + line;
		std::string error_msg = ss.str();
		throw std::invalid_argument(error_msg);
	}
	date = line.substr(0,delim_pos);
	value = line.substr(delim_pos + delimiter.length());
}


std::map<Date, float> BitcoinExchange::get_price_data(std::ifstream &ifs) {
	std::map<Date, float> data;
	std::string line, timestamp, rate_str;
	float rate;
	bool succeed;
	Date date;

	skip_header(ifs, DATA_CSV_HEADER);

	while (std::getline(ifs, line)) {
		try {
			split_line_by_delimiter(line, COMMA, timestamp, rate_str);

			date = Date(timestamp);
			rate = lib::to_float_num(rate_str, &succeed);
			if (!succeed) {
				throw std::invalid_argument("data.csv data invalid.");
			}

			if (data.find(date) != data.end()) {
				throw std::invalid_argument("data.csv data invalid.");
			}
			data[date] = rate;

			// std::cout << "[" << line << "]"
			// 		  << " -> [" << timestamp << "],"
			// 		  << " [" << rate_str << "](" << rate << ")" << std::endl;

		} catch (const std::exception &e) {

			throw std::invalid_argument(e.what());
		}
	}
	return data;
}


float get_rate(std::map<Date, float> &data, const Date &date) {
	std::map<Date, float>::const_iterator itr = data.find(date);
	if (itr != data.end()) {
		return itr->second;
	}

	itr = data.lower_bound(date);
	if (itr == data.begin()) {
		return GET_RATE_ERROR;
	}
	--itr;
	return itr->second;
}


void BitcoinExchange::exchange(const char *input_file_path) {
	std::ifstream ifs;
	std::string line, timestamp, value_str;
	float value, price, rate;
	bool succeed;
	Date date;
	std::size_t line_no;

	ifs.open(input_file_path, std::ifstream::in);
	if (!ifs.is_open()) {
		throw std::invalid_argument("Could not open file.");
	}

	skip_header(ifs, "date | value");

	line_no = 1;
	while (std::getline(ifs, line)) {
		try {
			++line_no;

			if (line.empty()) {
				continue;
			}

			split_line_by_delimiter(line, INPUT_DELIMITER,timestamp, value_str);

			date = Date(timestamp);

			value = lib::to_float_num(value_str, &succeed);
			if (!succeed || value < 0.0f || 1000.0f < value) {
				std::stringstream ss;
				ss << std::left << std::setw(28) << "Input data invalid. " << " => " << value_str;
				std::string error_msg = ss.str();
				throw std::invalid_argument(error_msg);
			}

			rate = get_rate(this->data_, date);
			if (rate == GET_RATE_ERROR) {
				std::stringstream ss;
				ss << std::left << std::setw(28) << "Date too old." << " => " << timestamp;
				std::string error_msg = ss.str();
				throw std::invalid_argument(error_msg);
			}

			price = rate * value;
			// std::cout << CYAN << "price:" << price << ", rate:" << rate << ", value:" << value << RESET << std::endl;

			if (isinf(price)) {
				std::stringstream ss;
				ss << std::left << std::setw(28) << "Calculated price too high." << " => " << timestamp;
				std::string error_msg = ss.str();
				throw std::invalid_argument(error_msg);
			}

			std::stringstream ss;
			ss << std::left << std::setw(12) << timestamp << " => "
			   << std::right << std::setw(12) << std::fixed << std::setprecision(6) << value     << " => "
			   << std::right << std::setw(15) << std::fixed << std::setprecision(6) << price;
			std::cout << CYAN << ss.str() << RESET << std::endl;

		} catch (const std::exception &e) {
			std::stringstream ss;
			ss << std::left << std::setw(60) << "[Error]: " + std::string(e.what()) << " :(L" << line_no << ")";
			std::string error_msg = ss.str();
			std::cout << YELLOW << error_msg << RESET << std::endl;
		}


	}
	ifs.close();
}


std::ostream &operator<<(std::ostream &out, const std::map<Date, float> &data) {
	std::map<Date, float>::const_iterator itr;
	for (itr = data.begin(); itr != data.end(); ++itr) {
		Date date = itr->first;
		float rate = itr->second;

		out << date.year_ << "-" << date.month_ << "-"<< date.day_
			<< ":"
			<< rate << std::endl;
	}
	return out;
}

////////////////////////////////////////////////////////////////////////////////


Date::Date() : year_(0), month_(0), day_(0) {}


Date::Date(const std::string &timestamp) : year_(0), month_(0), day_(0) {
	if (parse_timestamp(timestamp) == FAILURE) {
		std::stringstream ss;
		ss << std::left << std::setw(28) << "Invalid date." << " => " + timestamp;
		std::string error_msg = ss.str();
		throw std::invalid_argument(error_msg);
	}
	if (validate_date() == FAILURE) {
		std::stringstream ss;
		ss << std::left << std::setw(28) << "Invalid date." << " => " + timestamp;
		std::string error_msg = ss.str();
		throw std::invalid_argument(error_msg);
	}
}


Date::Date(const Date &other) {
	*this = other;
}


Date::~Date() {}


Date &Date::operator=(const Date &rhs) {
	if (this == &rhs) {
		return *this;
	}
	year_ = rhs.year_;
	month_ = rhs.month_;
	day_ = rhs.day_;
	return *this;
}


bool Date::operator<(const Date &rhs) const {
	if (year_ != rhs.year_) {
		return year_ < rhs.year_;
	}
	if (month_ != rhs.month_) {
		return month_ < rhs.month_;
	}
	return day_ < rhs.day_;
}


int Date::parse_timestamp(const std::string &timestamp) {
	int year, month, day;
	std::size_t pos, end;
	bool is_of;

	pos = 0;

	year = lib::to_integer_num(&timestamp[pos], &end, &is_of);
	pos += end;
	if (end == 0 || is_of) {
		return FAILURE;
	}
	if (timestamp[pos] != TIMESTAMP_DELIMITER) {
		return FAILURE;
	}
	++pos;

	month = lib::to_integer_num(&timestamp[pos], &end, &is_of);
	pos += end;
	if (end == 0 || is_of) {
		return FAILURE;
	}
	if (timestamp[pos] != TIMESTAMP_DELIMITER) {
		return FAILURE;
	}
	++pos;

	day = lib::to_integer_num(&timestamp[pos], &end, &is_of);
	pos += end;
	if (end == 0 || is_of) {
		return FAILURE;
	}
	if (timestamp[pos] != NULL_CHAR) {
		return FAILURE;
	}

	this->year_ = year;
	this->month_ = month;
	this->day_ = day;
	return SUCCESS;
}


bool Date::is_leap_year(int year) const {
	if (year % 4 != 0) {
		return false;
	}
	if (year % 100 == 0 && year % 400 != 0) {
		return false;
	}
	return true;
}


int Date::validate_date() const {
	int month_idx;
	int days_in_month[12];
	const int jan_idx = 0, feb_idx = 1, mar_idx = 2, apr_idx = 3,
			  may_idx = 4, jun_idx = 5, jul_idx = 6, aug_idx = 7,
			  sep_idx = 8, oct_idx = 9, nov_idx = 10, dec_idx = 11;
	const int GREGORIAN_CALENDAR = 1582;

	int year = this->year_;
	int month = this->month_;
	int day = this->day_;

	if (year < GREGORIAN_CALENDAR || month < 1 || 12 < month) {
		return FAILURE;
	}
	month_idx = month - 1;

	days_in_month[jan_idx] = 31;
	days_in_month[feb_idx] = is_leap_year(year) ? 29 : 28;
	days_in_month[mar_idx] = 31;
	days_in_month[apr_idx] = 30;
	days_in_month[may_idx] = 31;
	days_in_month[jun_idx] = 30;
	days_in_month[jul_idx] = 31;
	days_in_month[aug_idx] = 31;
	days_in_month[sep_idx] = 30;
	days_in_month[oct_idx] = 31;
	days_in_month[nov_idx] = 30;
	days_in_month[dec_idx] = 31;

	if (1 <= day && day <= days_in_month[month_idx]) {
		return SUCCESS;
	}
	return FAILURE;
}


////////////////////////////////////////////////////////////////////////////////


bool is_in_int_range(int before_x10_num,
					 int add_num) {
	int max_div, max_mod;

	if (before_x10_num == INT_MAX || before_x10_num == INT_MIN) {
		return false;
	}
	if (before_x10_num > 0) {
		max_div = INT_MAX / 10;
		max_mod = INT_MAX % 10;
	} else {
		max_div = -(INT_MIN / 10);
		max_mod = -(INT_MIN % 10);
	}
	if (std::abs(before_x10_num) < max_div) {
		return true;
	}
	if (std::abs(before_x10_num) == max_div && max_mod == add_num) {
		return true;
	}
	return false;
}


int lib::to_digit(const char &c) {
	return (c - '0');
}


int stoi(const std::string &str, std::size_t *idx, bool *overflow) {
	std::size_t	i;
	int num, digit, sign;

	if (overflow) { *overflow = false; }
	if (idx) { *idx = 0; }

	i = 0;
	while (std::isspace(str[i])) {
		i++;
	}

	sign = 1;
	if (str[i] == SIGN_PLUS || str[i] == SIGN_MINUS) {
		if (str[i] == SIGN_MINUS) {
			sign = -1;
		}
		i++;
	}

	num = 0;
	while (std::isdigit(str[i])) {
		digit = lib::to_digit(str[i]);
		if (!is_in_int_range(num, digit)) {
			num = (sign == 1) ? INT_MAX : INT_MIN;
			if (overflow) { *overflow = true; }
			if (idx) { *idx = i; }
			return num;
		}
		num = num * 10 + sign * digit;
		i++;
	}

	if (idx) { *idx = i; }
	return num;
}


int lib::to_integer_num(const std::string &str, std::size_t *end, bool *is_overflow) {
	std::size_t pos = 0;

	if (is_overflow) { *is_overflow = false; }
	if (end) { *end = 0; }
	if (!std::isdigit(str[pos])) { return FAILURE; }
	return stoi(str, end, is_overflow);
}


double get_fractional_part(const std::string &str_after_decimal_point,
						   size_t *precision_idx) {
	double	digit, num;
	int		precision_num;
	size_t	pos;

	num = 0;
	digit = 1;
	pos = 0;
	while (isdigit(str_after_decimal_point[pos])) {
		precision_num = lib::to_digit(str_after_decimal_point[pos]);
		num = num * 10 + static_cast<double>(precision_num);
		digit *= 10;
		++pos;
	}
	*precision_idx = pos;
	num /= digit;
	return num;
}


double get_integer_part(const std::string &str, std::size_t *idx) {
	double num;
	int digit;
	size_t pos;

	num = 0;
	pos = 0;
	while (isdigit(str[pos])) {
		digit = lib::to_digit(str[pos]);
		num = num * 10 + static_cast<double>(digit);
		++pos;
	}
	*idx = pos;
	return num;
}


float lib::to_float_num(const std::string &str, bool *succeed) {
	bool is_success;
	double num, precision_num;
	std::size_t	pos, precision_idx;

	is_success = false;
	if (succeed) { *succeed = is_success; }
	num = 0;
	pos = 0;
	if (!std::isdigit(str[pos])) {
		return static_cast<float>(num);
	}

	num = get_integer_part(str, &pos);

	if (str[pos] != DECIMAL_POINT) {
		if (str[pos] == '\0') {
			is_success = true;
		}
		if (succeed) {
			*succeed = is_success;
		}
		return static_cast<float>(num);
	}
	++pos;

	precision_num = get_fractional_part(&str[pos],
										&precision_idx);
	num += precision_num;

	if (str[pos + precision_idx] == '\0') {
		is_success = true;
	}
	if (succeed) {
		*succeed = is_success;
	}
	return static_cast<float>(num);
}
