#include <iostream>
#include <vector>

#include "ArrangementsTester.h"
#include "Arrangements.h"
#include "VectorOperations.h"
#include "PVAMath.h"


void ArrangementsTester::test() {

    Arrangements arrangs("ArrangementsGenerator");

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

        std::cout << "TEST NUMBER " << i << ": Arrangements(n = " << n << ", k = " << k << ")" << std::endl;
        auto arrangements = arrangs.get_arrangements(v, k);
        bool passed = true;
        if (arrangements.size() != (PVAMath::factorial(n)/PVAMath::factorial(n - k))) {
            std::cerr << arrangs.uid << " failed cardinality test" << std::endl;
            print_vector(v, true);
            continue;
        }

        for (unsigned long ai = 0; ai < arrangements.size(); ai++) {
            if (arrangements[ai].size() != k) {
                passed = false;
                break;
            }
            if (!are_vector_elements_unique(arrangements[ai])) {
                passed = false;
                break;
            }
            for (unsigned long aj = ai + 1; aj < arrangements.size() - 1; aj++) {
                if (are_vectors_equal(arrangements[ai], arrangements[aj])) {
                    passed = false;
                    break;
                }
            }
        }
        if (passed) {
            std::cout << arrangs.uid << " passed test" << std::endl;
        }
        else {
            std::cerr << arrangs.uid << " failed test" << std::endl;
            print_vector(input_vs[i], true);
            break;
        }
        std::cout << std::endl;
    }
}
