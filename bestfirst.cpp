#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <queue>
#include "utility.hpp"


int calculate_bound(const state& s, const Graph& g) const{
    int bound = 0;
    for (int i = 0; i < g.size(); ++i) {
        //TODO fix that min elem will always find 0
        if(!s.visited.count(i))
            bound += std::min_element(g[i]);
        else
            bound += g[s.node][i];
    }
    return bound;
}

//returns a list of nodes indicating the path
std::vector<node> bestfirst(Graph g){
    std::priority_queue states;
    state root, curr;

    root.bound = calculate_bound(root, g);
    states.push(root);
    while(!states.empty()){
        //get most promising state
        curr = states.top();
        states.pop();

        //TODO check unfeasible here


        for (int i = 0; i < g.size(); ++i) {
            if(!curr.visited.count(i)){
                //create and add child state
                state child = curr;
                child.visited.push(i);
                child.bound = calculate_bound(child, g);
                states.push(child);
            }
        }
    }
}
