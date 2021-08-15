cmake_minimum_required(VERSION 3.0.2)
project(davis_ros)
set(CMAKE_BUILD_TYPE "Release")

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(
    catkin REQUIRED
    dvs_msgs
    roscpp
    std_msgs
    cv_bridge
    image_transport
)

find_package(OpenCV REQUIRED)
find_package(gflags REQUIRED)


catkin_package()

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
    include
    ${catkin_INCLUDE_DIRS}

)


add_executable(event_node src/event_node.cpp)
target_link_libraries(event_node ${catkin_LIBRARIES} ${OpenCV_LIBS})
