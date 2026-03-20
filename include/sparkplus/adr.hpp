#pragma once

#include <memory>
#include <string>

#include "sparkplus/device_info.hpp"
#include "sparkplus/input_feed.hpp"
#include "sparkplus/memory_manager.hpp"
#include "sparkplus/pipeline.hpp"
#include "sparkplus/session_manager.hpp"
#include "sparkplus/stream_manager.hpp"
#include "sparkplus/types.hpp"

namespace sparkplus {

class IRunnable {
 public:
  virtual ~IRunnable() = default;
  virtual void run() noexcept = 0;
};

class ADR : public IRunnable {
 public:
  ~ADR() override = default;

  virtual void set_logger(LogCallback logger) = 0;
  virtual void set_exception_handler(ExceptionCallback handler) = 0;

  virtual DeviceInfo get_device_info() const = 0;

  virtual void attach_input_feed(std::shared_ptr<IInputFeed> feed) = 0;
  virtual void attach_output_sink(std::shared_ptr<IOutputSink> sink) = 0;

  virtual void attach_session_manager(std::shared_ptr<ISessionManager> manager) = 0;
  virtual void attach_stream_manager(std::shared_ptr<IStreamManager> manager) = 0;
  virtual void attach_memory_manager(std::shared_ptr<IMemoryManager> manager) = 0;
  virtual void attach_pipeline(std::shared_ptr<IPipeline> pipeline) = 0;

  virtual void load_onnx_model(const std::string& model_name,
                               const std::string& onnx_file_path,
                               const SessionOptions& options) = 0;

  virtual void stop() = 0;
  virtual bool is_running() const = 0;

  virtual void run() noexcept override = 0;
};

class ParallelADR : public ADR {
 public:
  ~ParallelADR() override = default;
  void run() noexcept override = 0;
};

class CascadeADR : public ADR {
 public:
  ~CascadeADR() override = default;
  void run() noexcept override = 0;
};

std::shared_ptr<ADR> create_parallel_adr();
std::shared_ptr<ADR> create_cascade_adr();

}  // namespace sparkplus
