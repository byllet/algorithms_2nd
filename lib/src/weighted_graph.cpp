#include "weighted_graph.hpp"

WeightedGraph::WeightedGraph(
    std::vector<std::vector<long long>> adjacency_matrix)
    : graph_{adjacency_matrix.size()} {
  for (size_t i = 0; i < adjacency_matrix.size(); ++i) {
    for (size_t j = 0; j < adjacency_matrix.size(); ++j) {
      if (adjacency_matrix[i][j] != 0) {
        graph_[i].push_back({adjacency_matrix[i][j], j});
      }
    }
  }
}

size_t WeightedGraph::Size() const { return graph_.size(); }

std::vector<DistVertex>& WeightedGraph::operator[](const DistVertex& v) {
  return graph_[v.vertex];
}

bool operator<(const DistVertex& dv1, const DistVertex& dv2) {
  return dv1.dist < dv2.dist;
}