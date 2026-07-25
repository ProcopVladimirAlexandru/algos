#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "GCDTester.h"
#include "EuclidGCD.h"
#include "PVAFile.h"
#include "VectorOperations.h"


void GCDTester::test(std::string input_file_path) {
    PVAFile pva_file = PVAFile(input_file_path);

    uint i = 0;
    unsigned long a;
    unsigned long b;
    long long expected_gcd;
    while (!pva_file.eof()) {
        if (i % 3 == 0) {
            a = pva_file.parse_line_to_unsigned_long();
        }
        else if (i % 3 == 1) {
            b = pva_file.parse_line_to_unsigned_long();
        }
        else if (i % 3 == 2) {
            std::cout << "TEST NUMBER " << (i + 1) / 3 << ": GCD(" << a << ", " << b << ")" << std::endl;
            expected_gcd = pva_file.parse_line_to_unsigned_long();

            EuclidGCD euclid_gcd("EuclidGCD");
            long long result_gcd = euclid_gcd.get_gcd(a, b);
            if (result_gcd != expected_gcd) {
                std::cerr << euclid_gcd.uid << " failed test" << std::endl;
            }
            else {
                std::cout << euclid_gcd.uid << " passed test" << std::endl;
            }
            std::cout << std::endl;
        }
        ++i;
    }
}
