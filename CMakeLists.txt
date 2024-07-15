cmake_minimum_required(VERSION 3.0.2)
project(depth_camera_sim)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  gazebo_ros
  sensor_msgs
)

find_package(gazebo REQUIRED)

catkin_package(
  CATKIN_DEPENDS roscpp gazebo_ros sensor_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}
)

link_directories(${GAZEBO_LIBRARY_DIRS})

add_executable(depth_camera_processor src/depth_camera_processor.cpp)
target_link_libraries(depth_camera_processor 
  ${catkin_LIBRARIES}
  ${GAZEBO_LIBRARIES}
)

install(DIRECTORY launch worlds models
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)