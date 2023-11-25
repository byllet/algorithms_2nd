#pragma once

class AbstractFunction {
 public:
  virtual void OnEdge(unsigned long long vertex) = 0;
  virtual void OnVertexBefore(unsigned long long vertex) = 0;
  virtual void OnVertexAfter(unsigned long long vertex) = 0;
};