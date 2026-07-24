#include <iostream>
#include <vector>

#include "PVAMathTester.h"
#include "PVAMath.h"


void PVAMathTester::test() {
    bool passed = true;
    std::vector<unsigned long> ns = {0, 1, 2, 3, 4, 10};
    std::vector<unsigned long> expected_factorials = {1, 1, 2, 6, 24, 3628800};
    for (unsigned long i = 0; i < ns.size(); i++) {
        unsigned long n = ns[i];
        unsigned long expected_factorial = expected_factorials[i];
        unsigned long result_factorial = PVAMath::factorial(n);
        if (result_factorial != expected_factorial ) {
            std::cerr << "PVAMath failed test: PVAMath::factorial(" << n << ") returned " << result_factorial << std::endl;
            passed = false;
        }
    }
    if (passed) {
        std::cout << "PVAMath::factorial passed tests!" << std::endl;
    }

    passed = true;
    ns = {
        1, 1,
        2, 2, 2,
        3, 3, 3, 3,
        4, 4, 4,
        5, 5, 5,
        10, 10, 10
    };
    std::vector<unsigned long> ks = {
        0, 1,
        0, 1, 2,
        0, 1, 2, 3,
        1, 2, 3,
        0, 2, 5,
        2, 3, 6
    };
    std::vector<unsigned long> expected_binomial_coefficients = {
        1, 1,
        1, 2, 1,
        1, 3, 3, 1,
        4, 6, 4,
        1, 10, 1,
        45, 120, 210
    };
    for (unsigned long i = 0; i < ns.size(); i++) {
        unsigned long n = ns[i];
        unsigned long k = ks[i];
        unsigned long expected_bc = expected_binomial_coefficients[i];
        unsigned long result_bc = PVAMath::binomial_coefficient(n, k);
        if (result_bc != expected_bc) {
            std::cerr << "PVAMath failed test: PVAMath::binomial_coeffcient(" << n << ", " << k << ") returned " << result_bc << std::endl;
            passed = false;
        }
    }
    if (passed) {
        std::cout << "PVAMath::binomial_coeffcient passed tests!" << std::endl;
    }

    passed = true;
    ns = {0, 1, 2, 3, 4, 5, 6, 7};
    std::vector<unsigned long> expected_bells = {1, 1, 2, 5, 15, 52, 203, 877};
    for (unsigned long i = 0; i < ns.size(); i++) {
        unsigned long n = ns[i];
        unsigned long expected_bell = expected_bells[i];
        unsigned long result_bell = PVAMath::bell_number(n);
        if (result_bell != expected_bell) {
            std::cerr << "PVAMath failed test: PVAMath::bell(" << n << ") returned " << result_bell << std::endl;
            passed = false;
        }
    }
    if (passed) {
        std::cout << "PVAMath::bell_number passed tests!" << std::endl;
    }
}
