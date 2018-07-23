cmake_minimum_required(VERSION 2.8.3)
project(air_thruster_gazebo_plugin)
add_compile_options(-std=c++11)
find_package(catkin REQUIRED)
find_package(gazebo REQUIRED)

catkin_package(
  INCLUDE_DIRS include
               ${catkin_INCLUDE_DIRS}
               ${GAZEBO_INCLUDE_DIRS}
               ${GAZEBO_MSG_INCLUDE_DIRS}
  LIBRARIES
    air_thruster_plugin
  DEPENDS gazebo
)

include_directories(${GAZEBO_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
)

set(AIR_THRUSTER_GAZEBO_PLUGINS_LIST "")

link_directories(${GAZEBO_LIBRARY_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")
add_library(air_thruster_plugin SHARED src/AirThrusterPlugin.cpp)
target_link_libraries(air_thruster_plugin ${GAZEBO_LIBRARIES})
list(APPEND AIR_THRUSTER_GAZEBO_PLUGINS_LIST air_thruster_plugin)
