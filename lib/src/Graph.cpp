#include "Graph.hpp"

Graph::Graph(std::unordered_map<size_t, std::vector<size_t>> vertexes) {
  colors_ = std::vector<Color>(vertexes.size());
  graph_.resize(vertexes.size() + 1);
  for (auto& u : vertexes) {
    graph_[u.first] = u.second;
  }
}

void Graph::DFS(size_t vertex, AbstractFunction* func) {
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
