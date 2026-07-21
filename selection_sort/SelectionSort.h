#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>
#include <string>

#include "BaseSort.h"


class SelectionSort : public BaseSort {
    public:
        SelectionSort(const char * uid);
        SelectionSort(std::string uid);
        std::vector<long double> get_sorted_vector(std::vector<long double> &v, bool ascending);
};

#endif
