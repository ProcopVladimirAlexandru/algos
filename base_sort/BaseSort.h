#ifndef BASESORT_H
#define BASESORT_H

#include <vector>
#include <string>

#include "Algorithm.h"


class BaseSort : public Algorithm {
    public:
        BaseSort(const char * uid);
        BaseSort(std::string uid);
        virtual std::vector<long double> * get_sorted_vector(std::vector<long double> &v, bool ascending) = 0;
};

#endif
