#ifndef GRAPH_EDGES_LIST_H_
#define GRAPH_EDGES_LIST_H_

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

class Graph {
 public:
  Graph(int V);
  Graph(std::ifstream &ifs);
  void AddEdge(int v, int w);
  std::vector<int> Adj(int v);
  int V();
  int E();

 private:
  std::vector<std::pair<int, int>> edges;
  int nv;
};

Graph::Graph(int V) : nv(V) {}

Graph::Graph(std::ifstream &ifs) {
  // Get number of vertices
  ifs >> nv;

  // Go through all the edges and add them
  int v, w;
  while (ifs >> v >> w)
    AddEdge(v, w);
}

void Graph::AddEdge(int v, int w) {
  edges.emplace_back(v, w);
}

std::vector<int> Graph::Adj(int v) {
  std::vector<int> v_edges;

  for (auto &e : edges) {
    if (e.first == v)
      v_edges.push_back(e.second);
  }

  return v_edges;
}

int Graph::V() { return nv; }
int Graph::E() { return edges.size(); }


#endif