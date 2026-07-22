#include <vector>
#include <stdexcept>

#include "Permutations.h"
#include "Algorithm.h"


Permutations::Permutations(const char * uid) : Algorithm(uid) {};

Permutations::Permutations(std::string uid) :  Algorithm(uid) {};

std::vector<std::vector<unsigned long>> Permutations::get_permutations(std::vector<unsigned long> & v, unsigned long current_index) {
    unsigned long n = v.size();
    if (current_index == n - 1) {
        std::vector<unsigned long> single_permutation({v[current_index]});
        return std::vector<std::vector<unsigned long>>({single_permutation});
    }
    if (current_index >= n) {
        throw std::invalid_argument("current_index should not reach size of input");
    }

    std::vector<std::vector<unsigned long>> new_permutations;
    for (auto & permutation : this->get_permutations(v, current_index + 1)) {
        for (unsigned long index_to_insert = 0; index_to_insert <= permutation.size(); ++index_to_insert) {
            std::vector<unsigned long> new_permutation(permutation);
            new_permutation.insert(new_permutation.begin() + index_to_insert, v.at(current_index));
            new_permutations.push_back(new_permutation);
        }
    }
    return new_permutations;
}
