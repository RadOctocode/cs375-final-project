#include "utility.hpp"

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

int elavtuate_path(std::vector<int> path_, Graph graph_){
    int ret_val=0;
    int next_node=path_[0];
    for(int i=1;i<path_.size();++i){
        std::vector<int> start=graph_[next_node];
        int distance=start[path_[i]];
        ret_val+=distance;
        next_node=path_[i];
    }

    return ret_val;
}

std::vector<int> solution_brute(int start,Graph graph_){
    // go through every permutation and select the one with the shortest distance
    std::vector<int> node_list;
    std::vector<int> ret_val;
    int smallest_dist;
    int num_perm=0;
    
    node_list.push_back(start);

    for(int i=0;i<graph_.size();++i){
            if(i!=start){
        node_list.push_back(i);
        }
    }
    
    node_list.push_back(start);

    ret_val=node_list;
    smallest_dist=elavtuate_path(node_list,graph_);

    do{
        /*for(auto x:node_list){
            printf("%d ",x);
        }
        printf("distance %d \n",elavtuate_path(node_list,graph_));
        */
        if(elavtuate_path(node_list,graph_)<smallest_dist){
            smallest_dist=elavtuate_path(node_list,graph_);
            ret_val=node_list;
        }
        num_perm++;
    }while(std::next_permutation(node_list.begin()+1, node_list.begin()+node_list.size()-1));

    printf("number of permutations %d distance %d\n",num_perm,smallest_dist);
    return ret_val;
}
