#pragma once
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Graph {
 public:
  Graph(std::unordered_map<unsigned int, std::vector<unsigned int>> nodes);
  std::vector<unsigned int> TopologySort(unsigned int start_node);

 private:
  void DFS(unsigned int current_node, std::vector<bool>& colors,
           std::stack<unsigned int>& topology_stack);
  std::vector<std::vector<unsigned int>> graph_;
};
