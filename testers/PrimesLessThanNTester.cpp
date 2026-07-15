#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "PrimesLessThanNTester.h"
#include "SieveOfErathosthenes.h"
#include "PVAFile.h"
#include "VectorOperations.h"


void PrimesLessThanNTester::test(std::string input_file_path) {
    PVAFile pva_file = PVAFile(input_file_path);

    uint i = 0;
    unsigned long n;
    std::vector<unsigned long> expected_primes;
    while (!pva_file.eof()) {
        if (i % 2 == 0) {
            n = pva_file.parse_line_to_unsigned_long();
        }
        else if (i % 2 == 1) {
            std::cout << "TEST NUMBER " << (i + 1) / 3 << ": Primes LTE to " << n << std::endl;
            expected_primes.clear();
            pva_file.parse_line_to_vector_unsigned_long(expected_primes, ',');
            SieveOfErathosthenes soe("SieveOfErathostenes");
            std::vector<unsigned long> result_primes = soe.get_primes_less_than_n(n);
            if (!are_vectors_equal(expected_primes, result_primes)) {
                std::cerr << soe.uid << " failed test" << std::endl;
            }
            else {
                std::cout << soe.uid << " passed test" << std::endl;
            }
            std::cout << std::endl;
        }
        ++i;
    }
}
