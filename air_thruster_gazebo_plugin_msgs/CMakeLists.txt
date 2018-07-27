cmake_minimum_required(VERSION 2.8.3)
project(air_thruster_gazebo_plugin_msgs)
find_package(catkin REQUIRED COMPONENTS
    std_msgs
    message_generation
)
find_package(message_generation)
add_message_files(
  FILES
  NamedFloatArray.msg
)
generate_messages(
  DEPENDENCIES
  std_msgs
)
catkin_package(CATKIN_DEPENDS
    std_msgs
    message_runtime
)
