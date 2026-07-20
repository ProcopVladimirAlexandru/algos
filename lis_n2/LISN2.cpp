#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "LISN2.h"
#include "Algorithm.h"



LISN2::LISN2(const char * uid) : Algorithm(uid) {};

LISN2::LISN2(std::string uid) :  Algorithm(uid) {};


std::string LISN2::get_lis(std::string s) {
    long long n = s.size();
    if (n == 0) {
        return std::string("");
    }
    std::vector<long long> lis_lengths;
    std::string result;
    std::vector<long long> p;
    for (long long i = 0; i < n; ++i) {
        lis_lengths.push_back(1);
        p.push_back(-1);
    }

    long long max_index = 0;
    long long max_lis_length = 1;
    for (long long i = 1; i < n; ++i) {
        for (long long j = i - 1; j >= 0; --j) {
            if ( s[i] > s[j] ) {
                if (lis_lengths[j] + 1 > lis_lengths[i]) {
                    lis_lengths[i] = lis_lengths[j] + 1;
                    p[i] = j;
                }
            }
        }
        if (lis_lengths[i] > max_lis_length) {
            max_lis_length = lis_lengths[i];
            max_index = i;
        }
    }

    long long i = max_index;
    while(true) {
        result.push_back(s[i]);
        if (p[i] == -1) {
            break;
        }
        i = p[i];
    }
    return std::string(result.rbegin(), result.rend());
}
