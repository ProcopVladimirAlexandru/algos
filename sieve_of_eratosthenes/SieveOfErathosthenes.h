#ifndef SIEVEOFERATHOSTHENES_H
#define SIEVEOFERATHOSTHENES_H
#include <vector>

#include "Algorithm.h"

class SieveOfErathosthenes : public Algorithm {
    public:
        SieveOfErathosthenes (const char * uid);
        SieveOfErathosthenes (std::string uid);
        std::vector<unsigned long> get_primes_less_than_n(unsigned long n);
};
#endif
