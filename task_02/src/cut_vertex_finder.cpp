#include "cut_vertex_finder.hpp"

#include <cstddef>
#include <vector>

class FindCutVertexesFunction : public AbstractFunction {
 public:
  FindCutVertexesFunction(size_t n) : timer_{0}, tin_(n), up_(n) {}

  void OnEdgeNotVisited(size_t from, size_t to, bool is_root) override {
    up_[from] = std::min(up_[from], up_[to]);
    if (up_[to] >= tin_[from]) {
      IsCutVertex(from);
    }
  }

  void OnEdgeVisited(size_t from, size_t to, bool is_root) override {
    up_[from] = std::min(up_[from], tin_[to]);
  }

  void OnVertexBefore(size_t vertex, size_t p) override {
    tin_[vertex] = up_[vertex] = timer_++;
  }

  void OnVertexAfter(size_t vertex, size_t p) override {}

  void IsCutVertex(size_t v) { cut_vertexes_.push_back(v); }

  std::vector<size_t> GetCutVertexes() { return cut_vertexes_; }

 private:
  unsigned long long timer_;
  std::vector<unsigned long long> tin_;
  std::vector<unsigned long long> up_;
  std::vector<size_t> cut_vertexes_;
};

void InnerFindCutVertexes(Graph<size_t>& graph,
                          std::vector<size_t>& cut_vertexes) {
  FindCutVertexesFunction f(graph.Size());
  graph.DFS(0, -1, true, &f);
  cut_vertexes = f.GetCutVertexes();
}

std::vector<size_t> FindCutVertexes(Graph<size_t>& graph) {
  std::vector<size_t> cut_vertexes;
  InnerFindCutVertexes(graph, cut_vertexes);
  return cut_vertexes;
}