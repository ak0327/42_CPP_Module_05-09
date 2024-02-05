#include <deque>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <list>
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

template <typename Container1, typename Container2, typename Container3>
void get_args(std::size_t &nums_idx,
              char **args,
              bool &succeed,
              Container1 &container1,
              Container2 &container2,
              Container3 &container3) {
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
        container3.push_back(num);
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
    typename Container::const_iterator elem, next_elem;
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

        next_elem = elem;
        ++next_elem;
        if (next_elem != container.end()) {
            ss << " ";
        }
    }
    ss << "]";
    return ss.str();
}

#ifdef DEBUG
// std::ostream &operator<<(std::ostream &out, const std::deque<int> &deque) {
//     out << get_elements_str(deque);
//     return out;
// }

std::ostream &operator<<(std::ostream &out, const std::list<int> &list) {
    out << get_elements_str(list);
    return out;
}
#endif
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
    std::vector<int>::const_iterator expected_itr;
    typename Container::const_iterator actual_itr;
    std::stringstream ss;
    std::size_t elem_cnt;
    bool succeed, omitted;

    if (expected.size() != actual.size()) {
        ss << YELLOW << " <sort result> size NG -> "
           << "expected: " << expected.size()
           << ", actual: " << actual.size() << RESET;
        return ss.str();
    }

    elem_cnt = 0;
    succeed = true;
    omitted = false;
    expected_itr = expected.begin();
    actual_itr = actual.begin();

    ss << "[";
    while (expected_itr != expected.end() && actual_itr != actual.end()) {
        ++elem_cnt;
        if (elem_cnt == OMIT_CNT) {
            ss << "...";
            omitted = true;
        }

        std::stringstream elem_ss;
        if (*expected_itr == *actual_itr) {
            elem_ss << *actual_itr;
        } else {
            succeed = false;
            elem_ss << RED << *actual_itr << RESET;
        }

        if (!omitted) {
            ss << elem_ss.str();
        }

        ss << (!omitted && expected_itr + 1 != expected.end() ? " " : "");

        ++expected_itr;
        ++actual_itr;
    }
    ss << "]" << (succeed ? GREEN " OK" RESET : RED " NG" RESET);
    return ss.str();
}


}  // namespace

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {
    bool succeed;
    std::size_t nums_idx;
    std::size_t nums_cnt;
    std::vector<int> std_sorted;
    std::deque<int> nums_dq, sorted_dq;
    std::list<int> nums_list, sorted_list;
    std::vector<int> nums_vec, sorted_vec;
    PmergeMe<std::deque<int> > sort_deque;
    PmergeMe<std::list<int> > sort_list;
    PmergeMe<std::vector<int> > sort_vector;

    get_args(nums_idx, &argv[1], succeed, nums_dq, nums_list, nums_vec);
    if (!succeed) {
        std::cout << YELLOW << "[Error] " << get_error_msg(argv[nums_idx + 1]) << RESET << std::endl;
        return EXIT_FAILURE;
    }

    /* before */
    nums_cnt = argc - 1;
    // sort_deque.sort(nums_dq);
    sort_list.sort(nums_list);
    sort_vector.sort(nums_vec);

    /* after */
    std_sorted = nums_vec;
    std::sort(std_sorted.begin(), std_sorted.end());

    // sorted_dq = sort_deque.get_sorted();
    sorted_vec = sort_vector.get_sorted();
    sorted_list = sort_list.get_sorted();

#ifdef DEBUG
    //--------------------------------------------------------------------------
    // before
    //--------------------------------------------------------------------------
    std::cout << std::endl;
    // std::cout << "Before(deque) : " << sort_deque.get_sequence() << std::endl;
    std::cout << "Before(list)  : " << sort_list.get_sequence() << std::endl;
    std::cout << "Before(vector): " << sort_vector.get_sequence() << std::endl;
    std::cout << std::endl;

    //--------------------------------------------------------------------------
    // after
    //--------------------------------------------------------------------------
    std::cout << "std::sort     : " << std_sorted << std::endl;
    // std::cout << "After(deque)  : " << result(std_sorted, sorted_dq) << std::endl;
    std::cout << "After(list)   : " << result(std_sorted, sorted_list) << std::endl;
    std::cout << "After(vector) : " << result(std_sorted, sorted_vec) << std::endl;
    std::cout << std::endl;
#else
    std::cout << "Before : " << sort_vector.get_sequence() << std::endl;
    std::cout << "After  : " << result(std_sorted, sorted_vec) << std::endl;
#endif
    //--------------------------------------------------------------------------
    // time
    //--------------------------------------------------------------------------
    // std::cout << runtime_msg(nums_cnt, "std::deque ") << " : "
    //           << std::fixed << std::setprecision(0) << sort_deque.get_process_time() << " us" << std::endl;

    std::cout << runtime_msg(nums_cnt, "std::list  ") << " : "
              << std::fixed << std::setprecision(0) << sort_list.get_process_time() << " us" << std::endl;

    std::cout << runtime_msg(nums_cnt, "std::vector") << " : "
              << std::fixed << std::setprecision(0) << sort_vector.get_process_time() << " us" << std::endl;

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
