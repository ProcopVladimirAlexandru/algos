#ifndef PARTITIONS_H
#define PARTITIONS_H

#include <vector>

#include "Algorithm.h"


class Partitions : public Algorithm {
    public:
        Partitions (const char * uid);
        Partitions (std::string uid);
        std::vector<std::vector<std::vector<unsigned long>>> get_partitions(std::vector<unsigned long> & v);
    private:
        std::vector<std::vector<unsigned long>> _get_subset_indices(
            std::vector<unsigned long> & v,
            unsigned long current_index,
            unsigned long start_index
        );
        std::pair<std::vector<unsigned long>, std::vector<unsigned long>> _partition_vector_by_indices(
            std::vector<unsigned long> & v,
            std::vector<unsigned long> & indices
        );
};
#endif
