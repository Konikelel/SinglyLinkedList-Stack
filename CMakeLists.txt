cmake_minimum_required(VERSION 3.11.0)
project(stack VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PROJECT_SOURCES singlyLinkedList.hpp concatenate.hpp stack.hpp)
add_library(ProjectSourcesLib STATIC ${PROJECT_SOURCES})
set_target_properties(ProjectSourcesLib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(stack main.cpp)
target_link_libraries(stack PRIVATE ProjectSourcesLib)

add_subdirectory(tests)