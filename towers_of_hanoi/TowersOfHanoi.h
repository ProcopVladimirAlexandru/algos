#ifndef TOWERSOFHANOI_H
#define TOWERSOFHANOI_H

#include <vector>
#include <string>

#include "Algorithm.h"


class TowersOfHanoi : public Algorithm {
    public:
        TowersOfHanoi (const char * uid, unsigned long tower_count, unsigned long ring_count);
        TowersOfHanoi (std::string uid, unsigned long tower_count, unsigned long ring_count);
        std::vector<std::vector<unsigned long>> solve();
    private:
        unsigned long tower_count;
        unsigned long ring_count;
        std::vector<std::vector<unsigned long>> state;
        void initialize_state();
        void print_state(std::string indent);
        void _solve(
            unsigned long level,
            unsigned long main_tower_index,
            unsigned long target_tower_index,
            unsigned long empty_tower_index
        );
        void move_ring(unsigned long source_tower_index, unsigned long target_tower_index);
};
#endif
