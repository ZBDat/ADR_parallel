#pragma once

#include <stdexcept>
#include <string>

namespace sparkplus {

class SparkplusError : public std::runtime_error {
 public:
  explicit SparkplusError(const std::string& message) : std::runtime_error(message) {}
};

class ConfigurationError : public SparkplusError {
 public:
  explicit ConfigurationError(const std::string& message) : SparkplusError(message) {}
};

class DeviceError : public SparkplusError {
 public:
  explicit DeviceError(const std::string& message) : SparkplusError(message) {}
};

class SessionError : public SparkplusError {
 public:
  explicit SessionError(const std::string& message) : SparkplusError(message) {}
};

class MemoryError : public SparkplusError {
 public:
  explicit MemoryError(const std::string& message) : SparkplusError(message) {}
};

}  // namespace sparkplus
