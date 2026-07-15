#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "ContinuousKnapsack.h"
#include "ContinuousKnapsackTester.h"
#include "PVAFile.h"
#include "VectorOperations.h"


void ContinuousKnapsackTester::test(std::string input_file_path) {
    PVAFile pva_file = PVAFile(input_file_path);

    unsigned long i = 0;
    unsigned long rows_per_test = 4;
    long double W;
    std::vector<long double> weights;
    std::vector<long double> values;
    std::vector<long double> expected_quantities;
    while (!pva_file.eof()) {
        if (i % rows_per_test  == 0) {
            W = pva_file.parse_line_to_long_double();
        }
        else if (i % rows_per_test  == 1) {
            weights.clear();
            pva_file.parse_line_to_vector_long_double(weights, ',');
        }
        else if (i % rows_per_test  == 2) {
            values.clear();
            pva_file.parse_line_to_vector_long_double(values, ',');
        }
        else if (i % rows_per_test  == 3) {
            std::cout << "TEST NUMBER " << (i + 1) / rows_per_test  << ": continuous knapsack of capacity " << W << " over " << weights.size() << " elements " << std::endl;
            expected_quantities.clear();
            pva_file.parse_line_to_vector_long_double(expected_quantities, ',');
            ContinuousKnapsack ck("ContinuousKnapsack");
            std::vector<long double> result_quantities = ck.get_quantities(W, weights, values);
            if (!are_vectors_equal(result_quantities, expected_quantities)) {
                std::cerr << ck.uid << " failed test" << std::endl;
                print_vector(result_quantities, true);
            }
            else {
                std::cout << ck.uid << " passed test" << std::endl;
            }
            std::cout << std::endl;
        }
        ++i;
    }
}
