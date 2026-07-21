#ifndef KNAPSACK01_H
#define KNAPSACK01_H

#include <vector>
#include <map>
#include <utility>

#include "Algorithm.h"


class Knapsack01 : public Algorithm {
    public:
        Knapsack01 (const char * uid);
        Knapsack01 (std::string uid);
        std::vector<long double> get_quantities(long double W, std::vector<long double> & weights, std::vector<long double> & values);
    private:
        std::pair<long double, std::vector<long double> * > * _get_quantities(
            long double W,
            std::vector<long double> & weights,
            std::vector<long double> & values,
            unsigned long i,
            std::map<unsigned long, std::map<long double, std::pair<long double, std::vector<long double> * > * > * > * memo);
};
#endif
