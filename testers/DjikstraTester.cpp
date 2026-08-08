#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "DjikstraTester.h"
#include "Djikstra.h"
#include "VectorOperations.h"
#include "GraphEdge.h"


void DjikstraTester::test() {
    Djikstra djikstra("Djikstra");
    std::vector<std::unordered_map<unsigned long, std::vector<GraphEdge>>> input_graphs = {
        {
            { 0, { GraphEdge(1, 1) } }, { 1, {} }
        }
    };
    std::vector<unsigned long> input_sources = { 0 };
    std::vector<unsigned long> input_destinations = { 1 };
    std::vector<std::vector<unsigned long>> expected_outputs = {
        { 0, 1 }
    };

    for (unsigned long i = 0; i < input_graphs.size(); ++i) {
        auto & input_graph = input_graphs[i];
        auto & expected_path = expected_outputs[i];
        unsigned long input_source = input_sources[i];
        unsigned long input_destination = input_destinations[i];
        std::cout << "TEST NUMBER " << i << ": Djikstra(" << input_source << ", " << input_destination << ")" << std::endl;
        std::vector<unsigned long> result_path = djikstra.get_path(input_graph, input_source, input_destination);
        if (!are_vectors_equal(result_path, expected_path)) {
            std::cerr << djikstra.uid << " failed test" << std::endl;
            print_vector(result_path, true);
        }
        else {
            std::cout << djikstra.uid << " passed test" << std::endl;
        }
        std::cout << std::endl;
    }
}
