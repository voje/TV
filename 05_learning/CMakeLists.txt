PROJECT(cpp)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

FIND_PACKAGE(OpenCV REQUIRED)
LINK_LIBRARIES(${OpenCV_LIBS})
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_BINARY_DIR} ${OpenCV_INCLUDE_DIR})
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall")    #don't need, fixed the code

ADD_EXECUTABLE(face face.cpp)
ADD_EXECUTABLE(faces faces.cpp utilities.cpp)
ADD_EXECUTABLE(detector detector.cpp)
ADD_EXECUTABLE(bow bow.cpp utilities.cpp)  #some errors

#FILE(COPY face_cascade.xml DESTINATION ${BUILD_ROOT})
