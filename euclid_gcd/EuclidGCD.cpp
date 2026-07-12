#include "EuclidGCD.h"
#include "Algorithm.h"


EuclidGCD::EuclidGCD(const char * uid) : Algorithm(uid) {};

EuclidGCD::EuclidGCD(std::string uid) :  Algorithm(uid) {};

unsigned long EuclidGCD::get_gcd(unsigned long a, unsigned long b) {
    if (a == 0 || b == 0) {
        throw "no gcd for zero";
    }
    if (a < b) {
        unsigned long aux = a;
        a = b;
        b = aux;
    }
    while (true) {
        unsigned long remainder = a % b;
        if (remainder == 0) {
            return b;
        }
        a = b;
        b = remainder;
    }
}
