#include "string"

#include "BaseSort.h"


BaseSort::BaseSort(const char * uid) {
    this->uid = std::string(uid);
}
BaseSort::BaseSort(std::string uid) {
    this->uid = uid;
}
