#pragma once

#include <cstddef>
#include <vector>

#include "graph.hpp"

struct Vertex {
  size_t number;
  long long weight;
};

std::vector<long long> Dijkstra(Graph<Vertex>& graph, size_t start_vertex);