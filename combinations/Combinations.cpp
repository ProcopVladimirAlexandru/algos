#include <vector>
#include <stdexcept>

#include "Combinations.h"
#include "Algorithm.h"


Combinations::Combinations(const char * uid) : Algorithm(uid) {};

Combinations::Combinations(std::string uid) :  Algorithm(uid) {};

void Combinations::_collect_combinations(
        std::vector<std::vector<unsigned long>> & combinations,
        std::vector<unsigned long> & v,
        unsigned long k,
        long long last_index,
        std::vector<unsigned long> last_combination)
{
    long long n = v.size();
    if (last_combination.size() > k) {
        throw std::invalid_argument("something went very wrong, combination size greater than k");
    }

    if (last_combination.size() == k) {
        combinations.push_back(last_combination);
        return;
    }

    if (last_index >= n) {
        throw std::invalid_argument("something went very wrong, combination last index out of bounds");
    }

    for (long long current_index = last_index + 1; current_index < n; current_index++) {
        std::vector<unsigned long> new_combination(last_combination);
        new_combination.push_back(v[current_index]);
        this->_collect_combinations(combinations, v, k, current_index, new_combination);
    }
}

std::vector<std::vector<unsigned long>> Combinations::get_combinations(std::vector<unsigned long> & v, unsigned long k) {
    // TODO cleanup heap memory
    unsigned long n = v.size();
    if (n == 0) {
        return std::vector<std::vector<unsigned long>>();
    }
    if (k > n) {
        throw std::invalid_argument("n must be greater or equal to k");
    }
    std::vector<std::vector<unsigned long>>combinations;
    std::vector<unsigned long> current_combination;
    this->_collect_combinations(combinations, v, k, -1, current_combination);
    return combinations;
}
