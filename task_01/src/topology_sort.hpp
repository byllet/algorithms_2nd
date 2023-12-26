#pragma once

#include <graph.hpp>
#include <stack>
#include <vector>

class GraphWithTopologySort : public Graph {
 public:
  GraphWithTopologySort(
      std::unordered_map<unsigned long long, std::vector<unsigned long long>>&
          adjacency_list);
  GraphWithTopologySort(
      std::unordered_map<unsigned long long, std::vector<unsigned long long>>
          adjacency_list);
  std::vector<unsigned int> TopologySort(size_t start_node);
};

class StackFunction : public AbstractFunction {
 public:
  StackFunction();
  void OnEdge(unsigned long long vertex) override;
  void OnVertexBefore(unsigned long long vertex) override;
  void OnVertexAfter(unsigned long long vertex) override;
  std::stack<size_t> topology_stack;
};
