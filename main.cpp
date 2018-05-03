#include "utility.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <climits>


std::vector<int> solution_brute(int start,Graph graph_);
std::vector<int> bestfirst(Graph g);

int main(int argc,char **argv){   
    if(argc != 2){
        std::cout << "wrong usage\n";
        return -1;
    }

    int total = 0;
    Graph graph = make_graph(argv[1]);
  
    //BRUTE FORCE
    clock_t begin = clock();

    auto bruteforcepath = solution_brute(0, graph);

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    //print results
    for(int i = 0; i < bruteforcepath.size(); i++){
        std::cout << bruteforcepath[i] << ' ';
        if(i == bruteforcepath.size()-1)
            continue;
        total += graph[bruteforcepath[i]][bruteforcepath[i+1]];
    }
    std::cout << "\ntotal: " << total << "\n";
    std::cout << "time: " << elapsed_secs << "\n";


    //BEST FIRST
    //make 0s max ints for comparison purposes later
    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph[0].size(); ++j) {
            if(graph[i][j] == 0)
                graph[i][j] = INT_MAX;
        }
    }

    begin = clock();
    auto bestfirstpath = bestfirst(graph);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    //print results
    total = 0;
    for(int i = 0; i < bestfirstpath.size(); i++){
        std::cout << bestfirstpath[i] << ' ';
        if(i == bestfirstpath.size()-1)
            continue;
        total += graph[bestfirstpath[i]][bestfirstpath[i+1]];
    }
    std::cout << "\ntotal: " << total << "\n";
    std::cout << "time: " << elapsed_secs << "\n";

    return 0;
}



