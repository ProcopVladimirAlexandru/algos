#include <vector>
#include <stdexcept>

#include "Subsets.h"
#include "Algorithm.h"


Subsets::Subsets(const char * uid) : Algorithm(uid) {};

Subsets::Subsets(std::string uid) :  Algorithm(uid) {};

void Subsets::_collect_subsets(
    std::vector<std::vector<unsigned long>> & all_subsets,
    std::vector<unsigned long> & v,
    unsigned long current_index,
    std::vector<unsigned long> current_subset
)
{
    unsigned long n = v.size();
    if (current_index >= n) {
        throw std::invalid_argument("something went very wrong, current index >= n");
    }
    if (current_subset.size() >= n) {
        throw std::invalid_argument("something went very wrong, current set size >= n");
    }

    std::vector<bool> choices = {false, true};
    for (auto choice : choices) {
        if (choice) {
            current_subset.push_back(v[current_index]);
        }
        if (current_index == n - 1) {
            all_subsets.push_back(current_subset);
        }
        else {
            this->_collect_subsets(all_subsets, v, current_index + 1, current_subset);
        }
    }
}

std::vector<std::vector<unsigned long>> Subsets::get_subsets(std::vector<unsigned long> & v) {
    std::vector<std::vector<unsigned long>> all_subsets;
    std::vector<unsigned long> first_current_subset;
    this->_collect_subsets(all_subsets, v, 0, first_current_subset);
    return all_subsets;
}
