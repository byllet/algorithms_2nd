
#include <gtest/gtest.h>

#include <vector>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  Graph test1({{1, {2, 3}}, {2, {4, 5}}, {3, {}}, {4, {3, 5}}, {5, {}}});
  ASSERT_EQ((test1.Topology_sort(1)),
            (std::vector<unsigned int>{1, 2, 4, 5, 3}));
  ASSERT_EQ((test1.Topology_sort(2)), (std::vector<unsigned int>{2, 4, 5, 3}));
}
