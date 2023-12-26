#include "dijkstra.hpp"

#include <set>
#include <vector>

std::vector<long long> Dijkstra(Graph &graph, unsigned long start_vertex) {
  long size = 10;
  std::vector<long long> dist(size);
  std::set<std::pair<long long, unsigned long>> q;
}