#ifndef VECTOROPERATIONS_H
#define VECTOROPERATIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>


template<class T>
bool are_vectors_equal(std::vector<T> & v, std::vector<T> & u) {
    unsigned long n = v.size();
    unsigned long m = u.size();
    if (n != m) {
        return false;
    }
    for (unsigned long i = 0; i < n; ++i) {
        if (v[i] != u[i]) {
            return false;
        }
    }
    return true;
}

template<class T>
std::string vector_to_string(std::vector<T> & v) {
    long long n = v.size();
    std::ostringstream outstream;
    outstream << "{ ";
    for (long long i = 0; i < n - 1; ++i) {
        outstream << v[i];
        outstream << ", ";
    }
    if (n) {
        outstream << v[v.size() - 1];
    }
    outstream << " }";
    return outstream.str();
}

template<class T>
void print_vector(std::vector<T> & v, bool new_line) {
    std::cout << vector_to_string<T>(v);
    if (new_line) {
        std::cout << std::endl;
    }
}

#endif
