#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "sparkplus/sparkplus.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_sparkplus, m) {
  m.doc() = "sparkplus interface-first ADR APIs";

  py::register_exception<sparkplus::SparkplusError>(m, "SparkplusError");
  py::register_exception<sparkplus::ConfigurationError>(m, "ConfigurationError");
  py::register_exception<sparkplus::DeviceError>(m, "DeviceError");
  py::register_exception<sparkplus::SessionError>(m, "SessionError");
  py::register_exception<sparkplus::MemoryError>(m, "MemoryError");

  py::enum_<sparkplus::DeviceKind>(m, "DeviceKind")
      .value("CPU", sparkplus::DeviceKind::kCpu)
      .value("CUDA", sparkplus::DeviceKind::kCuda)
      .value("AUTO", sparkplus::DeviceKind::kAuto);

  py::enum_<sparkplus::ExecutionMode>(m, "ExecutionMode")
      .value("PARALLEL", sparkplus::ExecutionMode::kParallel)
      .value("CASCADE", sparkplus::ExecutionMode::kCascade)
      .value("HYBRID", sparkplus::ExecutionMode::kHybrid);

  py::class_<sparkplus::CpuInfo>(m, "CpuInfo")
      .def(py::init<>())
      .def_readwrite("model_name", &sparkplus::CpuInfo::model_name)
      .def_readwrite("physical_cores", &sparkplus::CpuInfo::physical_cores)
      .def_readwrite("logical_cores", &sparkplus::CpuInfo::logical_cores);

  py::class_<sparkplus::GpuInfo>(m, "GpuInfo")
      .def(py::init<>())
      .def_readwrite("device_id", &sparkplus::GpuInfo::device_id)
      .def_readwrite("name", &sparkplus::GpuInfo::name)
      .def_readwrite("total_memory_bytes", &sparkplus::GpuInfo::total_memory_bytes)
      .def_readwrite("free_memory_bytes", &sparkplus::GpuInfo::free_memory_bytes);

  py::class_<sparkplus::DeviceInfo>(m, "DeviceInfo")
      .def(py::init<>())
      .def_readwrite("cpu", &sparkplus::DeviceInfo::cpu)
      .def_readwrite("gpus", &sparkplus::DeviceInfo::gpus);

  py::class_<sparkplus::SessionOptions>(m, "SessionOptions")
      .def(py::init<>())
      .def_readwrite("intra_op_threads", &sparkplus::SessionOptions::intra_op_threads)
      .def_readwrite("inter_op_threads", &sparkplus::SessionOptions::inter_op_threads)
      .def_readwrite("enable_graph_optimizations", &sparkplus::SessionOptions::enable_graph_optimizations)
      .def_readwrite("enable_cuda", &sparkplus::SessionOptions::enable_cuda)
      .def_readwrite("cuda_device_id", &sparkplus::SessionOptions::cuda_device_id);

  py::class_<sparkplus::PipelinePlan>(m, "PipelinePlan")
      .def(py::init<>())
      .def_readwrite("mode", &sparkplus::PipelinePlan::mode)
      .def_readwrite("stages", &sparkplus::PipelinePlan::stages);

  py::class_<sparkplus::IRunnable, std::shared_ptr<sparkplus::IRunnable>>(m, "IRunnable")
      .def("run", &sparkplus::IRunnable::run);

  py::class_<sparkplus::ADR, sparkplus::IRunnable, std::shared_ptr<sparkplus::ADR>>(m, "ADR")
      .def("get_device_info", &sparkplus::ADR::get_device_info)
      .def("load_onnx_model", &sparkplus::ADR::load_onnx_model)
      .def("stop", &sparkplus::ADR::stop)
      .def("is_running", &sparkplus::ADR::is_running)
      .def("run", &sparkplus::ADR::run);

  py::class_<sparkplus::ParallelADR, sparkplus::ADR, std::shared_ptr<sparkplus::ParallelADR>>(m,
                                                                                                 "ParallelADR")
      .def("run", &sparkplus::ParallelADR::run);

  py::class_<sparkplus::CascadeADR, sparkplus::ADR, std::shared_ptr<sparkplus::CascadeADR>>(m,
                                                                                               "CascadeADR")
      .def("run", &sparkplus::CascadeADR::run);

  m.attr("LIBRARY_NAME") = sparkplus::kLibraryName;
}
