#pragma once

template <typename Container>
class PmergeMe {
 public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();

    PmergeMe &operator=(const PmergeMe &rhs);

    double get_process_time() const;
    const Container &get_sequence() const;
    const Container &get_sorted() const;

    void sort(const Container &arr);

 private:
    double process_time_us_;
    Container sequence_;
    Container sorted_;

    Container merge_insertion_sort(const Container &arr) const;

    template <typename PairIterator>
    void merge(PairIterator first, PairIterator mid, PairIterator last) const;

    template <typename PairIterator>
    void merge_sort(PairIterator first, PairIterator last) const;

    double calc_process_time_us(timeval start, timeval end) const;
    std::string debug_print_elements(const Container &arr) const;
};

# include "PmergeMe.tpp"
