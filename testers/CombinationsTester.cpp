#include <iostream>
#include <vector>

#include "CombinationsTester.h"
#include "Combinations.h"
#include "VectorOperations.h"
#include "PVAMath.h"


void CombinationsTester::test() {

    Combinations combs("CombinationsGenerator");

    std::vector<std::vector<unsigned long>> input_vs {
        {0},

        {0, 1},
        {0, 1},

        {0, 1, 2},
        {0, 1, 2},
        {0, 1, 2},

        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},

        {1, 5, 7, 9, 100, 1000, 1234567890},
        {1, 5, 7, 9, 100, 1000, 1234567890},
        {1, 5, 7, 9, 100, 1000, 1234567890}
    };
    std::vector<unsigned long> input_ks {1, 1, 2, 1, 2, 3, 1, 2, 3, 4, 1, 5, 7};

    for (unsigned long i = 0; i < input_vs.size(); ++i) {
        auto v = input_vs[i];
        unsigned long n = input_vs[i].size();
        unsigned long k = input_ks[i];

        std::cout << "TEST NUMBER " << i << ": Combinations(n = " << n << ", k = " << k << ")" << std::endl;
        auto combinations = combs.get_combinations(v, k);
        bool passed = true;
        if (combinations.size() != (PVAMath::factorial(n)/(PVAMath::factorial(n - k) * PVAMath::factorial(k)))) {
            std::cerr << combs.uid << " failed test" << std::endl;
            print_vector(v, true);
            continue;
        }

        for (unsigned long ci = 0; ci < combinations.size(); ci++) {
            if (combinations[ci].size() != k) {
                passed = false;
                break;
            }
            if (!are_vector_elements_unique(combinations[ci])) {
                passed = false;
                break;
            }
            for (unsigned long cj = ci + 1; cj < combinations.size() - 1; cj++) {
                if (are_vectors_equal(combinations[ci], combinations[cj])) {
                    passed = false;
                    break;
                }
            }
        }
            if (passed) {
                std::cout << combs.uid << " passed test" << std::endl;
            }
            else {
                std::cerr << combs.uid << " failed test" << std::endl;
                print_vector(input_vs[i], true);
            }
            std::cout << std::endl;
        }
}
