cmake_minimum_required(VERSION 3.16)
project(matrix_library_demo)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# 统输出⽬录（可选）
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# ------------------------- 变量与路径 -------------------------
# 头⽂件⽬录（PUBLIC 供下游⽬标继承）
set(matrix_library_demo_INC_DIR ${CMAKE_SOURCE_DIR}/include)
# 源⽂件⽬录
set(matrix_library_demo_SRC_DIR ${CMAKE_SOURCE_DIR}/src)
# ------------------------- 收集源⽂件 -------------------------
# ⼿动列出或 file(GLOB ...) 均可；⼿动更稳健
set(matrix_library_demo_SOURCES
 ${matrix_library_demo_SRC_DIR}/main.cpp
 ${matrix_library_demo_SRC_DIR}/Matrix.cpp
 # ${TWO_SRC_DIR}/other.cpp # 以后直接加
)
# ------------------------- 可执⾏⽬标 -------------------------
add_executable(matrix_library_demo ${matrix_library_demo_SOURCES})
# 头⽂件搜索路径
target_include_directories(matrix_library_demo
 PUBLIC
 $<BUILD_INTERFACE:${matrix_library_demo_INC_DIR}>
 $<INSTALL_INTERFACE:include>
)
