#include <iostream>
#include <vector>
#include <cmath>

#include "SubsetsTester.h"
#include "Subsets.h"
#include "VectorOperations.h"
#include "PVAMath.h"


void SubsetsTester::test() {

    Subsets ss_generator("SubsetsGenerator");

    std::vector<std::vector<unsigned long>> input_vs {
        {0},
        {0, 1},
        {0, 1, 2, 3},
        {1, 5, 7, 9, 100, 1000, 1234567890}
    };

    for (unsigned long i = 0; i < input_vs.size(); ++i) {
        auto & v = input_vs[i];
        unsigned long n = input_vs[i].size();

        std::cout << "TEST NUMBER " << i << ": Subsets(n = " << n << ")" << std::endl;
        auto subsets = ss_generator.get_subsets(v);
        bool passed = true;
        if (subsets.size() != (unsigned long)std::pow(2, n)) {
            std::cerr << ss_generator.uid << " failed cardinality test" << std::endl;
            print_vector(v, true);
            continue;
        }

        for (unsigned long si = 0; si < subsets.size(); si++) {
            if (!are_vector_elements_unique(subsets[si])) {
                passed = false;
                break;
            }
            for (unsigned long sj = si + 1; sj < subsets.size(); sj++) {
                if (are_vectors_equal(subsets[si], subsets[sj])) {
                    passed = false;
                    break;
                }
            }
        }
        if (passed) {
            std::cout << ss_generator.uid << " passed test" << std::endl;
        }
        else {
            std::cerr << ss_generator.uid << " failed test" << std::endl;
            print_vector(v, true);
        }
        std::cout << std::endl;
    }
}
