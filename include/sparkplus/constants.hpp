#pragma once

#include <cstddef>
#include <cstdint>

namespace sparkplus {

inline constexpr const char* kLibraryName = "sparkplus";
inline constexpr const char* kDefaultLoggerName = "sparkplus.adr";

inline constexpr std::size_t kDefaultInputQueueDepth = 256;
inline constexpr std::size_t kDefaultOutputQueueDepth = 256;
inline constexpr std::size_t kDefaultWorkerThreads = 0;

inline constexpr std::uint32_t kInvalidDeviceId = 0xFFFFFFFFu;

}  // namespace sparkplus
