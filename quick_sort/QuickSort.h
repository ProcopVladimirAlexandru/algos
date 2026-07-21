#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <string>

#include "BaseSort.h"


class QuickSort : public BaseSort {
    public:
        QuickSort (const char * uid);
        QuickSort (std::string uid);
        std::vector<long double> get_sorted_vector(std::vector<long double> &v, bool ascending);
    private:
        void _quicksort_in_place(std::vector<long double> & v, bool ascending, long long left, long long to);
};

#endif
