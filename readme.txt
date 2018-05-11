# CS375 Final Assignment
# Michelle Tan and Jordan Levin

=====================================
Instructions
=====================================

1. In directory tan_levin run "make"
2. Run "./main input.txt" where input.txt
   is a valid graph file. samples can be found in files directory


=====================================
Data structures and implementation
=====================================

The graph is represented by a 2d vector (an adjacency matrix). This is the
main data structure used because both solutions rely on the graph.

The best first search also uses a priority queue. The priority queue is used
to keep the states stored so that the state with the lowest bound is used first.
This allows many of the nodes in the tree to be pruned which saves on time.

The state struct represents a state in the state space tree for the breadthfirst search.
It stores a list of nodes visited as well as the bound and current node

=====================================
Analysis of computation time
=====================================

The brute force algorithm will simply check the value of every cycle and find the lowest.
Because there are n! cycles in the graph this algorithm will take O(n!) time.

The program uses a best first search algorithm to find an 
optimal solution to the traveling salesman problem. This is achieved by exploring the
most promising node available, the node with the lowest bound. In the worst
case scenario the algorithm will fail to prune any nodes and every option will
need to be explored. This means that in the worst case the algorithm has an O((n^2)*n!)
time complexity because calculating the bound takes n^2 time and will need to be done for
every node. Despite having a worse upper bound for time complexity this algorithm outperforms
the brute force in most real world scenarios.

=====================================
Classes and interaction
=====================================

Classes used are: State. Priority_queue also but I didnt make that.

The state struct represents a state in the state space tree for the breadth first search.
It stores nodes visited, bound, and current node.

Graph is just a 2d vector because it did not need to be a class

BestFirst function takes a graph and returns a path of nodes representing the solution
to the traveling salesman problem. The calculate bound function is used along with 
min_unvisited (which finds the lowest weight in a row excluding nodes already visited)
to find the bound for a certain state.

The main function runs both functions to solve the problem, times them, and prints
the results.
