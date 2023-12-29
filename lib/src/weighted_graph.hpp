#pragma once

#include <cstddef>
#include <vector>

struct DistVertex {
  long long dist;
  size_t vertex;
};

class WeightedGraph {
 public:
  WeightedGraph(std::vector<std::vector<long long>> adjacency_matrix);
  std::vector<DistVertex>& operator[](const DistVertex& v);
  size_t Size() const;

 private:
  std::vector<std::vector<DistVertex>> graph_;
};

bool operator<(const DistVertex& dv1, const DistVertex& dv2);