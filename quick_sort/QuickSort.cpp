#include <vector>
#include <string>

#include "QuickSort.h"
#include "VectorOperations.h"


QuickSort::QuickSort(const char * uid) : BaseSort(uid) {};

QuickSort::QuickSort(std::string uid) :  BaseSort(uid) {};


void QuickSort::_quicksort_in_place(std::vector<long double> & v, bool ascending, long long from, long long to) {
    if (from >= (v.size() - 1) || to > v.size()) {
        return;
    }
    if (from == to) {
        return;
    }
    if (from == to - 1) {
        return;
    }
    if (from == to - 2) {
        if (ascending) {
            if (v[from] > v[to - 1]) {
                swap_vector_elements(v, from, to - 1);
            }
        }
        else {
            if (v[from] < v[to - 1]) {
                swap_vector_elements(v, from, to - 1);
            }
        }
    }

    unsigned long pivot_index = from;
    unsigned long candidate_index = pivot_index + 1;
    while (candidate_index < to) {
        if ((ascending && v[candidate_index] < v[pivot_index]) || (!ascending && v[candidate_index] > v[pivot_index])) {
            swap_vector_elements(v, pivot_index, pivot_index++);
            if (pivot_index < candidate_index) {
                swap_vector_elements(v, pivot_index - 1, candidate_index);
            }
        }
        candidate_index += 1;
    }

    this->_quicksort_in_place(v, ascending, from, pivot_index);
    this->_quicksort_in_place(v, ascending, pivot_index + 1, to);
}

std::vector<long double> QuickSort::get_sorted_vector(std::vector<long double> &v, bool ascending) {
    std::vector<long double>result(v);
    long long n = result.size();
    if (n == 0) {
        return result;
    }
    this->_quicksort_in_place(result, ascending, 0, n);
    return result;
}
