#ifndef ARRANGEMENTS_H
#define ARRANGEMENTS_H

#include <vector>

#include "Algorithm.h"


class Arrangements : public Algorithm {
    public:
        Arrangements (const char * uid);
        Arrangements (std::string uid);
        std::vector<std::vector<unsigned long>> get_arrangements(std::vector<unsigned long> & v, unsigned long k);
};
#endif
