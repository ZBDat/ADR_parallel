#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace sparkplus {

struct CpuInfo {
  std::string model_name;
  std::uint32_t physical_cores = 0;
  std::uint32_t logical_cores = 0;
};

struct GpuInfo {
  std::uint32_t device_id = 0;
  std::string name;
  std::size_t total_memory_bytes = 0;
  std::size_t free_memory_bytes = 0;
};

struct DeviceInfo {
  CpuInfo cpu;
  std::vector<GpuInfo> gpus;
};

class IDeviceInspector {
 public:
  virtual ~IDeviceInspector() = default;
  virtual DeviceInfo query_device_info() const = 0;
};

}  // namespace sparkplus
