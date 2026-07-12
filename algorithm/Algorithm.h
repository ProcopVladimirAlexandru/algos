#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>


class Algorithm {
    public:
        std::string uid;
        Algorithm (const char * uid);
        Algorithm (std::string uid);
};

#endif
