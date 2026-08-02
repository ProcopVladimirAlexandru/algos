#ifndef LONGESTCOMMONSUBSEQUENCE_H
#define LONGESTCOMMONSUBSEQUENCE_H
#include <string>
#include <vector>

#include "Algorithm.h"


class LongestCommonSubsequence : public Algorithm {
    public:
        LongestCommonSubsequence (const char * uid);
        LongestCommonSubsequence (std::string uid);
        std::string get_longest_common_subsequence(std::vector<std::string> words);
};
#endif
