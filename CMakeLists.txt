cmake_minimum_required(VERSION 3.8)
project(feature_test)

#set(CMAKE_CXX_STANDARD 11)
set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

find_package(OpenCV 3.1 REQUIRED)
find_package(Eigen3 3.1.0 REQUIRED)

include_directories(
        ${OpenCV_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIR}
)

set(	LIBS
        ${EIGEN3_LIBS}
        ${OpenCV_LIBS}
)

set(SOURCE_FILES main.cpp lib.h feature.cpp feature.h)
add_executable(feature_test ${SOURCE_FILES})
target_link_libraries(feature_test ${LIBS})