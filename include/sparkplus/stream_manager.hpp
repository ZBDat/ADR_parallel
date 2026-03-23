#pragma once

#include <cstddef>
#include <cstdint>

namespace sparkplus {

using StreamHandle = std::uintptr_t;

class IStreamManager {
 public:
  virtual ~IStreamManager() = default;
  virtual StreamHandle create_stream(std::uint32_t device_id, std::size_t priority) = 0;
  virtual void synchronize_stream(StreamHandle stream) = 0;
  virtual void synchronize_device(std::uint32_t device_id) = 0;
  virtual void destroy_stream(StreamHandle stream) = 0;
};

}  // namespace sparkplus
