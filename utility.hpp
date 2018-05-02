#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct edge{
	int weight,dest;

	edge(){

	}

	edge(int weight_,int dest_){
		weight=weight_;
		dest=dest_;
	}
	
};

struct node{
	int node_num;
	std::vector<edge> edges;

	node(){
		node_num=0;
	}

	node(int id){
		node_num=id;
	}

	node(int id, std::vector<edge> edges_){
		node_num=id;
		edges=edges_;
		
	}

};

void print_edgelist(node node_){
	for (auto x:node_.edges){
		printf("transition:%d %d \n",x.dest,x.weight);
	}

}


std::vector<node> make_graph(std::string file_name){
	//format of numbers 
	// id numb_edg edg edg edg
	std::vector<node> retval;
	std::ifstream my_file(file_name);
    std::stringstream buffer;
    int total_nodes=0;

    if (my_file.is_open()){
        buffer<<my_file.rdbuf();
        my_file.close();
    }

    buffer>>total_nodes;
    
    for (int i = 0; i < total_nodes; ++i){
 
		int node_id,numb_edg;
        buffer>>node_id;
        node current_node=node(node_id);

        for(int j=0;j<total_nodes;++j){
        	int edg,weight;
        	buffer>>edg>>weight;
        	edge current_edge=edge(weight,edg);
        	current_node.edges.push_back(current_edge);
        	//print_edgelist(current_node);
        }
    	retval.push_back(current_node);
    }

    return retval;

};

