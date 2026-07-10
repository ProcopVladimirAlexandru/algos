#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "SearchTester.h"
#include "BinarySearch.h"
#include "PVAFile.h"
#include "VectorOperations.h"


void SearchTester::test(std::string input_file_path) {
    PVAFile pva_file = PVAFile(input_file_path);

    uint i = 0;
    std::vector<long double> input_vector = std::vector<long double>();
    long double target;
    long long expected_index;
    while (!pva_file.eof()) {
        if (i % 3 == 0) {
            input_vector.clear();
            pva_file.parse_line_to_vector_long_double(input_vector, ',');
        }
        else if (i % 3 == 1) {
            target = pva_file.parse_line_to_long_double();
        }
        else if (i % 3 == 2) {
            std::cout << "TEST NUMBER " << (i + 1) / 3 << ": searching for " << target << " in "
                << (vector_to_string<long double>(input_vector)) << std::endl;
            expected_index = pva_file.parse_line_to_long_long();

            BinarySearch binary_search("BinarySearch");
            long long result_index = binary_search.find(input_vector, target);
            if (result_index != expected_index) {
                std::cerr << binary_search.uid << " failed test" << std::endl;
            }
            else {
                std::cout << binary_search.uid << " passed test" << std::endl;
            }
            std::cout << std::endl;
        }
        ++i;
    }
}
