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
    std::time_t process_time_us_;
    Container sequence_;
    Container sorted_;

    double calc_process_time_us(timeval start, timeval end) const;
    std::string debug_print_elements(const Container &arr) const;

    Container merge_insertion_sort(const Container &arr);

    template <typename Iterator>
    void merge(Iterator first, Iterator mid, Iterator last) const;

    template <typename Iterator>
    void merge_sort(Iterator first, Iterator last) const;
};

# include "PmergeMe.tpp"
