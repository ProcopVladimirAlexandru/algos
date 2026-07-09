#include <vector>
#include <string>

#include "BubbleSort.h"
#include "BaseSort.h"


BubbleSort::BubbleSort(const char * uid) : BaseSort(uid) {};

BubbleSort::BubbleSort(std::string uid) :  BaseSort(uid) {};

std::vector<long double> * BubbleSort::get_sorted_vector(std::vector<long double> &v, bool ascending) {
    std::vector<long double> & result = *(new std::vector<long double>(v));
    long long n = result.size();
    for (long long j = 0; j < n - 1; ++j) {
        for (long long i = 0; i < n - 1; ++i) {
            bool swap = (ascending && result[i] > result[i + 1]) ||
                            (!ascending && result[i] < result[i + 1]);
            if (swap) {
                long double aux = result[i];
                result[i] = result[i + 1];
                result[i + 1] = aux;
            }
        }
    }
    return &result;
}