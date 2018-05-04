#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <climits>
#include "utility.hpp"

int calculate_val(const state& s, const Graph& g){
    int total = 0;
    for(int i = 0; i < s.order_visited.size(); i++){
        if(i == s.order_visited.size()-1)
            total += g[s.order_visited[i]][s.node];
        else
            total += g[s.order_visited[i]][s.order_visited[i+1]];
    }
    return total;
}

int min_unvisited(const state& s, const Graph& g, int rownum){
    auto row = g[rownum];
    int min = INT_MAX;
    for(int i = 0; i < row.size(); i++){
        //row of node being consided
        if(rownum == s.node){
            if(s.visited.count(i) != 0 || i == 0)
                continue;
        }
        //exclude current node column and any visited column
        else if(s.visited.count(i) != 0 && i != 0 || i == s.node){
            continue;
        }
        if(row[i] < min)
            min = row[i];
    }
    return min;
}

int calculate_bound(const state& s, const Graph& g){
    int bound = 0;
    for (int i = 0; i < g.size(); ++i) {
        if(!s.visited.count(i))
            bound += min_unvisited(s, g, i);
    }
    return bound + calculate_val(s, g);
}

//returns a list of nodes indicating the path
std::vector<int> bestfirst(Graph g){
    int nodes = 0, leaves = 0;
    std::priority_queue<state> states;
    state root, curr, best;
    best.val = INT_MAX;

    root.bound = calculate_bound(root, g);
    root.node = 0;
    root.visited.insert(0);
    root.order_visited.push_back(0);
    states.push(root);
    while(!states.empty()){
        nodes++;
        //get most promising state
        curr = states.top();
        states.pop();

        if(curr.node != 0 || curr.visited.size() == g.size()){
            curr.visited.insert(curr.node);
            curr.order_visited.push_back(curr.node);
        }

        //DEBUG PRINTING
        printf("node considered: %d\n", curr.node);
        printf("val: %d\n", curr.val);
        printf("bound: %d\n", curr.bound);
        for(int i: curr.order_visited)
            printf("%d ", i);
        printf("\n");

        //check if current better than best and path is fully made
        if(curr.val < best.val && curr.visited.size() == g.size()){
            curr.order_visited.push_back(0);
            best = curr;
            continue;
        }
        //check unfeasible here
        if(curr.bound >= best.val || curr.visited.size() == g.size()){
            leaves++;
            continue;
        }

        for (int i = 0; i < g.size(); ++i) {
            if(i == 0 && curr.visited.size() != g.size())
                continue;
            if(curr.visited.count(i) == 0){
                //create and add child state
                state child = curr;
                child.node = i;
                child.bound = calculate_bound(child, g);
                child.val = calculate_val(child, g);
                states.push(child);
            }
        }
    }
    printf("nodes: %d, leaves: %d\n", nodes, leaves);
    return best.order_visited;
}
