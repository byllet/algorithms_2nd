
#include <gtest/gtest.h>

#include "RMQ.hpp"

TEST(RMQ, Simple) {
  std::vector<long long> v1{1, 10, 7, 6, 3, 2, 1, 11};
  RMQ rmq1{v1};
  ASSERT_EQ(rmq1.GetMin(2, 2), 6);
  ASSERT_EQ(rmq1.GetMin(0, 8), 1);
  ASSERT_EQ(rmq1.GetMin(4, 1), 3);

  std::vector<long long> v2{1, 2, 3};
  RMQ rmq2{v2};
  ASSERT_EQ(rmq2.GetMin(1, 1), 2);
  ASSERT_EQ(rmq2.GetMin(0, 3), 1);
}
