#ifndef LISN2_H
#define LISN2_H
#include <string>

#include "Algorithm.h"


class LISN2 : public Algorithm {
    public:
        LISN2 (const char * uid);
        LISN2 (std::string uid);
        std::string get_lis(std::string s);
};
#endif
