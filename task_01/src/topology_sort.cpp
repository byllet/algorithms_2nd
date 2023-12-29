#include "topology_sort.hpp"

#include <cstddef>
#include <stack>

GraphWithTopologySort::GraphWithTopologySort(
    std::unordered_map<size_t, std::vector<size_t>>& adjacency_list)
    : Graph(adjacency_list) {}

GraphWithTopologySort::GraphWithTopologySort(
    std::unordered_map<size_t, std::vector<size_t>> adjacency_list)
    : Graph(adjacency_list) {}

StackFunction::StackFunction() : topology_stack{std::stack<size_t>()} {}

void StackFunction::OnEdge(unsigned long long vertex) {}

void StackFunction::OnVertexBefore(unsigned long long vertex) {}

void StackFunction::OnVertexAfter(unsigned long long vertex) {
  topology_stack.push(vertex);
}

std::vector<size_t> GraphWithTopologySort::TopologySort(size_t vertex) {
  colors_.assign(graph_.size(), white);
  StackFunction stack_function;
  DFS(vertex, &stack_function);
  std::vector<size_t> result;
  for (unsigned int i = 0; i < stack_function.topology_stack.size();) {
    result.push_back(stack_function.topology_stack.top());
    stack_function.topology_stack.pop();
  }
  return result;
}