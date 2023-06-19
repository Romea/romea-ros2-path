// Copyright 2022 INRAE, French National Research Institute for Agriculture, Food and Environment
// Add license

#ifndef ROMEA_PATH_UTILS__PATH_POSTURE2D_CONVERSIONS_HPP_
#define ROMEA_PATH_UTILS__PATH_POSTURE2D_CONVERSIONS_HPP_

// romea
#include "romea_core_path/PathPosture2D.hpp"
#include "romea_path_msgs/msg/path_posture2_d.hpp"

namespace romea
{

void to_ros_msg(
  const PathPosture2D & romea_path_posture2d,
  romea_path_msgs::msg::PathPosture2D & ros_path_posture2d_msg);

void to_romea(
  const romea_path_msgs::msg::PathPosture2D & posture_msg,
  PathPosture2D & romea_path_posture);

PathPosture2D to_romea(const romea_path_msgs::msg::PathPosture2D & posture_msg);

}  // namespace romea

#endif  // ROMEA_PATH_UTILS__PATH_POSTURE2D_CONVERSIONS_HPP_
