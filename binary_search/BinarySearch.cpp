#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "BinarySearch.h"


BinarySearch::BinarySearch(const char * uid) {
    this->uid = std::string(uid);
}

BinarySearch::BinarySearch(std::string uid) {
    this->uid = uid;
}

long long BinarySearch::find(std::vector<long double> &v, long double target) {
    long long n = v.size();
    long long left_index = 0;
    long long right_index = n - 1;
    while (true) {
        long long diff = right_index - left_index;
        if (diff < 0) {
            return -1;
        }
        else if (diff == 0) {
            return (this->compare_long_double(v[left_index], target) == 0)?left_index:-1;
        }
        else if (diff == 1) {
            if (compare_long_double(v[left_index], target) == 0) {
                return left_index;
            }
            else if (this->compare_long_double(v[right_index], target) == 0) {
                return right_index;
            }
            return -1;
        }
        else {
            long long middle_index = left_index + std::floor(diff / 2);
            if (this->compare_long_double(v[middle_index], target) == 0) {
                return middle_index;
            }
            else if (target < v[middle_index]) {
                right_index = middle_index - 1;
            }
            else {
                left_index = middle_index + 1;
            }
        }
    }
    return -1;
}


int BinarySearch::compare_long_double(long double x, long double y) {
    long double limit = 1e-5;
    long double diff = x - y;
    if (diff <= 0) {
        if (diff >= -limit) {
            return 0;
        } else {
            return -1;
        }
    } else {
        if (diff <= limit) {
            return 0;
        } else {
            return 1;
        }
    }
}