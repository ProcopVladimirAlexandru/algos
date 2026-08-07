#ifndef DJIKSTRA_H
#define DJIKSTRA_H

#include <vector>

#include "Algorithm.h"
#include "GraphEdge.h"


class Djikstra : public Algorithm {
    public:
        Djikstra (const char * uid);
        Djikstra (std::string uid);
        std::vector<unsigned long> get_path(std::unordered_set<unsigned long, std::vector<GraphEdge>> graph, unsigned long source, unsigned long destination);
};
#endif
