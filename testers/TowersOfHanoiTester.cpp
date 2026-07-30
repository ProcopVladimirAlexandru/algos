#include <iostream>
#include <string>
#include <vector>

#include "TowersOfHanoiTester.h"
#include "TowersOfHanoi.h"
#include "VectorOperations.h"


void TowersOfHanoiTester::test() {
    std::vector<unsigned long> input_ns = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned long test_count = input_ns.size();
    unsigned long tower_count = 3;
    for (unsigned long i = 0; i < test_count; ++i) {
        unsigned long n = input_ns[i];
        std::cout << "TEST NUMBER " << (i + 1) <<  "/" << test_count << ": TowersOfHanoi(" << n << ")" << std::endl;

        TowersOfHanoi toh("TowersOfHanoi", tower_count , n);
        std::vector<std::vector<unsigned long>> result = toh.solve();
        if (result[0].size()) {
            std::cerr << toh.uid << " failed test for n = " << n << " first tower should be empty" << std::endl;
        }

        unsigned long empty_towers = 1;
        unsigned long full_towers = (n == 0)?1:0;
        for (unsigned long ti = 1; ti < result.size(); ti++) {
            if (result[ti].size() == 0) {
                empty_towers++;
            }
            if (result[ti].size() == n) {
                bool is_tower_correct = true;
                for (unsigned ri = 1; ri < result[ri].size(); ri++) {
                    if (result[ti][ri] != result[ti][ri - 1] - 1) {
                        is_tower_correct = false;
                        break;
                    }
                }
                if (is_tower_correct) {
                    full_towers++;
                }
            }
        }
        if (empty_towers != tower_count  - 1 && n > 0) {
            std::cerr << toh.uid << " failed test for n = " << n << ", found " << empty_towers << " empty towers" << std::endl;
        }
        else if ((n > 0 && full_towers != 1) || (n == 0 && full_towers != tower_count)) {
            std::cerr << toh.uid << " failed test for n = " << n << ", found " << full_towers << " full towers" << std::endl;
        }
        else {
            std::cout << toh.uid << " passed test for n = " << n << std::endl;
        }
        std::cout << std::endl;
    }
}
