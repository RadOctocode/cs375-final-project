//#include "utility.hpp"
#include "bruteforce.cpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc,char **argv){   
    Graph graph = make_graph(argv[1]);
  
    solution_brute(graph);


    return 0;
}



