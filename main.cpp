#include "testers/SortingTester.h"
#include "testers/SearchTester.h"

int main() {

    SortingTester().test("./tests/sorting_tests.txt");
    SearchTester().test("./tests/search_tests.txt");

    return 0;
}