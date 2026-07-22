#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

#include <vector>

#include "Algorithm.h"


class Permutations : public Algorithm {
    public:
        Permutations (const char * uid);
        Permutations (std::string uid);
        std::vector<std::vector<unsigned long>> get_permutations(std::vector<unsigned long> & v, unsigned long current_index = 0);
};
#endif
