#pragma once

#include <memory>
#include <string>
#include <vector>

#include "sparkplus/types.hpp"

namespace sparkplus {

struct SessionOptions {
  std::size_t intra_op_threads = 0;
  std::size_t inter_op_threads = 0;
  bool enable_graph_optimizations = true;
  bool enable_cuda = true;
  std::uint32_t cuda_device_id = 0;
};

class ISession {
 public:
  virtual ~ISession() = default;
  virtual const std::string& model_name() const = 0;
  virtual OutputBatch infer(const InputBatch& batch) = 0;
};

class ISessionManager {
 public:
  virtual ~ISessionManager() = default;
  virtual void load_model(const std::string& model_name,
                          const std::string& onnx_file_path,
                          const SessionOptions& options) = 0;
  virtual std::shared_ptr<ISession> get_session(const std::string& model_name) = 0;
  virtual std::vector<std::string> loaded_models() const = 0;
};

}  // namespace sparkplus
