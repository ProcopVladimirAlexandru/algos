#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "InsertionSort.h"
#include "SortingTester.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "PVAFile.h"
#include "VectorOperations.h"
#include "BaseSort.h"


void SortingTester::test(std::string input_file_path) {
    PVAFile pva_file = PVAFile(input_file_path);
    uint i = 0;
    std::vector<long double> input_vector = std::vector<long double>();
    std::vector<long double> expected_sorted_vector = std::vector<long double>();
    bool ascending = true;
    while (!pva_file.eof()) {
        if (i % 3 == 0) {
            input_vector.clear();
            pva_file.parse_line_to_vector_long_double(input_vector, ',');
        }
        else if (i % 3 == 1) {
            std::string line = pva_file.parse_raw_line();
            if (line == "asc" || line == "ascending") {
                ascending = true;
            }
            else if (line == "desc" || line == "descending") {
                ascending = false;
            }
            else {
                throw "unknown sorting order";
            }
        }
        else if (i % 3 == 2) {
            std::cout << "TEST NUMBER " << (i + 1) / 3 << ": sorting "
                << (vector_to_string<long double>(input_vector)) << std::endl;
            expected_sorted_vector.clear();
            pva_file.parse_line_to_vector_long_double(expected_sorted_vector, ',');

            BubbleSort bubble_sort("BubbleSort");
            InsertionSort insertion_sort("InsertionSort");
            SelectionSort selection_sort("SelectionSort");
            MergeSort merge_sort("MergeSort");
            std::vector<BaseSort *> sort_objects_vector = {&bubble_sort, &insertion_sort, &selection_sort, &merge_sort};
            for (auto sort_object : sort_objects_vector) {
                std::vector<long double> * sorted_vector = sort_object->get_sorted_vector(input_vector, ascending);
                if ((*sorted_vector) != expected_sorted_vector) {
                    std::cerr << sort_object->uid << " failed test" << std::endl;
                }
                else {
                    std::cout << sort_object->uid << " passed test" << std::endl;
                }

            }
            std::cout << std::endl;
        }
        ++i;
    }
}
