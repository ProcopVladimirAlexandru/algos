#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "ShowSchedulerTester.h"
#include "ShowScheduler.h"
#include "PVAFile.h"
#include "VectorOperations.h"


void ShowSchedulerTester::test(std::string input_file_path) {
    PVAFile pva_file = PVAFile(input_file_path);

    uint i = 0;
    unsigned long per_test_lines = 2;
    std::vector<Show> shows;
    std::vector<unsigned long> expected_schedule;
    std::vector<unsigned long> raw_times;
    while (!pva_file.eof()) {
        if (i % per_test_lines  == 0) {
            shows.clear();
            raw_times.clear();
            pva_file.parse_line_to_vector_unsigned_long(raw_times, ',');
            if (raw_times.size() == 0) {
                return;
            }
            if (raw_times.size() == 0 || raw_times.size() % 4 != 0) {
                throw "show raw times should be a positive multiple of four";
            }
            for (unsigned long j = 3; j < raw_times.size(); j+=4) {
                Show s(raw_times[j - 3], raw_times[j - 2], raw_times[j - 1], raw_times[j]);
                shows.push_back(s);
            }
        }
        else if (i % per_test_lines  == 1) {
            std::cout << "TEST NUMBER " << (i + 1) / per_test_lines  << ": Scheduling " << shows.size() << " Shows!" << std::endl;
            expected_schedule.clear();
            pva_file.parse_line_to_vector_unsigned_long(expected_schedule, ',');
            ShowScheduler ss("GreedyShowScheduler");
            std::vector<unsigned long> result_schedule = ss.get_schedule(shows);
            if (!are_vectors_equal(expected_schedule, result_schedule)) {
                std::cerr << ss.uid << " failed test" << std::endl;
            }
            else {
                std::cout << ss.uid << " passed test" << std::endl;
            }
            std::cout << std::endl;
        }
        ++i;
    }
}
