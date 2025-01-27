
#include <gtest/gtest.h>

#include <dijkstra.hpp>
#include <limits>
#include <vector>

TEST(Dijkstra, Simple) {
  Graph<VertexWeighted> weighted_graph;
  weighted_graph.SetAdjacencyMatrix({{0, 2, 100}, {2, 0, 1}, {100, 1, 0}});
  ASSERT_EQ(Dijkstra(weighted_graph, 0), (std::vector<long long>{0, 2, 3}));
  ASSERT_EQ(Dijkstra(weighted_graph, 1), (std::vector<long long>{2, 0, 1}));
  ASSERT_EQ(Dijkstra(weighted_graph, 2), (std::vector<long long>{3, 1, 0}));
}

TEST(Dijkstra, Simple1) {
  Graph<VertexWeighted> weighted_graph;
  weighted_graph.SetAdjacencyMatrix({{0, 2, 0}, {7, 0, 3}, {1, 5, 0}});
  ASSERT_EQ(Dijkstra(weighted_graph, 2), (std::vector<long long>{1, 3, 0}));
  ASSERT_EQ(Dijkstra(weighted_graph, 1), (std::vector<long long>{4, 0, 3}));
  ASSERT_EQ(Dijkstra(weighted_graph, 0), (std::vector<long long>{0, 2, 5}));
}
TEST(Dijkstra, Simple3) {
  Graph<VertexWeighted> weighted_graph;
  weighted_graph.SetAdjacencyMatrix(
      {{0, 6, 14, 11}, {7, 0, 9, 8}, {7, 0, 0, 10}, {15, 8, 7, 0}});
  ASSERT_EQ(Dijkstra(weighted_graph, 0),
            (std::vector<long long>({0, 6, 14, 11})));
}

TEST(Dijkstra, WithNoWays) {
  long long INF = std::numeric_limits<long long>::max();
  Graph<VertexWeighted> weighted_graph;
  weighted_graph.SetAdjacencyMatrix({{0, 0, 0}, {1, 0, 1}, {1, 1, 0}});
  ASSERT_EQ(Dijkstra(weighted_graph, 0),
            (std::vector<long long>({0, INF, INF})));
}

TEST(Dijkstra, OneVertex) {
  Graph<VertexWeighted> weighted_graph;
  weighted_graph.SetAdjacencyMatrix({{0}});
  ASSERT_EQ(Dijkstra(weighted_graph, 0), (std::vector<long long>({0})));
}

TEST(Dijkstra, Medium) {
  Graph<VertexWeighted> weighted_graph;
  weighted_graph.SetAdjacencyMatrix({{0, 8, 14, 6, 5, 0},
                                     {5, 0, 13, 9, 11, 18},
                                     {15, 1, 0, 5, 13, 18},
                                     {7, 12, 1, 0, 4, 6},
                                     {6, 1, 19, 14, 0, 10},
                                     {17, 3, 16, 8, 6, 0}});
  ASSERT_EQ(Dijkstra(weighted_graph, 0),
            (std::vector<long long>{0, 6, 7, 6, 5, 12}));
  ASSERT_EQ(Dijkstra(weighted_graph, 1),
            (std::vector<long long>{5, 0, 10, 9, 10, 15}));
  ASSERT_EQ(Dijkstra(weighted_graph, 2),
            (std::vector<long long>{6, 1, 0, 5, 9, 11}));
  ASSERT_EQ(Dijkstra(weighted_graph, 3),
            (std::vector<long long>{7, 2, 1, 0, 4, 6}));
  ASSERT_EQ(Dijkstra(weighted_graph, 4),
            (std::vector<long long>{6, 1, 11, 10, 0, 10}));
  ASSERT_EQ(Dijkstra(weighted_graph, 5),
            (std::vector<long long>{8, 3, 9, 8, 6, 0}));
}

TEST(Dijkstra, Hard) {
  Graph<VertexWeighted> weighted_graph;
  weighted_graph.SetAdjacencyMatrix({{0, 11, 7, 12, 13, 5, 19, 3, 16},
                                     {20, 0, 18, 15, 16, 19, 20, 17, 18},
                                     {14, 17, 0, 2, 7, 19, 6, 9, 11},
                                     {8, 4, 15, 0, 9, 15, 18, 3, 0},
                                     {5, 14, 15, 2, 0, 19, 13, 15, 4},
                                     {1, 8, 18, 12, 5, 0, 3, 8, 4},
                                     {4, 9, 13, 5, 15, 2, 0, 1, 9},
                                     {7, 6, 17, 17, 17, 10, 20, 0, 7},
                                     {6, 12, 12, 3, 12, 7, 2, 17, 0}});
  ASSERT_EQ(Dijkstra(weighted_graph, 0),
            (std::vector<long long>{0, 9, 7, 9, 10, 5, 8, 3, 9}));
  ASSERT_EQ(Dijkstra(weighted_graph, 6),
            (std::vector<long long>{3, 7, 10, 5, 7, 2, 0, 1, 6}));
  ASSERT_EQ(Dijkstra(weighted_graph, 8),
            (std::vector<long long>{5, 7, 12, 3, 9, 4, 2, 3, 0}));
}

TEST(Dijkstra, Hard2) {
  Graph<VertexWeighted> weighted_graph;
  weighted_graph.SetAdjacencyMatrix(
      {{0, 16, 9, 16, 10, 13, 9, 19, 13, 18, 11, 14, 5, 17, 8},
       {12, 0, 0, 15, 16, 13, 7, 9, 19, 12, 7, 5, 2, 2, 18},
       {16, 4, 0, 2, 8, 6, 20, 19, 7, 10, 0, 16, 15, 6, 10},
       {3, 16, 0, 0, 4, 15, 12, 16, 4, 1, 7, 20, 0, 6, 18},
       {16, 7, 5, 4, 0, 13, 1, 0, 1, 1, 0, 3, 8, 18, 16},
       {14, 4, 13, 14, 4, 0, 20, 6, 5, 17, 0, 7, 15, 11, 7},
       {15, 10, 3, 3, 5, 10, 0, 16, 11, 17, 11, 18, 10, 3, 11},
       {1, 11, 9, 1, 10, 16, 16, 0, 4, 13, 8, 5, 15, 4, 1},
       {1, 2, 17, 12, 18, 1, 17, 17, 0, 14, 12, 4, 4, 18, 17},
       {15, 17, 8, 9, 6, 2, 18, 4, 8, 0, 17, 17, 19, 9, 8},
       {7, 13, 8, 11, 3, 5, 17, 7, 10, 1, 0, 16, 12, 7, 18},
       {12, 9, 18, 4, 17, 8, 5, 9, 7, 5, 8, 0, 20, 10, 12},
       {19, 8, 4, 10, 14, 1, 13, 11, 15, 6, 16, 10, 0, 4, 0},
       {14, 16, 11, 8, 9, 0, 12, 12, 15, 10, 16, 6, 10, 0, 3},
       {1, 9, 17, 13, 3, 10, 17, 17, 20, 11, 10, 12, 2, 8, 0}});
  ASSERT_EQ(Dijkstra(weighted_graph, 0),
            (std::vector<long long>{0, 10, 9, 11, 10, 6, 9, 12, 11, 11, 11, 13,
                                    5, 9, 8}));
  ASSERT_EQ(
      Dijkstra(weighted_graph, 13),
      (std::vector<long long>{4, 9, 9, 8, 6, 6, 7, 11, 7, 7, 13, 6, 5, 0, 3}));
  ASSERT_EQ(
      Dijkstra(weighted_graph, 8),
      (std::vector<long long>{1, 2, 10, 8, 11, 1, 9, 11, 0, 9, 9, 4, 4, 4, 9}));
}

TEST(Dijkstra, Hard3) {
  Graph<VertexWeighted> weighted_graph;
  weighted_graph.SetAdjacencyMatrix(
      {{0, 30, 11, 3, 3, 22, 21, 10, 18, 25, 18, 7, 7},
       {5, 0, 1, 28, 16, 0, 14, 1, 24, 14, 4, 29, 22},
       {11, 22, 0, 12, 4, 4, 27, 0, 17, 8, 27, 23, 29},
       {9, 26, 6, 0, 0, 2, 15, 9, 3, 15, 28, 28, 24},
       {1, 24, 4, 8, 0, 23, 19, 29, 22, 7, 3, 9, 10},
       {26, 9, 16, 3, 10, 0, 21, 10, 26, 12, 23, 16, 21},
       {5, 20, 28, 15, 2, 21, 0, 12, 0, 17, 20, 2, 18},
       {6, 28, 30, 21, 25, 17, 24, 0, 3, 21, 24, 28, 7},
       {1, 30, 23, 0, 17, 23, 13, 6, 0, 13, 11, 26, 9},
       {17, 11, 25, 4, 1, 7, 22, 21, 0, 0, 13, 2, 26},
       {1, 3, 11, 12, 24, 10, 1, 4, 25, 30, 0, 25, 23},
       {19, 17, 21, 14, 23, 16, 12, 6, 5, 23, 0, 0, 15},
       {3, 8, 27, 22, 7, 19, 16, 24, 15, 16, 8, 26, 0}});
  ASSERT_EQ(
      Dijkstra(weighted_graph, 2),
      (std::vector<long long>{5, 10, 0, 8, 4, 4, 8, 11, 11, 8, 7, 10, 12}));
  ASSERT_EQ(Dijkstra(weighted_graph, 1),
            (std::vector<long long>{5, 0, 1, 8, 5, 5, 5, 1, 11, 9, 4, 7, 12}));
  ASSERT_EQ(
      Dijkstra(weighted_graph, 0),
      (std::vector<long long>{0, 14, 9, 3, 3, 5, 18, 10, 6, 17, 17, 7, 7}));
}

TEST(Dijkstra, Unbelievable) {
  Graph<VertexWeighted> weighted_graph;
  weighted_graph.SetAdjacencyMatrix(
      {{0, 25, 21, 16, 21, 14, 26, 18, 25, 24,
        9, 15, 4,  19, 9,  22, 5,  22, 27, 23},
       {20, 0, 28, 23, 14, 9,  30, 20, 13, 14,
        22, 1, 4,  20, 7,  23, 19, 25, 29, 19},
       {30, 19, 0,  6,  18, 28, 18, 28, 6,  15,
        11, 6,  18, 14, 11, 13, 23, 21, 23, 29},
       {8,  1,  11, 0, 13, 0,  29, 28, 12, 30,
        25, 24, 23, 2, 29, 25, 12, 27, 0,  24},
       {18, 22, 27, 4, 0, 30, 9, 18, 26, 5, 30, 21, 4, 2, 15, 5, 1, 23, 1, 8},
       {29, 22, 24, 9,  11, 0,  23, 25, 8,  7,
        12, 7,  27, 19, 16, 17, 25, 27, 15, 11},
       {0,  23, 17, 20, 14, 22, 0,  17, 0,  11,
        15, 14, 21, 26, 30, 2,  10, 10, 11, 19},
       {29, 29, 10, 27, 7,  29, 8,  0,  23, 7,
        9,  24, 23, 24, 29, 14, 10, 10, 24, 21},
       {18, 4, 15, 22, 20, 15, 22, 2,  0,  11,
        9,  3, 10, 22, 14, 22, 15, 12, 19, 1},
       {29, 28, 10, 24, 13, 5, 3, 15, 23, 0, 18, 8, 6, 21, 20, 13, 0, 3, 6, 25},
       {16, 21, 13, 12, 3,  10, 1,  9,  23, 26,
        0,  5,  29, 7,  10, 16, 16, 19, 22, 21},
       {4,  25, 9, 9,  3,  25, 27, 20, 26, 4,
        13, 0,  6, 28, 22, 14, 20, 19, 13, 27},
       {11, 13, 7, 27, 9,  20, 10, 23, 26, 27,
        23, 3,  0, 19, 24, 17, 23, 4,  3,  9},
       {12, 15, 22, 9, 25, 9,  30, 29, 14, 0,
        14, 23, 9,  0, 17, 24, 25, 10, 21, 30},
       {25, 4,  20, 22, 16, 30, 8,  21, 3, 14,
        16, 18, 13, 11, 0,  4,  30, 1,  9, 26},
       {29, 10, 20, 21, 29, 15, 17, 15, 22, 18,
        15, 21, 17, 20, 14, 0,  28, 23, 8,  6},
       {19, 22, 0, 13, 22, 3, 1, 1, 6, 27, 15, 20, 30, 14, 9, 2, 0, 28, 9, 23},
       {17, 23, 23, 11, 1, 19, 28, 13, 13, 18,
        16, 10, 3,  9,  5, 20, 6,  0,  14, 7},
       {5, 19, 10, 15, 10, 1, 4, 29, 6, 30, 30, 9, 4, 30, 1, 10, 30, 17, 0, 26},
       {5, 15, 1,  20, 20, 19, 25, 21, 4,  3,
        9, 18, 16, 5,  4,  10, 24, 24, 16, 0}});

  ASSERT_EQ(Dijkstra(weighted_graph, 0),
            (std::vector<long long>{0, 12, 11, 13, 9, 8, 6, 6, 11, 11,
                                    9, 7,  4,  11, 8, 7, 5, 8, 7,  13}));
  ASSERT_EQ(Dijkstra(weighted_graph, 1),
            (std::vector<long long>{5,  0, 10, 8, 4, 6, 6, 6, 10, 5,
                                    14, 1, 4,  6, 6, 7, 5, 8, 5,  11}));
  ASSERT_EQ(Dijkstra(weighted_graph, 2),
            (std::vector<long long>{14, 7, 0,  6, 14, 16, 12, 16, 6,  15,
                                    11, 6, 11, 8, 11, 13, 15, 18, 15, 19}));
  ASSERT_EQ(Dijkstra(weighted_graph, 3),
            (std::vector<long long>{6,  1, 11, 0, 5, 10, 9, 12, 12, 6,
                                    15, 2, 5,  2, 8, 10, 6, 9,  6,  13}));
  ASSERT_EQ(Dijkstra(weighted_graph, 4),
            (std::vector<long long>{10, 5, 9, 4, 0,  4, 2, 2, 7, 5,
                                    16, 6, 4, 2, 10, 3, 1, 8, 1, 8}));
  ASSERT_EQ(Dijkstra(weighted_graph, 5),
            (std::vector<long long>{17, 10, 17, 9,  11, 0,  10, 10, 8,  7,
                                    12, 7,  13, 11, 13, 12, 12, 10, 12, 9}));
}
