#include <vector>

#include "SelectionSort.h"


std::vector<long double> * SelectionSort::get_sorted_vector(std::vector<long double> &v, bool ascending) {
    std::vector<long double> & result = *(new std::vector<long double>(v));
    long long n = result.size();

    for (long long i = 0; i < n - 1; ++i) {
        for (long long j = i + 1; j < n; ++j) {
            bool swap = (ascending && result[j] < result[i]) ||
                            (!ascending && result[j] > result[i]);
            if (swap) {
                long double aux = result[i];
                result[i] = result[j];
                result[j] = aux;
            }
        }
    }
    return &result;
}