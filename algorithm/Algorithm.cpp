#include "string"

#include "Algorithm.h"


Algorithm::Algorithm(const char * uid) {
    this->uid = std::string(uid);
}
Algorithm::Algorithm(std::string uid) {
    this->uid = uid;
}
