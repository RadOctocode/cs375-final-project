#include "utility.cpp"

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

std::vector<int> solution_brute(Graph graph_){
    // go through every permutation and select the one with the shortest distance
    std::vector<int> node_list;
    std::vector<int> ret_val;
    for(int i=0;i<graph_.size();++i){
        node_list.push_back(i);
    }
    /*do{
        for(int i =0;i<node_list.size();++i){
            printf("%d, ",node_list[i]);
        }
        printf("\n");
    }while(std::next_permutation(node_list.begin(), node_list.begin()+node_list.size()));
*/
    return ret_val;

}