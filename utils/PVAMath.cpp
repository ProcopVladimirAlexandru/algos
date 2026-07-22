namespace PVAMath {
    unsigned long factorial(unsigned long n) {
        if (n == 0) {
            return 0;
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
}
