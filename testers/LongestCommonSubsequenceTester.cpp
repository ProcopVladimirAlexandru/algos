#include <iostream>
#include <string>
#include <vector>

#include "LongestCommonSubsequenceTester.h"
#include "LongestCommonSubsequence.h"
#include "VectorOperations.h"


void LongestCommonSubsequenceTester::test() {

    LongestCommonSubsequence lcs("LongestCommonSubsequence");

    std::vector<std::vector<std::string>> input_word_sets{
        {"", ""},
        {"a", "a"},
        {"ab", "ab"},
        {"abc", "abc"},
        {"abc", "xyzabc"},
        {"abc", "xyz000abc"},
        {"abc", "xyaz0b00c"},
        {"da989b8c87888123", "xyaz0b00c"},
        {"a5454b45c5454dx4x55x4545y45z", "x0990x09yz9009a9bcd"}
    };
    std::vector<std::string> expected_results {
        "",
        "a",
        "ab",
        "abc",
        "abc",
        "abc",
        "abc",
        "abc",
        "xxyz"
    };

    for (unsigned long i = 0; i < input_word_sets.size(); ++i) {
        std::cout << "TEST NUMBER " << i << ": LongestCommonSubsequence(\"" << input_word_sets[i][0] << "\", \"" << input_word_sets[i][1] << "\")" << std::endl;
        std::string result_lcs = lcs.get_longest_common_subsequence(input_word_sets[i]);
        if (result_lcs != expected_results[i]) {
            std::cerr << lcs.uid << " failed test, returned \"" << result_lcs << "\"" << std::endl;
        }
        else {
            std::cout << lcs.uid << " passed test, LCS = \"" << expected_results[i] << "\"" << std::endl;
        }
        std::cout << std::endl;
    }
}
