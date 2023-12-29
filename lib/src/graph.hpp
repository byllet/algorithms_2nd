#pragma once

#include <cstddef>
#include <unordered_map>
#include <vector>

#include "abstract_function.hpp"

enum Color { white, black, gray };

class Graph {
 public:
  Graph(std::unordered_map<size_t, std::vector<size_t>> adjacency_list);
  std::vector<size_t>& operator[](const size_t i);
  size_t Size() const;

 protected:
  void DFS(size_t vertex, AbstractFunction* func);
  void BFS(size_t vertex, AbstractFunction* fucn);

  std::vector<Color> colors_;
  std::vector<std::vector<size_t>> graph_;
};
