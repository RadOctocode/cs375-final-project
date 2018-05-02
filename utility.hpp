#include <vector>

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