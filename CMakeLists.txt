cmake_minimum_required(VERSION 3.20)
project(sparkplus VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(sparkplus_headers INTERFACE)
target_include_directories(sparkplus_headers INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(sparkplus_headers INTERFACE cxx_std_17)

find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(_sparkplus python/bindings.cpp)
target_link_libraries(_sparkplus PRIVATE sparkplus_headers)

target_compile_features(_sparkplus PRIVATE cxx_std_17)

install(TARGETS _sparkplus LIBRARY DESTINATION sparkplus RUNTIME DESTINATION sparkplus)
install(FILES python/sparkplus/__init__.py python/sparkplus/py.typed DESTINATION sparkplus)
install(DIRECTORY include/ DESTINATION include)
