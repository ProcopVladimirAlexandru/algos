#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "LongestCommonSubsequence.h"
#include "Algorithm.h"


LongestCommonSubsequenceMemoCell::LongestCommonSubsequenceMemoCell(unsigned long size, MemoCellOrigin origin) {
    this->size = size;
    this->origin= origin;
};


LongestCommonSubsequence::LongestCommonSubsequence(const char * uid) : Algorithm(uid) {};

LongestCommonSubsequence::LongestCommonSubsequence(std::string uid) :  Algorithm(uid) {};


std::string LongestCommonSubsequence::get_longest_common_subsequence(std::vector<std::string> words) {
    unsigned long n = words.size();
    std::string result;

    if (n != 2) {
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

    std::vector<std::vector<LongestCommonSubsequenceMemoCell>> memo;
    for (unsigned long i = 0; i < w1.size(); i++) {
        std::vector<LongestCommonSubsequenceMemoCell> line;
        for (unsigned long j = 0; j < w2.size(); j++) {
            LongestCommonSubsequenceMemoCell new_cell(0, MemoCellOrigin::DEFAULT);
            line.push_back(new_cell);
        }
        memo.push_back(line);
    }

    for (unsigned i = 0; i < memo.size(); i++) {
        for (unsigned long j = 0; j < memo[i].size(); j++) {
            if (j == 0) {
                if (w1[i] == w2[j]) {
                    memo[i][j].size = 1;
                    memo[i][j].origin = MemoCellOrigin::FIRST_J;
                }
                continue;
            }
            if (w1[i] == w2[j]) {
                if (i == 0) {
                    memo[i][j].size = 1;
                    memo[i][j].origin = MemoCellOrigin::FIRST_I;
                    continue;
                }
                memo[i][j].size = memo[i - 1][j - 1].size + 1;
                memo[i][j].origin = MemoCellOrigin::LOWER_I_AND_J;
            }
            else {
                if (i == 0) {
                    memo[i][j].size = memo[i][j - 1].size;
                    memo[i][j].origin = MemoCellOrigin::LOWER_J;
                    continue;
                }
                if (memo[i - 1][j].size > memo[i][j - 1].size) {
                    memo[i][j].size = memo[i - 1][j].size;
                    memo[i][j].origin = MemoCellOrigin::LOWER_I;
                }
                else {
                    memo[i][j].size = memo[i][j - 1].size;
                    memo[i][j].origin = MemoCellOrigin::LOWER_J;
                }
            }
        }
    }

    unsigned long i = w1.size() - 1;
    unsigned long j = w2.size() - 1;
    while (true) {
        LongestCommonSubsequenceMemoCell current_cell = memo[i][j];
        if (current_cell.size == 0) {
            break;
        }
        else if (current_cell.origin == MemoCellOrigin::DEFAULT) {
            break;
        }
        else if (current_cell.origin == MemoCellOrigin::FIRST_I) {
            if (current_cell.size == 1) {
                result.push_back(w1[0]);
            }
            break;
        }
        else if (current_cell.origin == MemoCellOrigin::FIRST_J) {
            if (current_cell.size == 1) {
                result.push_back(w2[0]);
            }
            break;
        }
        else if (current_cell.origin == MemoCellOrigin::LOWER_I_AND_J) {
            result.push_back(w1[i]);
            --i;
            --j;
        }
        else if (current_cell.origin == MemoCellOrigin::LOWER_I) {
            --i;
        }
        else if (current_cell.origin == MemoCellOrigin::LOWER_J) {
            --j;
        }
        else {
            break;
        }
    }

    std::reverse(result.begin(), result.end());
    return result;
}
