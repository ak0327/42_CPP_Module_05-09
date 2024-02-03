#include <deque>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "PmergeMe.hpp"

namespace {

const char SIGN_PLUS = '+';
const char SIGN_MINUS = '-';
const std::size_t OMIT_CNT = 20;

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


int to_digit(const char &c) {
    return (c - '0');
}


int stoi(const std::string &str, std::size_t &idx, bool &succeed) {
    std::size_t i;
    int num, digit, sign;

    idx = 0;

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
        digit = to_digit(str[i]);
        if (!is_in_int_range(num, digit)) {
            num = (sign == 1) ? INT_MAX : INT_MIN;
            succeed = false;
            idx = i;
            return num;
        }
        num = num * 10 + sign * digit;
        i++;
    }

    idx = i;
    succeed = true;
    return num;
}


int to_integer_num(const std::string &str, std::size_t &end, bool &succeed) {
    succeed = false;
    end = 0;
    if (str.empty() || !std::isdigit(str[0])) { return 0; }
    return stoi(str, end, succeed);
}

template <typename Container1, typename Container2>
void get_args(std::size_t &nums_idx,
              char **args,
              bool &succeed,
              Container1 &container1,
              Container2 &container2) {
    int num;
    bool stoi_succeed;
    std::size_t end;

    nums_idx = 0;
    while (args[nums_idx]) {
        num = to_integer_num(args[nums_idx], end, stoi_succeed);
        // std::cout << YELLOW << "nums_idx:" << nums_idx
        // << ", arg:" << args[nums_idx]
        // << ", num:" << num
        // << ", stoi:" << std::boolalpha << stoi_succeed << RESET << std::endl;

        if (args[nums_idx][end] != '\0' || !stoi_succeed || num < 0) {
            succeed = false;
            return;
        }

        container1.push_back(num);
        container2.push_back(num);
        ++nums_idx;
    }

    if (container1.size() == 0) {
        succeed = false;
        return;
    }
    succeed = true;
}

template <typename Container>
std::string get_elements_str(const Container &container) {
    typename Container::const_iterator elem;
    std::stringstream ss;
    std::size_t cnt;

    cnt = 0;
    ss << "[";
    for (elem = container.begin(); elem != container.end(); ++elem) {
        ++cnt;
        if (cnt >= OMIT_CNT) {
            ss << "...";
            break;
        }
        ss << *elem;
        if (elem + 1 != container.end()) {
            ss << " ";
        }
    }
    ss << "]";
    return ss.str();
}

std::ostream &operator<<(std::ostream &out, const std::deque<int> &deque) {
    out << get_elements_str(deque);
    return out;
}

std::ostream &operator<<(std::ostream &out, const std::vector<int> &vector) {
    out << get_elements_str(vector);
    return out;
}

std::string runtime_msg(std::size_t nums_cnt, const std::string &type) {
    std::stringstream ss;

    ss << "Time to process a range of " << nums_cnt;
    ss << (nums_cnt == 1 ? " element " : " elements ");
    ss << "with " << type;
    return ss.str();
}

std::string get_error_msg(const char *err_arg) {
    std::stringstream ss;

    ss << "invalid argument";
    if (err_arg) {
        ss << " \"" << err_arg << "\"";
    }
    return ss.str();
}

template <typename Container>
std::string result(const std::vector<int> &expected, const Container &actual) {
    std::stringstream ss;
    std::size_t cnt;
    bool ok = true;

    if (expected.size() != actual.size()) {
        ss << YELLOW << " <sort result> size NG -> "
        << "expected: " << expected.size()
        << ", actual: " << actual.size() << RESET;
        return ss.str();
    }

    cnt = 0;
    ss << "[";
    for (std::size_t i = 0; i < expected.size(); ++i) {
        ++cnt;
        if (cnt >= OMIT_CNT) {
            ss << "... ";
            break;
        }
        if (expected[i] == actual[i]) {
            ss << actual[i];
        } else {
            ss << RED << actual[i] << RESET;
        }
        ss << (i + 1 < expected.size() ? " " : "");
    }
    ss << "]";
    if (ok) {
        ss << GREEN << " OK" << RESET;
    } else {
        ss << RED << " NG" << RESET;
    }
    return ss.str();
}


int calc_compare_count(int n) {
    double ans = 0;

    for (int k = 1; k <= n; ++k) {
        double term = std::ceil(std::log2(3.0 * k / 4.0));
        ans += term;
    }
    return static_cast<int>(ans);
}


}  // namespace

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {
    bool succeed;
    std::size_t nums_idx;
    std::size_t nums_cnt;
    std::vector<int> std_sorted;
    std::vector<int> nums_vec, sorted_vec;
    std::deque<int> nums_dq, sorted_dq;
    PmergeMe<std::vector<int> > sort_vector;
    PmergeMe<std::deque<int> >  sort_deque;

    get_args(nums_idx, &argv[1], succeed, nums_dq, nums_vec);
    if (!succeed) {
        std::cout << YELLOW << "[Error] " << get_error_msg(argv[nums_idx + 1]) << RESET << std::endl;
        return EXIT_FAILURE;
    }

    nums_cnt = argc - 1;
    sort_vector.sort(nums_vec);
    sort_deque.sort(nums_dq);

    //--------------------------------------------------------------------------
    // before
    //--------------------------------------------------------------------------
    std::cout << "Before(deque) : " << sort_deque.get_sequence() << std::endl;
    std::cout << "Before(vector): " << sort_vector.get_sequence() << std::endl;
    std::cout << std::endl;

    //--------------------------------------------------------------------------
    // after
    //--------------------------------------------------------------------------
    std_sorted = nums_vec;
    std::sort(std_sorted.begin(), std_sorted.end());
    sorted_vec = sort_vector.get_sorted();
    sorted_dq = sort_deque.get_sorted();

    std::cout << "std::sort     : " << std_sorted << std::endl;
    std::cout << "After(vector) : " << result(std_sorted, sorted_vec) << std::endl;
    std::cout << "After(deque)  : " << result(std_sorted, sorted_dq) << std::endl;

    std::cout << std::endl;


    //--------------------------------------------------------------------------
    // time
    //--------------------------------------------------------------------------
    std::cout << runtime_msg(nums_cnt, "std::vector") << " : "
    << std::fixed << std::setprecision(1) << sort_vector.get_process_time() << " us" << std::endl;

    std::cout << runtime_msg(nums_cnt, "std::deque ") << " : "
    << std::fixed << std::setprecision(1) << sort_deque.get_process_time() << " us" << std::endl;
    std::cout << std::endl;

    //--------------------------------------------------------------------------
    // compare_cnt
    //--------------------------------------------------------------------------
    std::cout << "compare count(deque)  : " << sort_deque.get_compare_cnt() << std::endl;
    std::cout << "compare count(vector) : " << sort_vector.get_compare_cnt() << std::endl;
    std::cout << "log(n)                : " << calc_compare_count(static_cast<int>(nums_cnt)) << std::endl;

    return EXIT_SUCCESS;
}
