#include "utility.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>


std::vector<int> solution_brute(Graph graph_);

int main(int argc,char **argv){   
    Graph graph = make_graph(argv[1]);
  
    solution_brute(graph);


    return 0;
}



