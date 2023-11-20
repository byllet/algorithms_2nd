#include "RMQ.hpp"

#include <cmath>

RMQ::RMQ(std::vector<long long>& numbers) {
  size_t size = std::ceil(std::log2(numbers.size()));
  sparse_table.assign(size + 1, std::vector<size_t>());

  for (const auto& number : numbers) {
    sparse_table[0].push_back(number);
  }

  unsigned long long current_len = 1;
  for (size_t j = 1; j < sparse_table.size(); ++j) {
    size_t len_of_current_vec = sparse_table[j - 1].size() - current_len;
    for (size_t i = 0; i < len_of_current_vec; ++i) {
      sparse_table[j].push_back(std::min(sparse_table[j - 1][i],
                                         sparse_table[j - 1][i + current_len]));
    }
    current_len *= 2;
  }
}

long long RMQ::GetMin(size_t i, size_t len) {
  size_t t = std::floor(std::log2(len));
  return std::min(sparse_table[t][i], sparse_table[t][i + len - 1 - t]);
}
