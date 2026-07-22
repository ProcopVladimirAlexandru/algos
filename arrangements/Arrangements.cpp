#include <vector>
#include <stdexcept>

#include "Arrangements.h"
#include "Algorithm.h"
#include "Combinations.h"
#include "Permutations.h"


Arrangements::Arrangements(const char * uid) : Algorithm(uid) {};

Arrangements::Arrangements(std::string uid) :  Algorithm(uid) {};

std::vector<std::vector<unsigned long>> Arrangements::get_arrangements(std::vector<unsigned long> & v, unsigned long k) {
    std::vector<std::vector<unsigned long>> result;
    Combinations combs("CombinationsGenerator");
    Permutations perms("PermutationsGenerator");
    std::vector<std::vector<unsigned long>> combinations = combs.get_combinations(v, k);
    for (auto & comb : combinations) {
        std::vector<std::vector<unsigned long>> permutations = perms.get_permutations(comb);
        for (auto & perm : permutations) {
            result.push_back(perm);
        }
    }
    return result;
}
