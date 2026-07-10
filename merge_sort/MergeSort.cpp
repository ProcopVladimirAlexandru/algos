#include <vector>
#include <string>
#include <cmath>

#include "MergeSort.h"


MergeSort::MergeSort(const char * uid) : BaseSort(uid) {};

MergeSort::MergeSort(std::string uid) :  BaseSort(uid) {};


std::vector<long double> MergeSort::_get_merged_vector(std::vector<long double> v_1, std::vector<long double> v_2, bool ascending) {
    unsigned long long i_1 = 0;
    unsigned long long i_2 = 0;
    unsigned long long n_1 = v_1.size();
    unsigned long long n_2 = v_2.size();
    std::vector<long double> result;

    while (true) {
        if (i_1 == n_1) {
            if (i_2 == n_2) {
                return result;
            }
            result.push_back(v_2.at(i_2++));
        }
        else {
            if (i_2 == n_2) {
                result.push_back(v_1.at(i_1++));
            }
            else {
                if (v_1.at(i_1) <= v_2.at(i_2)) {
                    if (ascending) {
                        result.push_back(v_1.at(i_1++));
                    }
                    else {
                        result.push_back(v_2.at(i_2++));
                    }
                }
                else {
                    if (ascending) {
                        result.push_back(v_2.at(i_2++));
                    }
                    else {
                        result.push_back(v_1.at(i_1++));
                    }
                }
            }
        }
    }
}

std::vector<long double> MergeSort::_get_merge_sorted_vector(
        std::vector<long double> &v, bool ascending, unsigned long left_index, unsigned long right_index
) {
    if (left_index > right_index) {
        return std::vector<long double>();
    }
    if (left_index == right_index) {
        return std::vector<long double>({v.at(left_index)});
    }
    if (left_index == right_index - 1) {
        if (ascending) {
            if (v.at(left_index) <= v.at(right_index)) {
                return std::vector<long double>({v.at(left_index), v.at(right_index)});
            }
            else {
                return std::vector<long double>({v.at(right_index), v.at(left_index)});
            }
        }
        else {
            if (v.at(left_index) >= v.at(right_index)) {
                return std::vector<long double>({v.at(left_index), v.at(right_index)});
            }
            else {
                return std::vector<long double>({v.at(right_index), v.at(left_index)});
            }
        }
    }
    unsigned long middle_index = left_index + std::floor( right_index - left_index );
    return this->_get_merged_vector(
        this->_get_merge_sorted_vector( v, ascending, left_index, middle_index - 1),
        this->_get_merge_sorted_vector( v, ascending, middle_index, right_index),
        ascending
    );
}

std::vector<long double> * MergeSort::get_sorted_vector(std::vector<long double> &v, bool ascending) {
    if (v.empty()) {
        return new std::vector<long double>();
    }
    return (new std::vector<long double>(this->_get_merge_sorted_vector(v, ascending, 0, v.size() - 1)));
}
