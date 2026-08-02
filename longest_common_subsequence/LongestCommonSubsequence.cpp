#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "LongestCommonSubsequence.h"
#include "Algorithm.h"



LongestCommonSubsequence::LongestCommonSubsequence(const char * uid) : Algorithm(uid) {};

LongestCommonSubsequence::LongestCommonSubsequence(std::string uid) :  Algorithm(uid) {};


std::string LongestCommonSubsequence::get_longest_common_subsequence(std::vector<std::string> words) {
    unsigned long n = words.size();
    std::string result;

    if (words.size() != 2) {
        throw std::invalid_argument("longest common subsequence only available for 2 words");
    }
    std::string w1 = words[0];
    std::string w2 = words[1];
    if (w1.size() == 0) {
        return result;
    }
    if (w2.size() == 0) {
        return result;
    }

    std::vector<std::vector<unsigned long>> memo;
    for (unsigned long i = 0; i < w1.size(); i++) {
        std::vector line;
        for (unsigned long j = 0; j < w2.size(); j++) {
            line.push_back(0);
        }
        memo.push_back(line);
    }

    if (w1[0] == w2[0]) {
        memo[0][0] = 0;
        result.push_back(w1[0]);
    }
g
    for (unsigned i = 0; i < memo.size(); i++) {
        for (unsigned long j = 0; j < memo[i].size(); j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (w1[i] == w2[j]) {

            }
        }
    }

    return result;
}
