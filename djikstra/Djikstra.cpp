
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>

#include "Djikstra.h"
#include "Algorithm.h"
#include "GraphEdge.h"


Djikstra::Djikstra(const char * uid) : Algorithm(uid) {};

Djikstra::Djikstra(std::string uid) :  Algorithm(uid) {};


std::vector<unsigned long> Djikstra::get_path(std::unordered_map<unsigned long, std::vector<GraphEdge>> graph, unsigned long source, unsigned long destination) {
    std::vector<unsigned long> path;
    if (graph.count(source) == 0)
        return path;
    if (graph.count(destination) == 0)
        return path;
    if (source == destination) {
        path.push_back(source);
        return path;
    }

    std::unordered_map<unsigned long, long double> distances;
    std::vector<std::pair<unsigned long, long double>> unvisited_with_distance;
    std::unordered_map<unsigned long, unsigned long> prev;

    for (auto const& [v, edges] : graph) {
        distances[v] = std::numeric_limits<long double>::infinity();
        if (v != source) {
            unvisited_with_distance.push_back(std::pair<unsigned long, long double>(v,  std::numeric_limits<long double>::infinity()));
        }
    }
    unvisited_with_distance.push_back(std::pair<unsigned long, long double>(source, 0.0));

    while (true) {
        if (unvisited_with_distance.size() == 0) {
            return path;
        }
        std::pair<unsigned long, long double> min_unvisited = unvisited_with_distance.back();
        unvisited_with_distance.pop_back();
        if (min_unvisited.second == std::numeric_limits<long double>::infinity()) {
            return path;
        }
        for (auto & edge : graph[min_unvisited.first]) {
            long double new_distance = edge.weight + distances[min_unvisited.first];
            if (new_distance < distances[edge.destination]) {
                distances[edge.destination] = new_distance;
                prev[edge.destination] = min_unvisited.first;
            }
        }
    }
    if (distances[destination] == std::numeric_limits<long double>::infinity())
        return path;

    unsigned long current_node = destination;
    while(true) {
        path.push_back(current_node);
        if (current_node == source) {
            break;
        }
        if (prev.count(current_node) == 0) {
            return std::vector<unsigned long>();
        }
        current_node = prev[current_node];
    }
    std::reverse(path.begin(), path.end());
    return path;
}
