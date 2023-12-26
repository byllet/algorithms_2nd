#pragma once

#include <unordered_map>
#include <vector>

#include "abstract_function.hpp"

enum Color { white, black, gray };

class Graph {
 public:
  Graph(std::unordered_map<unsigned long long, std::vector<unsigned long long>>
            adjacency_list);

 protected:
  void DFS(unsigned long long vertex, AbstractFunction* func);
  void BFS(unsigned long long vertex, AbstractFunction* fucn);

  std::vector<Color> colors_;
  std::vector<std::vector<unsigned long long>> graph_;
};
