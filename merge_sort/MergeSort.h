#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <string>

#include "BaseSort.h"


class MergeSort : public BaseSort {
    public:
        MergeSort(const char * uid);
        MergeSort(std::string uid);
        std::vector<long double> _get_merged_vector(std::vector<long double> v_1, std::vector<long double> v_2, bool ascending);
        std::vector<long double> _get_merge_sorted_vector(std::vector<long double> &v, bool ascending, unsigned long left_index, unsigned long right_index);
        std::vector<long double> * get_sorted_vector(std::vector<long double> &v, bool ascending);
};

#endif
