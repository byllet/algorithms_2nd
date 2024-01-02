#pragma once

#include <cstddef>
#include <graph.hpp>
#include <vector>

class LCA {
 public:
  LCA(Graph& graph, size_t root);
  size_t GetLCA(size_t a, size_t b);

 private:
  std::vector<long long> heigths_;
  std::vector<size_t> dfs_list_;
  std::vector<size_t> segments_tree_;
  std::vector<size_t> first_;

  void BuildTree(size_t i, size_t left, size_t right);
  size_t MinFromTree(size_t i, size_t sl, size_t sr, size_t l, size_t r);
};