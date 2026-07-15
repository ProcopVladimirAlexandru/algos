#include<vector>
#include<iostream>

#include "SieveOfErathosthenes.h"
#include "Algorithm.h"
#include "VectorOperations.h"


SieveOfErathosthenes::SieveOfErathosthenes(const char * uid) : Algorithm(uid) {};

SieveOfErathosthenes::SieveOfErathosthenes(std::string uid) :  Algorithm(uid) {};

std::vector<unsigned long> SieveOfErathosthenes::get_primes_less_than_n(unsigned long n) {
    std::vector<unsigned long> result;
    std::vector<unsigned long> els;
    std::vector<bool> marked;
    for (unsigned long i = 2; i <= n; ++i) {
        els.push_back(i);
        marked.push_back(false);
    }

    unsigned long i = 0;
    while ( i < els.size() ) {
        if (marked[i]) {
            i++;
        }
        else {
            result.push_back(els[i]);
            unsigned long j = i + els[i];
            while (j < marked.size()) {
                marked[j] = true;
                j += els[i];
            }
            i++;
        }
    }
    return result;
}


/*
int main() {
    SieveOfErathosthenes soe("soe");
    unsigned long n = 2;
    std::vector<unsigned long> result = soe.get_primes_less_than_n(n);
    std::cout << "Found " << result.size() << " Primes <= " << n << ": " << std::endl;
    print_vector<unsigned long>(result, true);
    return 0;
}
*/
