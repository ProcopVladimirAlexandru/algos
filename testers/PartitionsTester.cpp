#include <iostream>
#include <vector>
#include <cmath>

#include "PartitionsTester.h"
#include "Partitions.h"
#include "VectorOperations.h"
#include "PVAMath.h"


void PartitionsTester::test() {

    Partitions partitions_generator("PartitionsGenerator");

    std::vector<std::vector<unsigned long>> input_vs {
        //{0},
        //{0, 1},
        {0, 1, 2, 3},
        {1, 2, 3, 4, 5},
        {1, 5, 7, 9, 100, 1000, 1234567890}
    };

    for (unsigned long i = 0; i < input_vs.size(); ++i) {
        std::vector<unsigned long> v = input_vs[i];
        unsigned long n = input_vs[i].size();

        std::cout << "TEST NUMBER " << i << ": Partitions(n = " << n << ")" << std::endl;
        auto partitions = partitions_generator.get_partitions(v);
        if (partitions.size() != PVAMath::bell_number(n)) {
            std::cerr << partitions_generator.uid << " failed cardinality test, returned " << partitions.size() << " partitions" << std::endl;
            print_vector(v, true);
            continue;
        }

        bool passed = true;
        bool partition_elements_count_passed = true;
        bool disjoint_partition_elements_passed = true;
        for (unsigned long pi = 0; pi < partitions.size(); pi++) {
            unsigned long total_partition_elements = 0;
            for (unsigned long si = 0; si < partitions[pi].size(); si++) {
                total_partition_elements += partitions[pi][si].size();
                for (unsigned long sj = si + 1; sj < partitions[pi].size(); sj++) {
                    if (!are_vectors_disjoint(partitions[pi][si], partitions[pi][sj])) {
                        passed = false;
                        disjoint_partition_elements_passed = false;
                        break;
                    }
                }
            }
            if (total_partition_elements != n) {
                passed = false;
                partition_elements_count_passed = false;
            }
        }
        if (passed) {
            std::cout << partitions_generator.uid << " passed test" << std::endl;
        }
        else {
            std::cerr << partitions_generator.uid << " failed test: partition_elements_count_passed is " << partition_elements_count_passed <<
                ", disjoint_partition_elements_passed is "<< disjoint_partition_elements_passed << std::endl;
            print_vector(v, true);
        }
        std::cout << std::endl;
    }
}
