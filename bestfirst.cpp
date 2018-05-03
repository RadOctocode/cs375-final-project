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

bool compare(const int& a, const int& b){
    if(a == 0) return false;
    else return a < b;
}

int calculate_val(const state& s, const Graph& g){
    int total = 0;
    for(int i = 0; i < s.order_visited.size(); i++){
        if(i == s.order_visited.size()-1)
            continue;
        total += g[s.order_visited[i]][s.order_visited[i+1]];
    }
    return total;
}

int calculate_bound(const state& s,Graph& g){
    int bound = 0;
    for (int i = 0; i < g.size(); ++i) {
        //g[i][s.node] = INT_MAX;
        if(!s.visited.count(i)){
            //for(int j = 0; j < g[0].size(); j++)
                //printf("%d ", g[i][j]);
            //printf("\n");
            //bound += *std::min_element(g[i].begin(), g[i].end(), compare);
            //printf("%d\n", *std::min_element(g[i].begin(), g[i].end(), compare));
            bound += *std::min_element(g[i].begin(), g[i].end());
        }
    }
    return bound + calculate_val(s, g);
    //return bound;
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

        if(curr.visited.size() == g.size() && !curr.done){
            curr.visited.erase(0);
            curr.done = true;
        }

        //DEBUG PRINTING
        //printf("node considered: %d\n", curr.node);
        //printf("val: %d\n", curr.val);
        //printf("bound: %d\n", curr.bound);
        //for(int i: curr.order_visited)
            //printf("%d ", i);
        //printf("\n");

        //check if current better than best
        if(curr.val < best.val && curr.visited.size() == g.size()){
            best = curr;
        }

        //check unfeasible here
        if(curr.bound > best.val || curr.visited.size() == g.size()){
            leaves++;
            continue;
        }

        for (int i = 0; i < g.size(); ++i) {
            if(curr.visited.count(i) == 0){
                //create and add child state
                state child = curr;
                child.node = i;
                child.visited.insert(i);
                child.order_visited.push_back(i);
                child.bound = calculate_bound(child, g);
                child.val = calculate_val(child, g);
                states.push(child);
            }
        }
    }
    printf("nodes: %d, leaves: %d\n", nodes, leaves);
    return best.order_visited;
}

//int main(int argc, char *argv[]){
    //if(argc != 2){
        //std::cout << "wrong usage\n";
        //return -1;
    //}
    //Graph g = make_graph(argv[1]);

    ////make 0s max ints for comparison purposes later
    //for (int i = 0; i < g.size(); ++i) {
        //for (int j = 0; j < g[0].size(); ++j) {
            //if(g[i][j] == 0)
                //g[i][j] = INT_MAX;
        //}
    //}

    //auto vertices = bestfirst(g);
    //int total = 0;
    //for(int i = 0; i < vertices.size(); i++){
        //std::cout << vertices[i] << ' ';
        //if(i == vertices.size()-1)
            //continue;
        //total += g[vertices[i]][vertices[i+1]];
    //}
    //std::cout << "\ntotal: " << total << "\n";

    //return 0;
//}
