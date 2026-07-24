#include <stdexcept>


namespace PVAMath {
    unsigned long factorial(unsigned long n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 1;
        }
        unsigned long result = 1;
        for (unsigned long i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    unsigned long binomial_coefficient(unsigned long n, unsigned long k) {
        if (k > n) {
            throw std::invalid_argument("C(n, k): n must be >= k");
        }
        if (k > n - k) {
            k = n - k;
        }
        if (k == 0){
            return 1;
        }
        if (k == 1){
            return n;
        }
        if (k == 2) {
            return ((n * (n - 1)) >> 1);
        }

        unsigned long k_fac = PVAMath::factorial(k);
        unsigned long numerator = n - k + 1;
        for (unsigned long i = numerator + 1; i <= n; i++) {
            numerator *= i;
        }
        return numerator / k_fac;
    }

    unsigned long bell_number(unsigned long n) {
        if (n < 2) {
            return 1;
        }
        unsigned long result = 0;
        for (unsigned long k = 0; k < n; k++) {
            result += PVAMath::binomial_coefficient(n - 1, k) * PVAMath::bell_number(k);
        }
        return result;
    }
}
