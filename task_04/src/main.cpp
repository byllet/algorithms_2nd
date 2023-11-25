#include <vector>

#include "RMQ.hpp"

int main() {
  std::vector<long long> v = {1, 10, 7, 6, 3, 2, 1, 11};
  RMQ rmq{v};
  return 0;
}
