#pragma once

#pragma once

#include <unordered_map>
#include <vector>

#include "AbstractFunction.hpp"

enum Color { white, black, gray };

class Graph {
 public:
  Graph(std::unordered_map<size_t, std::vector<size_t>> vertexes);

 protected:
  void DFS(size_t vertex, AbstractFunction* func);

  std::vector<Color> colors_;
  std::vector<std::vector<size_t>> graph_;
};
