#include <utility>
#include <stdexcept>
#include <algorithm>

#include "ShowScheduler.h"
#include "Algorithm.h"


Show::Show(unsigned long start_hour, unsigned long start_minute, unsigned long end_hour, unsigned long end_minute) {
    this->start_hour = start_hour;
    this->start_minute = start_minute;
    this->end_hour = end_hour;
    this->end_minute = end_minute;
}

bool Show::operator <(const Show& other) {
    if (this->end_hour < other.end_hour) {
        return true;
    }
    else if (this->end_hour == other.end_hour) {
        return this->end_minute < other.end_minute;
    }
    else {
        return false;
    }
}

bool Show::intersects(const Show& other) {
    if (this->end_hour < other.start_hour) {
        return false;
    }
    else if (this->end_hour == other.start_hour) {
        if (this->end_minute < other.start_minute) {
            return false;
        }
        return true;
    }
    else {
        if (this->start_hour > other.end_hour) {
            return false;
        }
        else if (this->start_hour == other.end_hour) {
            if (this->start_minute <= other.end_minute) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
}

ShowScheduler::ShowScheduler(const char * uid) : Algorithm(uid) {};

ShowScheduler::ShowScheduler(std::string uid) :  Algorithm(uid) {};

std::vector<unsigned long> ShowScheduler::get_schedule(std::vector<Show> & shows) {
    unsigned long n = shows.size();
    std::vector<unsigned long> results;
    if (n == 0) {
        return results;
    }
    std::vector<unsigned long> position_map;
    for (unsigned long i = 0; i < n; i++) {
        position_map.push_back(i);
    }
    for (unsigned long i = 0; i < n - 1; i++) {
        for (unsigned long j = 0; j < n - i - 1; j++) {
            if (shows[position_map[j + 1]] < shows[position_map[j]]) {
                unsigned long aux = position_map[j];
                position_map[j] = position_map[j + 1];
                position_map[j + 1] = aux;
            }
        }
    }

    results.push_back(position_map[0]);
    unsigned long previous_show_index = position_map[0];
    for (unsigned long i = 1; i < n; i++) {
        if (!shows[previous_show_index].intersects(shows[position_map[i]])) {
            previous_show_index = position_map[i];
            results.push_back(previous_show_index);
        }
    }
    return results;
}
