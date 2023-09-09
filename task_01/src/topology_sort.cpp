#include "topology_sort.hpp"

#include <iostream>
#include <vector>

Graph::Graph(
    std::unordered_map<unsigned int, std::vector<unsigned int>> nodes) {
  nodes_.resize(nodes.size() + 1);
  for (auto i = nodes.begin(); i != nodes.end(); ++i) {
    nodes_[i->first] = i->second;
  }
}

void Graph::Dfs(unsigned int current_node, std::vector<bool>& visited,
                std::stack<unsigned int>& topology_stack) {
  if (visited[current_node]) {
    return;
  }
  visited[current_node] = true;
  for (auto child : nodes_[current_node]) {
    if (!visited[child]) {
      Dfs(child, visited, topology_stack);
    }
  }
  topology_stack.push(current_node);
}

std::vector<unsigned int> Graph::Topology_sort(unsigned int start_node) {
  std::vector<bool> visited(nodes_.size(), false);
  std::stack<unsigned int> topology_stack;
  Dfs(start_node, visited, topology_stack);
  std::vector<unsigned int> res;
  for (unsigned int i = 0; i < topology_stack.size();) {
    res.push_back(topology_stack.top());
    topology_stack.pop();
  }
  return res;
}