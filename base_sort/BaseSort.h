#ifndef BASESORT_H
#define BASESORT_H

#include <vector>
#include <string>


class BaseSort {
    public:
        std::string uid;
        BaseSort(const char * uid);
        BaseSort(std::string uid);
        virtual std::vector<long double> * get_sorted_vector(std::vector<long double> &v, bool ascending) = 0;
};

#endif