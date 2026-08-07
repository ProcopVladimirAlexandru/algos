#ifndef GRAPHEDGE_H
#define GRAPHEDGE_H


class GraphEdge {
    public:
        GraphEdge(unsigned long destination, long double weight);
        unsigned long destination;
        long double weight;
};

#endif
