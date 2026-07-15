#ifndef EUCLIDGCD_H
#define EUCLIDGCD_H
#include "Algorithm.h"

class EuclidGCD : public Algorithm {
    public:
        EuclidGCD (const char * uid);
        EuclidGCD (std::string uid);
        unsigned long get_gcd(unsigned long a, unsigned long b);
};
#endif
