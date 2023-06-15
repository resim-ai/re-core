
cmake_minimum_required(VERSION 3.5)

project(ResimViewDemo)

find_package(Eigen3 3.4.0 REQUIRED NO_MODULE)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

link_directories(${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(example_00_rigid_transform example_00_rigid_transform.cc)
target_link_libraries(example_00_rigid_transform Eigen3::Eigen review)

add_executable(example_01_framed_transform_composition example_01_framed_transform_composition.cc)
target_link_libraries(example_01_framed_transform_composition Eigen3::Eigen review)
