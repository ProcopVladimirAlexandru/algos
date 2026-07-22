#include <iostream>
#include <vector>

#include "PermutationsTester.h"
#include "Permutations.h"
#include "VectorOperations.h"
#include "PVAMath.h"


void PermutationsTester::_report_test_result(Permutations & perms, std::vector<unsigned long> & v, bool passed) {
    if (!passed) {
        std::cerr << perms.uid << " failed test" << std::endl;
        print_vector(v, true);
    }
    else {
        std::cout << perms.uid << " passed test" << std::endl;
    }
    std::cout << std::endl;
}

void PermutationsTester::test() {

    Permutations perms("PermutationsGenerator");

    std::vector<std::vector<unsigned long>> inputs {
        {0},
        {0, 1},
        {0, 1, 2},
        {0, 1, 2, 3},
        {1, 5, 7, 9, 100, 1000, 1234567890}
    };
    for (unsigned long i = 0; i < inputs.size(); ++i) {
        std::cout << "TEST NUMBER " << i << ": Permutations(" << inputs[i].size() << ")" << std::endl;
        auto permutations = perms.get_permutations(inputs[i]);
        bool passed = true;
        if (permutations.size() != PVAMath::factorial(inputs[i].size())) {
            this->_report_test_result(perms, inputs[i], false);
            continue;
        }

        for (unsigned long pi = 0; pi < permutations.size(); pi++) {
            if (permutations[pi].size() != inputs[i].size()) {
                this->_report_test_result(perms, inputs[i], false);
                passed = false;
                break;
            }
            if (!are_vector_elements_unique(permutations[pi])) {
                this->_report_test_result(perms, inputs[i], false);
                passed = false;
                break;
            }
            for (unsigned long pj = pi + 1; pj < permutations.size() - 1; pj++) {
                if (are_vectors_equal(permutations[pi], permutations[pj])) {
                    this->_report_test_result(perms, inputs[i], false);
                    passed = false;
                    break;
                }
            }
        }
        if (passed) {
            this->_report_test_result(perms, inputs[i], true);
        }
    }
}
