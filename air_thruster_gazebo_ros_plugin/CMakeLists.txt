cmake_minimum_required(VERSION 2.8.3)
project(air_thruster_gazebo_ros_plugin)
add_compile_options(-std=c++11)
find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    air_thruster_gazebo_plugin
)

set(AIR_THRUSTER_GAZEBO_ROS_PLUGINS_LIST "")

find_package(gazebo REQUIRED)
catkin_package(
    INCLUDE_DIRS include
    ${PROJECT_SOURCE_DIR}/include
    ${catkin_INCLUDE_DIRS}
    ${GAZEBO_INCLUDE_DIRS}
    ${GAZEBO_MSG_INCLUDE_DIRS}
    LIBRARIES air_thruster_gazebo_plugin
    CATKIN_DEPENDS air_thruster_gazebo_plugin
)
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${catkin_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}
  ${GAZEBO_MSG_INCLUDE_DIRS}
)

link_directories(
  ${GAZEBO_LIBRARY_DIRS}
)

add_library(air_thruster_ros_plugin src/AirThrusterROSPlugin.cpp)
target_link_libraries(air_thruster_ros_plugin ${catkin_LIBRARIES})
add_dependencies(air_thruster_ros_plugin ${catkin_EXPORTED_TARGETS})
list(APPEND AIR_THRUSTER_GAZEBO_ROS_PLUGINS_LIST air_thruster_ros_plugin)
