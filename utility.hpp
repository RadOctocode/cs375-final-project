#ifndef UTILITY_H
#define UTILITY_H value

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>

using Graph = std::vector<std::vector<int>>;

//represents a state in the state space tree for best first
struct state{
    std::unordered_set<int> visited;
    std::vector<int> order_visited;
    int bound, node, val = 0;
    bool done = false;

    state() = default;
    bool operator<(const state& other) const;
};

void print_edgelist(Graph graph_);
//returns an adjacency matrix read from a file
Graph make_graph(std::string file_name);

#endif 
