cmake_minimum_required(VERSION 3.5)
project(romea_path_utils)

# Default to C99
if(NOT CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(romea_core_common REQUIRED)
find_package(romea_core_path REQUIRED)
find_package(romea_common_msgs REQUIRED)
find_package(romea_common_utils REQUIRED)
find_package(romea_path_msgs REQUIRED)


add_library(${PROJECT_NAME}
    src/path_frenet_pose2d_conversions.cpp
    src/path_matching_info_conversions.cpp
    src/path_matching_point2d_conversions.cpp
    src/path_posture2d_conversions.cpp)

ament_target_dependencies(${PROJECT_NAME}
    rclcpp
    romea_core_common
    romea_core_path
    std_msgs
    romea_common_msgs
    romea_common_utils
    romea_path_msgs)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

ament_export_dependencies(eigen3_cmake_module)
ament_export_dependencies(Eigen3)
ament_export_dependencies(rclcpp)
ament_export_dependencies(std_msgs)
ament_export_dependencies(romea_core_common)
ament_export_dependencies(romea_core_path)
ament_export_dependencies(romea_common_msgs)
ament_export_dependencies(romea_common_utils)
ament_export_dependencies(romea_path_msgs)

ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
#ament_export_targets(${PROJECT_NAME})

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

#install(TARGETS ${PROJECT_NAME}_node DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)

    find_package(ament_lint_auto REQUIRED)
    ament_lint_auto_find_test_dependencies()
    list(APPEND AMENT_LINT_AUTO_EXCLUDE ament_cmake_copyright)
    add_subdirectory(test)

endif()

ament_package()

