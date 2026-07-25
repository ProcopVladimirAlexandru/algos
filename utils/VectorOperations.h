#ifndef VECTOROPERATIONS_H
#define VECTOROPERATIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>


template<class T>
bool are_vector_elements_unique(std::vector<T> & v) {
    std::unordered_set<T> us(v.begin(), v.end());
    return us.size() == v.size();
}

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
bool are_vectors_disjoint(std::vector<T> & v, std::vector<T> & u) {
    for (unsigned long i = 0; i < v.size(); i++) {
        for (unsigned long j = 0; j < u.size(); j++) {
            if (v[i] != u[j]) {
                return false;
            }
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

template<class T>
void swap_vector_elements(std::vector<T> &v, unsigned long i, unsigned long j) {
    auto aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

#endif
