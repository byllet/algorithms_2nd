#pragma once

#include <dijkstra.hpp>
#include <graph.hpp>
#include <vector>

bool FordBellman(Graph<Vertex>& graph, size_t s,
                 std::vector<long long>& distances);

std::vector<std::vector<long long>> Johnson(Graph<Vertex>& graph);