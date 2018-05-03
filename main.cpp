#include "utility.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc,char **argv){   
    Graph graph = make_graph(argv[1]);

    //for(auto node_:graph){
        //printf("node_id:%d \n",node_.node_num);
        //print_edgelist(node_);
    //}    

    return 0;
}
