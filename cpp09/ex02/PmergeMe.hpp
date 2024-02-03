#pragma once

template <typename Container>
class PmergeMe {
 public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();

    PmergeMe &operator=(const PmergeMe &rhs);

    double get_process_time() const;
    std::size_t get_compare_cnt() const;
    const Container &get_sequence() const;
    const Container &get_sorted() const;

    void sort(const Container &arr);

 private:
    double process_time_us_;
    std::size_t compare_cnt_;
    Container sequence_;
    Container sorted_;

    double calc_process_time_us(timeval start, timeval end) const;
    std::string debug_print_elements(const Container &arr) const;

    Container merge_insertion_sort(const Container& arr);

    template<typename Iterator>
    void merge(Iterator first, Iterator mid, Iterator last) const;

    template<typename Iterator>
    void merge_sort(Iterator first, Iterator last) const;

    template <typename Iterator, typename T>
    Iterator lower_bound_(Iterator first, Iterator last, const T &val);
    };

# include "PmergeMe.tpp"
