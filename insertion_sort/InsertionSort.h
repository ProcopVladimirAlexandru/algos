#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>
#include <string>

#include "BaseSort.h"


class InsertionSort : public BaseSort {
    public:
        InsertionSort(const char * uid);
        InsertionSort(std::string uid);
        std::vector<long double> get_sorted_vector(std::vector<long double> &v, bool ascending);
};

#endif
