#ifndef CONTINUOUSKNAPSACK_H
#define CONTINUOUSKNAPSACK_H

#include <vector>

#include "Algorithm.h"


class ContinuousKnapsack : public Algorithm {
    public:
        ContinuousKnapsack (const char * uid);
        ContinuousKnapsack (std::string uid);
        std::vector<long double> get_quantities(long double W, std::vector<long double> & weights, std::vector<long double> & values);
};
#endif
