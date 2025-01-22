cmake_minimum_required(VERSION 3.5)
project(romea_path_msgs)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(romea_common_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
    msg/PathPosture2D.msg
    msg/PathFrenetPose2D.msg
    msg/PathMatchedPoint2D.msg
    msg/PathMatchingInfo2D.msg
    msg/PathAnnotation.msg
    msg/PathAnnotations.msg
    DEPENDENCIES std_msgs romea_common_msgs)

ament_export_dependencies(rosidl_default_runtime)
ament_package()

