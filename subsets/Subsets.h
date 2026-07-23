#ifndef SUBSETS_H
#define SUBSETS_H

#include <vector>

#include "Algorithm.h"


class Subsets : public Algorithm {
    public:
        Subsets (const char * uid);
        Subsets (std::string uid);
        std::vector<std::vector<unsigned long>> get_subsets(std::vector<unsigned long> & v);
    private:
        void _collect_subsets(
            std::vector<std::vector<unsigned long>> & all_subsets,
            std::vector<unsigned long> & v,
            unsigned long current_index,
            std::vector<unsigned long> current_subset
        );
};
#endif
