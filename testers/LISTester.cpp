#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "LISTester.h"
#include "LISN2.h"
#include "VectorOperations.h"


void LISTester::test() {

    LISN2 lis_n2("LISN2");

    std::vector<std::string> inputs{"", "ababczde", "ababczd", "a", "ad", "ruacbdzopb"};
    std::vector<std::string> expected_results{"", "abcde", "abcz", "a", "ad", "abdop"};
    for (long long i = 0; i < inputs.size(); ++i) {
        std::cout << "TEST NUMBER " << i << ": LISN2(\"" << inputs[i] << "\")" << std::endl;
        std::string result_lis = lis_n2.get_lis(inputs[i]);
        if (result_lis != expected_results[i]) {
            std::cerr << lis_n2.uid << " failed test" << std::endl;
        }
        else {
            std::cout << lis_n2.uid << " passed test, LIS = \"" << expected_results[i] << "\"" << std::endl;
        }
        std::cout << std::endl;
    }
}
