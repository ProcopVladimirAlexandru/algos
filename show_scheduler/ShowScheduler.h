#ifndef SHOWSCHEDULER_H
#define SHOWSCHEDULER_H

#include <vector>

#include "Algorithm.h"

class Show {
    public:
        unsigned long start_hour;
        unsigned long start_minute;
        unsigned long end_hour;
        unsigned long end_minute;
        Show(unsigned long start_hour, unsigned long start_minute, unsigned long end_hour, unsigned long end_minute);
        bool operator <(const Show& other);
        bool intersects(const Show& other);
};


class ShowScheduler: public Algorithm {
    public:
        ShowScheduler (const char * uid);
        ShowScheduler (std::string uid);
        std::vector<unsigned long> get_schedule(std::vector<Show> & shows);
};
#endif
