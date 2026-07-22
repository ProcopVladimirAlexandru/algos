#ifndef PERMUTATIONSTESTER_H
#define PERMUTATIONSTESTER_H

#include <vector>

#include "Permutations.h"


class PermutationsTester {
    public:
        void test();
    private:
        void _report_test_result(Permutations &perms, std::vector<unsigned long> & v, bool passed);
};

#endif
