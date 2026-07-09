#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <vector>
#include <string>


class BinarySearch {
    public:
        std::string uid;
        BinarySearch(const char * uid);
        BinarySearch(std::string uid);
        long long find(std::vector<long double> &v, long double target);
        int compare_long_double(long double x, long double y);
};

#endif