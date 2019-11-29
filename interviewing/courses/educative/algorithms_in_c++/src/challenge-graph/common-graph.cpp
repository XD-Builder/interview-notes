#include <list>
#include <iostream>
using namespace std;


class Graph {
  int vertices; //number of vertices
  list <int> * adjacencyList; //store adjacency list

  public:
    Graph(int V);
    void addEdge(int v, int w);
    void breadthFirstTraversal(int source);
};

Graph::Graph(int V) { //construction
  this -> vertices = V;
  adjacencyList = new list <int> [V];
}

void Graph::addEdge(int v, int w) { // add edge to the graph
  adjacencyList[v].push_back(w);

  //adjacencyList[w].push_back(v); only for undirected graph
  //where reverse also allowed
}
