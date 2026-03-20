#pragma once

#include "sparkplus/types.hpp"

namespace sparkplus {

class IInputFeed {
 public:
  virtual ~IInputFeed() = default;
  virtual bool pop_next(InputBatch& batch) = 0;
};

class IOutputSink {
 public:
  virtual ~IOutputSink() = default;
  virtual void publish(OutputBatch batch) = 0;
};

}  // namespace sparkplus
