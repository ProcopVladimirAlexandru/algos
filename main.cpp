#include "testers/SortingTester.h"
#include "testers/SearchTester.h"
#include "testers/GCDTester.h"
#include "testers/PrimesLessThanNTester.h"
#include "testers/ContinuousKnapsackTester.h"
#include "testers/ShowSchedulerTester.h"


int main() {

    SortingTester().test("./tests/sorting_tests.txt");
    SearchTester().test("./tests/search_tests.txt");
    GCDTester().test("./tests/gcd_tests.txt");
    PrimesLessThanNTester().test("./tests/primes_less_than_n_tests.txt");
    ContinuousKnapsackTester().test("./tests/continuous_knapsack_tests.txt");
    ShowSchedulerTester().test("./tests/show_scheduler_tests.txt");

    return 0;
}
