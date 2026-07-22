#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include <vector>

#include "Algorithm.h"


class Combinations : public Algorithm {
    public:
        Combinations (const char * uid);
        Combinations (std::string uid);
        std::vector<std::vector<unsigned long>> get_combinations(std::vector<unsigned long> & v, unsigned long k);
    private:
        void _collect_combinations(
            std::vector<std::vector<unsigned long>> & combinations,
            std::vector<unsigned long> & v,
            unsigned long k,
            long long last_index,
            std::vector<unsigned long> last_combination);
};
#endif
