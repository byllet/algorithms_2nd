#include "dijkstra.hpp"

#include <limits>
#include <set>
#include <vector>

#include "weighted_graph.hpp"

std::vector<long long> Dijkstra(WeightedGraph& graph, size_t start_vertex) {
  std::vector<long long> distances(graph.Size(),
                                   std::numeric_limits<long long>::max());
  std::set<DistVertex> queue;
  distances[start_vertex] = 0;
  queue.insert({distances[start_vertex], start_vertex});

  while (!queue.empty()) {
    DistVertex v = *queue.begin();
    queue.erase(queue.begin());
    for (auto& u : graph[v]) {
      long long distance_from_v_to_u = distances[v.vertex] + u.dist;
      if (distance_from_v_to_u < distances[u.vertex]) {
        distances[u.vertex] = distance_from_v_to_u;
        queue.insert({distances[u.vertex], u.vertex});
      }
    }
  }
  return distances;
}