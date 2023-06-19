// Copyright 2022 INRAE, French National Research Institute for Agriculture, Food and Environment
// Add license

#ifndef ROMEA_PATH_UTILS__PATH_MATCHING_POINT2D_CONVERSIONS_HPP_
#define ROMEA_PATH_UTILS__PATH_MATCHING_POINT2D_CONVERSIONS_HPP_

// romea
#include "romea_core_path/PathMatchedPoint2D.hpp"
#include "romea_path_msgs/msg/path_matched_point2_d.hpp"

namespace romea
{

void to_ros_msg(
  const PathMatchedPoint2D & romea_matched_point2d,
  romea_path_msgs::msg::PathMatchedPoint2D & ros_path_matched_point2d_msg);

void to_romea(
  const romea_path_msgs::msg::PathMatchedPoint2D & matched_point_msg,
  PathMatchedPoint2D & romea_matched_point);

PathMatchedPoint2D to_romea(const romea_path_msgs::msg::PathMatchedPoint2D & matched_point_msg);

}  // namespace romea

#endif  // ROMEA_PATH_UTILS__PATH_MATCHING_POINT2D_CONVERSIONS_HPP_
