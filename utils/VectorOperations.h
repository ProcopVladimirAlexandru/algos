#ifndef VECTOROPERATIONS_H
#define VECTOROPERATIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>


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