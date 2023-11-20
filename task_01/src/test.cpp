
#include <gtest/gtest.h>

#include <vector>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  Graph test1({{1, {2, 3}}, {2, {4, 5}}, {3, {}}, {4, {3, 5}}, {5, {}}});
  ASSERT_EQ((test1.TopologySort(1)),
            (std::vector<unsigned int>{1, 2, 4, 5, 3}));
  ASSERT_EQ((test1.TopologySort(2)), (std::vector<unsigned int>{2, 4, 5, 3}));
}

TEST(TopologySort, Middle) {
  Graph test1(
      {{1, {4, 5, 3}}, {2, {4, 5}}, {3, {2}}, {4, {5, 3, 1}}, {5, {4}}});
  ASSERT_EQ((test1.TopologySort(1)),
            (std::vector<unsigned int>{1, 4, 3, 2, 5}));
  ASSERT_EQ((test1.TopologySort(2)),
            (std::vector<unsigned int>{2, 4, 1, 3, 5}));
  ASSERT_EQ((test1.TopologySort(3)),
            (std::vector<unsigned int>{3, 2, 4, 1, 5}));
  ASSERT_EQ((test1.TopologySort(4)),
            (std::vector<unsigned int>{4, 1, 3, 2, 5}));

  Graph test2({{1, {6, 2, 4, 5, 7}},
               {2, {5, 1}},
               {3, {4, 1, 5, 6}},
               {4, {6, 2, 1, 3, 7}},
               {5, {6}},
               {6, {7}},
               {7, {4}}});
  ASSERT_EQ((test2.TopologySort(3)),
            (std::vector<unsigned int>{3, 4, 2, 1, 5, 6, 7}));
  ASSERT_EQ((test2.TopologySort(1)),
            (std::vector<unsigned int>{1, 6, 7, 4, 3, 2, 5}));
}

TEST(TopologySort, Hard) {
  Graph test1({{1, {12, 4}},
               {2, {12, 8, 4, 10, 3, 11, 9, 6, 1, 5}},
               {3, {7, 10, 12, 1, 6, 11, 4, 5}},
               {4, {11, 6, 1, 8, 9, 5, 3, 7, 2, 12}},
               {5, {11}},
               {6, {5, 11, 8, 7}},
               {7, {3, 9, 6, 12, 1, 11}},
               {8, {7, 3}},
               {9, {2, 5, 1}},
               {10, {2, 7}},
               {11, {3, 8, 6}},
               {12, {5, 11, 4, 3, 1}}});
  ASSERT_EQ((test1.TopologySort(1)),
            (std::vector<unsigned int>{1, 12, 5, 11, 3, 7, 9, 2, 10, 4, 6, 8}));
  ASSERT_EQ((test1.TopologySort(12)),
            (std::vector<unsigned int>{12, 5, 11, 3, 7, 9, 2, 10, 4, 1, 6, 8}));
  ASSERT_EQ((test1.TopologySort(6)),
            (std::vector<unsigned int>{6, 5, 11, 3, 7, 9, 2, 10, 12, 4, 8, 1}));
  ASSERT_EQ((test1.TopologySort(5)),
            (std::vector<unsigned int>{5, 11, 3, 7, 9, 2, 10, 12, 4, 1, 6, 8}));
}
