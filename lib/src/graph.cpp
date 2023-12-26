#include "graph.hpp"

Graph::Graph(
    std::unordered_map<unsigned long long, std::vector<unsigned long long>>
        adjacency_list) {
  colors_ = std::vector<Color>(adjacency_list.size());
  graph_.resize(adjacency_list.size() + 1);
  for (auto& u : adjacency_list) {
    graph_[u.first] = u.second;
  }
}

void Graph::DFS(unsigned long long vertex, AbstractFunction* func) {
  if (colors_[vertex] != white) {
    return;
  }

  colors_[vertex] = gray;
  func->OnVertexBefore(vertex);

  for (auto u : graph_[vertex]) {
    if (colors_[u] == white) {
      func->OnEdge(vertex);
      DFS(u, func);
    }
  }

  colors_[vertex] = black;
  func->OnVertexAfter(vertex);
}

void Graph::BFS(unsigned long long vertex, AbstractFunction* func) {}