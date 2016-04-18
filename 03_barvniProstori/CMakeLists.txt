PROJECT(cpp)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

FIND_PACKAGE(OpenCV REQUIRED)
LINK_LIBRARIES(${OpenCV_LIBS})
INCLUDE_DIRECTORIES(AFTER ${CMAKE_CURRENT_BINARY_DIR} ${OpenCV_INCLUDE_DIR})

ADD_EXECUTABLE(threshold threshold.cpp)
ADD_EXECUTABLE(histograms histograms.cpp)
ADD_EXECUTABLE(morphology morphology.cpp)
ADD_EXECUTABLE(filtering filtering.cpp)
ADD_EXECUTABLE(edges edges.cpp)
ADD_EXECUTABLE(hough hough.cpp)
ADD_EXECUTABLE(my_threshold my_threshold.cpp)
ADD_EXECUTABLE(colorful_rings colorful_rings.cpp)

#FILE(COPY eagle.jpg bird.jpg eclipse.jpg clock.jpg DESTINATION ${BUILD_ROOT})

