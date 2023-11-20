#include "topology_sort.hpp"

#include <iostream>
#include <vector>

Graph::Graph(
    std::unordered_map<unsigned int, std::vector<unsigned int>> graph) {
  graph_.resize(graph.size() + 1);
  for (auto i = graph.begin(); i != graph.end(); ++i) {
    graph_[i->first] = i->second;
  }
}

void Graph::DFS(unsigned int current_node, std::vector<bool>& visited,
                std::stack<unsigned int>& topology_stack) {
  if (visited[current_node]) {
    return;
  }
  visited[current_node] = true;
  for (auto u : graph_[current_node]) {
    if (!visited[u]) {
      DFS(u, visited, topology_stack);
    }
  }
  topology_stack.push(current_node);
}

std::vector<unsigned int> Graph::TopologySort(unsigned int start_node) {
  std::vector<bool> visited(graph_.size(), false);
  std::stack<unsigned int> topology_stack;
  DFS(start_node, visited, topology_stack);
  std::vector<unsigned int> res;
  for (unsigned int i = 0; i < topology_stack.size();) {
    res.push_back(topology_stack.top());
    topology_stack.pop();
  }
  return res;
}