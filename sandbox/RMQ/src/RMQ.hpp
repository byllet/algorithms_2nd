#pragma once

#include <vector>

class RMQ {
 public:
  RMQ(std::vector<long long>& numbers);
  long long GetMin(size_t i, size_t len);

 private:
  std::vector<std::vector<size_t>> sparse_table;
};