#include <utility>
#include <stdexcept>
#include <algorithm>

#include "Knapsack01.h"
#include "Algorithm.h"


Knapsack01::Knapsack01(const char * uid) : Algorithm(uid) {};

Knapsack01::Knapsack01(std::string uid) :  Algorithm(uid) {};

std::pair<long double, std::vector<long double> * > * Knapsack01::_get_quantities(
            long double W,
            std::vector<long double> & weights,
            std::vector<long double> & values,
            unsigned long i,
            std::map<unsigned long, std::map<long double, std::pair<long double, std::vector<long double> * > * > * > * memo) {
    unsigned long n = weights.size();
    if (i >= n) {
        auto result_vector = new std::vector<long double>();
        long double result_value = 0.0;
        auto result = new std::pair<long double, std::vector<long double> * >(result_value, result_vector);
        return result;
    }
    if (memo->contains(i)) {
        std::map<long double, std::pair<long double, std::vector<long double> * > * > * per_weight_memo = memo->at(i);
        if (per_weight_memo->contains(W)) {
            return per_weight_memo->at(W);
        }
    }
    else {
        auto memo_for_i = new std::map<long double, std::pair<long double, std::vector<long double>*>*>();
        (*memo)[i] = memo_for_i;
    }

    std::pair<long double, std::vector<long double> * > * result = nullptr;
    if (weights[i] > W) {
        result = this->_get_quantities(
            W, weights, values, i + 1, memo
        );
    }
    else {
        auto result_not_including_i = this->_get_quantities(
            W, weights, values, i + 1, memo
        );
        auto result_including_i = this->_get_quantities(
            W - weights[i], weights, values, i + 1, memo
        );
        result = (result_not_including_i->first > result_including_i->first)?result_not_including_i:result_including_i;
        if (result == result_including_i) {
            result->first += weights[i];
            result->second->push_back(1);
        } else {
            result->second->push_back(0);
        }
    }
    (*((*memo)[i]))[W] = result;
    return result;
}

std::vector<long double> Knapsack01::get_quantities(long double W, std::vector<long double> & weights, std::vector<long double> & values) {
    // TODO: delete heap allocations!
    if (W <= 0) {
        throw std::invalid_argument("knapsack capacity should be positive");
    }
    unsigned long n = weights.size();
    unsigned long n_ = values.size();
    if (n != n_) {
        throw std::invalid_argument("weights and values must have equal length");
    }
    if (n == 0) {
        throw std::invalid_argument("you must provide some weights and values");
    }
    std::map<unsigned long, std::map<long double, std::pair<long double, std::vector<long double>*>*>*> memo;
    return std::vector(*((this->_get_quantities(W, weights, values, 0, &memo))->second));
}
