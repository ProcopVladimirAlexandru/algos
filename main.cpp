#include "testers/SortingTester.h"
#include "testers/SearchTester.h"
#include "testers/GCDTester.h"
#include "testers/PrimesLessThanNTester.h"
#include "testers/ContinuousKnapsackTester.h"
#include "testers/ShowSchedulerTester.h"
#include "testers/LISTester.h"
#include "testers/Knapsack01Tester.h"
#include "testers/PermutationsTester.h"
#include "testers/CombinationsTester.h"
#include "testers/ArrangementsTester.h"
#include "testers/SubsetsTester.h"
#include "testers/PVAMathTester.h"
#include "testers/PartitionsTester.h"
#include "testers/TowersOfHanoiTester.h"
#include "testers/LongestCommonSubsequenceTester.h"
#include "testers/DjikstraTester.h"


int main() {
    PVAMathTester().test();
    SortingTester().test("./tests/sorting_tests.txt");
    SearchTester().test("./tests/search_tests.txt");
    GCDTester().test("./tests/gcd_tests.txt");
    PrimesLessThanNTester().test("./tests/primes_less_than_n_tests.txt");
    ContinuousKnapsackTester().test("./tests/continuous_knapsack_tests.txt");
    ShowSchedulerTester().test("./tests/show_scheduler_tests.txt");
    LISTester().test();
    Knapsack01Tester().test("./tests/knapsack_01_tests.txt");
    PermutationsTester().test();
    CombinationsTester().test();
    ArrangementsTester().test();
    SubsetsTester().test();
    PartitionsTester().test();
    TowersOfHanoiTester().test();
    LongestCommonSubsequenceTester().test();
    DjikstraTester().test();

    return 0;
}
