#include "graph.hpp"

Graph::Graph(std::unordered_map<size_t, std::vector<size_t>> adjacency_list) {
  colors_ = std::vector<Color>(adjacency_list.size());
  graph_.resize(adjacency_list.size() + 1);
  for (auto& u : adjacency_list) {
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

void Graph::BFS(size_t vertex, AbstractFunction* func) {}

std::vector<size_t>& Graph::operator[](const size_t i) { return graph_[i]; }

size_t Graph::Size() const { return graph_.size(); }