#pragma once

#include <cstddef>
#include <cstdint>
#include <functional>
#include <string>
#include <vector>

namespace sparkplus {

enum class DeviceKind : std::uint8_t {
  kCpu = 0,
  kCuda = 1,
  kAuto = 2,
};

enum class ExecutionMode : std::uint8_t {
  kParallel = 0,
  kCascade = 1,
  kHybrid = 2,
};

enum class LogLevel : std::uint8_t {
  kTrace = 0,
  kDebug = 1,
  kInfo = 2,
  kWarning = 3,
  kError = 4,
  kCritical = 5,
};

using TensorShape = std::vector<std::int64_t>;

struct TensorView {
  std::string name;
  void* data = nullptr;
  std::size_t bytes = 0;
  TensorShape shape;
  std::string dtype;
};

struct InputBatch {
  std::vector<TensorView> tensors;
  std::uint64_t sequence_id = 0;
};

struct OutputBatch {
  std::vector<TensorView> tensors;
  std::uint64_t sequence_id = 0;
};

using LogCallback = std::function<void(LogLevel level, const std::string& message)>;
using ExceptionCallback = std::function<void(const std::exception& error)>;

}  // namespace sparkplus
