#include <vector>
#include <string>

#include "InsertionSort.h"


InsertionSort::InsertionSort(const char * uid) : BaseSort(uid) {};

InsertionSort::InsertionSort(std::string uid) :  BaseSort(uid) {};

std::vector<long double> * InsertionSort::get_sorted_vector(std::vector<long double> &v, bool ascending) {
    std::vector<long double> & result = *(new std::vector<long double>(v));
    long long n = result.size();

    for (long long i = 1; i < n; ++i) {
        for (long long j = i; j > 0; --j) {
            bool swap = (ascending && result[j] < result[j - 1]) ||
                            (!ascending && result[j] > result[j - 1]);
            if (swap) {
                long double aux = result[j];
                result[j] = result[j - 1];
                result[j - 1] = aux;
            }
        }
    }

    return &result;
}