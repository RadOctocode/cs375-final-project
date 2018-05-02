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
		
	}

}