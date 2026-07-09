#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>
#include <string>

#include "BaseSort.h"


class BubbleSort : public BaseSort {
    public:
        BubbleSort(const char * uid);
        BubbleSort(std::string uid);
        std::vector<long double> * get_sorted_vector(std::vector<long double> &v, bool ascending);
};

#endif