#include <vector>
#include <iostream>
#include <sstream>
#include <string>


struct node{
	int node_num;
	std::vector<int> edges;

	node(){
		node_num=0;
	}

	node(int id){
		node_num=id;
	}

	node(int id, std::vector<int> edges_){
		node_num=id;
		edges=edges_;
		
	}

};

void add_edge(node node_,int edge_){
	bool added=false
	for(auto edge:node_.edges){
		if(edge==edge_){
			added=true;
		}
	}

	if(!added){
		node_.edges.push_back(edge_);
	}


}

std::vector<node> make_graph(std::string file_name){
	//format of numbers 
	// id numb_edg edg edg edg
	std::vector<node> retval;
	std::ifstream my_file(file_name);
    std::stringstream buffer;

    if (my_file.is_open()){
        buffer<<my_file.rdbuf();
        my_file.close();
    }

    while(buffer){
		int node_id,numb_edg;
        buffer>>node_id>>numb_edg;
        node current_node=node(node_id);

        for(int i=0;i<numb_edg;i++){
        	int edg;
        	buffer>>edg;
        	add_edge(current_node,edg);
        }
    	retval.push_back(current_node);
    }

    return retval;

}