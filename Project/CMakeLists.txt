cmake_minimum_required(VERSION 2.8.11)
project(rgb_interaction)

find_package(OpenCV REQUIRED)
link_libraries(${OpenCV_LIBS})

add_executable(head_bob head_bob.cpp)
add_executable(detector detector.cpp)


