#pragma once

#include <cstddef>
#include <cstdint>

namespace sparkplus {

struct MemoryStats {
  std::size_t cpu_reserved_bytes = 0;
  std::size_t gpu_reserved_bytes = 0;
  std::size_t cpu_in_use_bytes = 0;
  std::size_t gpu_in_use_bytes = 0;
};

class IMemoryManager {
 public:
  virtual ~IMemoryManager() = default;
  virtual void reserve_cpu(std::size_t bytes) = 0;
  virtual void reserve_gpu(std::uint32_t device_id, std::size_t bytes) = 0;
  virtual void* allocate_cpu(std::size_t bytes, std::size_t alignment) = 0;
  virtual void release_cpu(void* ptr, std::size_t bytes) = 0;
  virtual void* allocate_gpu(std::uint32_t device_id, std::size_t bytes) = 0;
  virtual void release_gpu(std::uint32_t device_id, void* ptr, std::size_t bytes) = 0;
  virtual MemoryStats stats() const = 0;
};

}  // namespace sparkplus
