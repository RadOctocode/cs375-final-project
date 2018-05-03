#ifndef UTILITY_H
#define UTILITY_H value

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>

using Graph = std::vector<std::vector<int>>;

struct state{
    std::unordered_set<int> visited;
    std::vector<int> order_visited;
    int bound, node, val = 0;

    state() = default;
    bool operator<(const state& other) const;
};

void print_edgelist(Graph graph_);
Graph make_graph(std::string file_name);

#endif 
