#include <utility>
#include <stdexcept>
#include <algorithm>

#include "ContinuousKnapsack.h"
#include "Algorithm.h"


ContinuousKnapsack::ContinuousKnapsack(const char * uid) : Algorithm(uid) {};

ContinuousKnapsack::ContinuousKnapsack(std::string uid) :  Algorithm(uid) {};

std::vector<long double> ContinuousKnapsack::get_quantities(long double W, std::vector<long double> & weights, std::vector<long double> & values) {
    std::vector<std::pair<long double, unsigned long>> tuples;

    unsigned long n = weights.size();
    unsigned long n_ = values.size();
    if (n != n_) {
        throw std::invalid_argument("weights and values must have equal length");
    }
    std::vector<long double> results(n);
    for (unsigned long i = 0; i < n; ++i) {
        if (weights.at(i) <= 1e-8) {
            throw std::invalid_argument("weights must be positive");
        }
        long double unit_value = values.at(i) / weights.at(i);
        std::pair<long double, unsigned long> tup(unit_value, i);
        tuples.push_back(tup);
    }

    struct
    {
        bool operator()(std::pair<long double, unsigned long> tup1, std::pair<long double, unsigned long> tup2) const {
            return tup1.first > tup2.first;
        }
    }
    customLess;
    std::sort(tuples.begin(), tuples.end(), customLess);

    long double current_weight = 0.0;
    for (unsigned long i = 0; i < n; ++i){
        unsigned long el_index = tuples.at(i).second;
        long double w = weights[el_index];
        long double weight_diff = W - current_weight;
        if (weight_diff > w) {
            results[el_index] = w;
            current_weight += w;
        }
        else {
            results[el_index] = weight_diff;
            current_weight += weight_diff;
            return results;
        }
    }
    return results;
}
