#pragma once

#include <string>
#include <vector>

#include "sparkplus/types.hpp"

namespace sparkplus {

struct PipelinePlan {
  ExecutionMode mode = ExecutionMode::kParallel;
  std::vector<std::vector<std::string>> stages;
};

class IPipeline {
 public:
  virtual ~IPipeline() = default;
  virtual void configure(const PipelinePlan& plan) = 0;
  virtual PipelinePlan current_plan() const = 0;
};

}  // namespace sparkplus
