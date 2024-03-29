#pragma once

# include <sys/time.h>
# include <algorithm>
# include <utility>
# include <iostream>
# include <sstream>

# define RED        "\x1b[31m"
# define GREEN      "\x1b[32m"
# define YELLOW     "\x1b[33m"
# define BLUE       "\x1b[34m"
# define MAGENTA    "\x1b[35m"
# define CYAN       "\x1b[36m"
# define RESET      "\x1b[0m"

template <typename Container>
PmergeMe<Container>::PmergeMe()
    : process_time_us_(0),
      sequence_(),
      sorted_() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container> &other) {
    *this = other;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe<Container>() {}

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe<Container> &rhs) {
    if (this == &rhs) {
        return *this;
    }
    this->process_time_us_ = rhs.process_time_us_;
    this->compare_cnt_ = rhs.compare_cnt_;
    this->sequence_ = rhs.sequence_;
    this->sorted_ = rhs.sorted_;
    return *this;
}

template <typename Container>
double PmergeMe<Container>::get_process_time() const {
    return process_time_us_;
}

template <typename Container>
const Container &PmergeMe<Container>::get_sequence() const {
    return sequence_;
}

template <typename Container>
const Container &PmergeMe<Container>::get_sorted() const {
    return sorted_;
}

/* Merge insertion Sort
 * https://github.com/decidedlyso/merge-insertion-sort
 *
 * sequences  : [3 1 4 1 5 9 2 6 5]
 *
 * sep        : (3, 1), (4, 1), (5, 9), (2, 6)   5
 * (a, b)pair : (1, 3), (1, 4), (5, 9), (2, 6)   5
 *
 * sort by a  : (1, 3), (1, 4), (2, 6), (5, 9)   5
 *               |_______^_______^______^ sorted
 *
 * main chain : [1 1 2 5]
 * b_arr      : [3 4 6 9]   5
 *
 * insert b to main chain by binary search, upper or lower is a
 *      3(1)  : [1 1 2 5]
 *               |    ^
 *
 *      4(1)  : [1 1 2 3 5]
 *               |      ^
 *
 *      6(2)  : [1 1 2 3 4 5]
 *                   |      ^
 *
 *      9(5)  : [1 1 2 3 4 5 6]
 *                         |  ^
 *
 *      5     : [1 1 2 3 4 5 6 9]
 *                         ^
 */
template <typename Container>
void PmergeMe<Container>::sort(const Container &arr) {
    timeval start_time = {}, end_time = {};

    this->sequence_ = arr;
    gettimeofday(&start_time, NULL);
    this->sorted_ = merge_insertion_sort(arr);
    gettimeofday(&end_time, NULL);
    process_time_us_ = calc_process_time_us(start_time, end_time);
}

template <typename Container>
template <typename PairIterator>
void PmergeMe<Container>::merge(PairIterator first, PairIterator mid, PairIterator last) const {
    typedef typename std::iterator_traits<PairIterator>::value_type ItrType;
    typedef typename Container::value_type ValueType;
    std::vector<ItrType> merged(std::distance(first, last));
    PairIterator left, right, merged_elem;
    ValueType a_left, a_right;

    left = first;
    right = mid;
    merged_elem = merged.begin();
    while (left < mid && right < last) {
        a_left = (*left).first;
        a_right = (*right).first;

        if (a_left <= a_right) {
            *merged_elem = *left;
            ++left;
        } else {
            *merged_elem = *right;
            ++right;
        }
        ++merged_elem;
    }

    while (left < mid) {
        *merged_elem = *left;
        ++merged_elem;
        ++left;
    }

    while (right < last) {
        *merged_elem = *right;
        ++merged_elem;
        ++right;
    }

    std::copy(merged.begin(), merged.end(), first);
}

template <typename Container>
template <typename PairIterator>
void PmergeMe<Container>::merge_sort(PairIterator first, PairIterator last) const {
    PairIterator mid;

    if (std::distance(first, last) > 1) {
        mid = first + std::distance(first, last) / 2;
        merge_sort(first, mid);
        merge_sort(mid, last);
        merge(first, mid, last);
    }
}

template <typename Container>
Container PmergeMe<Container>::merge_insertion_sort(const Container &arr) const {
    const bool IS_ODD = arr.size() % 2 != 0;
    typedef typename Container::value_type ValueType;
    typename Container::const_iterator elem, next_elem;
    typename Container::iterator insert_pos;
    typename std::vector<std::pair<ValueType, ValueType> > pairs;
    typename std::vector<std::pair<ValueType, ValueType> >::iterator pair;
    ValueType a, b, last_elem;
    Container sorted;

    elem = arr.begin();
    for (size_t i = 0; i < arr.size() - IS_ODD; i += 2) {
        next_elem = elem;
        ++next_elem;

        a = std::min(*elem, *next_elem);
        b = std::max(*elem, *next_elem);
        pairs.push_back(std::make_pair(a, b));

        ++elem;
        ++elem;
    }

    if (IS_ODD) {
        last_elem = *elem;
    }

    merge_sort(pairs.begin(), pairs.end());

    for (pair = pairs.begin(); pair != pairs.end(); ++pair) {
        a = pair->first;
        sorted.push_back(a);
    }

    // std::cout << "arr_a : " << debug_print_elements(sorted) << std::endl;
    // Container tmp_b;
    // for (pair = pairs.begin(); pair != pairs.end(); ++pair) {
    //     tmp_b.push_back(pair->second);
    // }
    // std::cout << "arr_b : " << debug_print_elements(tmp_b) << std::endl;

    for (pair = pairs.begin(); pair != pairs.end(); ++pair) {
        b = pair->second;
        insert_pos = std::lower_bound(sorted.begin(), sorted.end(), b);
        sorted.insert(insert_pos, b);
        // std::cout << "sorted: " << debug_print_elements(sorted) << std::endl;
    }
    // std::cout << std::endl;

    if (IS_ODD) {
        insert_pos = std::lower_bound(sorted.begin(), sorted.end(), last_elem);
        sorted.insert(insert_pos, last_elem);
    }
    return sorted;
}

template <typename Container>
double PmergeMe<Container>::calc_process_time_us(timeval start, timeval end) const {
    const double SEC_TO_USEC = 1000 * 1000;
    double process_time_us, sec, usec;

    sec  = static_cast<double>(end.tv_sec) - static_cast<double>(start.tv_sec);
    usec = static_cast<double>(end.tv_usec) - static_cast<double>(start.tv_usec);
    process_time_us = sec * SEC_TO_USEC + usec;

    return process_time_us;
}

template <typename Container>
std::string PmergeMe<Container>::debug_print_elements(const Container &arr) const {
    typename Container::const_iterator itr;
    std::stringstream ss;

    ss << "[";
    for (itr = arr.begin(); itr != arr.end(); ++itr) {
        ss << *itr;
        if (itr + 1 != arr.end()) {
            ss << " ";
        }
    }
    ss << "]";
    return ss.str();
}
