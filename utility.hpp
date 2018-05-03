#ifndef UTILITY_H
#define UTILITY_H value

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using Graph = std::vector<std::vector<int>>;


/*struct state{
    std::unordered_set<int> visited;
    int bound, node, val = 0;

    state() = default;
    bool operator<(const state& other) const{
        return bound < other.bound;
    }
};*/

void print_edgelist(Graph graph_){
    for (int i = 0; i < graph_.size(); ++i){
        std::cout<<"node "<<i<<'\n';
        
        for(int j=0;j<graph_[i].size();++j){
            std::cout<<'\t'<<"weight "<<graph_[i][j]<<" to dest "<<j<<'\n';
        }

        std::cout<<"\n";
       
    }    

}


Graph make_graph(std::string file_name){
    //adjaency matrix
    Graph retval;
    std::ifstream my_file(file_name);
    std::stringstream buffer;
    int total_nodes=0;

    if (my_file.is_open()){
        buffer<<my_file.rdbuf();
        my_file.close();
    }

    buffer>>total_nodes;
    //retval.reserve(total_nodes);
    for (int i = 0; i < total_nodes; ++i){
        std::vector<int> v;    
        retval.push_back(v); 
       
    }
    
    for (int i = 0; i < total_nodes; ++i){
 
        for(int j=0;j < total_nodes;++j){
            
            int current_weight=0;
            buffer>>current_weight;
            retval[i].push_back(current_weight);     
        }
       
    }

    return retval;

};

#endif 
