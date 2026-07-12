#include "testers/SortingTester.h"
#include "testers/SearchTester.h"
#include "testers/GCDTester.h"

int main() {

    SortingTester().test("./tests/sorting_tests.txt");
    SearchTester().test("./tests/search_tests.txt");
    GCDTester().test("./tests/gcd_tests.txt");

    return 0;
}
