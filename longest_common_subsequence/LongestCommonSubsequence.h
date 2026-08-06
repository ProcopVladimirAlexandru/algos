#ifndef LONGESTCOMMONSUBSEQUENCE_H
#define LONGESTCOMMONSUBSEQUENCE_H
#include <string>
#include <vector>

#include "Algorithm.h"


enum MemoCellOrigin {DEFAULT, FIRST_I, FIRST_J, LOWER_I, LOWER_J, LOWER_I_AND_J};


class LongestCommonSubsequenceMemoCell {
    public:
        unsigned long size;
        MemoCellOrigin origin;
        LongestCommonSubsequenceMemoCell (unsigned long size, MemoCellOrigin origin);
};

class LongestCommonSubsequence : public Algorithm {
    public:
        LongestCommonSubsequence (const char * uid);
        LongestCommonSubsequence (std::string uid);
        std::string get_longest_common_subsequence(std::vector<std::string> words);
};
#endif
