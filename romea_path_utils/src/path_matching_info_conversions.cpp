// Copyright 2022 INRAE, French National Research Institute for Agriculture, Food and Environment
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and

#include <vector>

#include "romea_path_utils/path_matching_info_conversions.hpp"
#include "romea_path_utils/path_matching_point2d_conversions.hpp"

#include "romea_common_utils/conversions/time_conversions.hpp"
#include "romea_common_utils/conversions/twist2d_conversions.hpp"

namespace romea
{

//-----------------------------------------------------------------------------
romea_path_msgs::msg::PathMatchingInfo2D to_ros_msg(
  const Duration & duration,
  const PathMatchedPoint2D & matched_point,
  const double & path_length,
  const Twist2D & twist)
{
  return to_ros_msg(
    to_ros_time(duration),
    matched_point,
    path_length,
    twist);
}

//-----------------------------------------------------------------------------
romea_path_msgs::msg::PathMatchingInfo2D to_ros_msg(
  const rclcpp::Time & stamp,
  const PathMatchedPoint2D & matched_point,
  const double & path_length,
  const Twist2D & twist)
{
  romea_path_msgs::msg::PathMatchingInfo2D msg;
  msg.header.frame_id = "path";
  msg.header.stamp = stamp;
  msg.matched_points.resize(1);
  to_ros_msg(matched_point, msg.matched_points[0]);
  msg.path_length = path_length;
  to_ros_msg(twist, msg.twist);
  return msg;
}

//-----------------------------------------------------------------------------
romea_path_msgs::msg::PathMatchingInfo2D to_ros_msg(
  const Duration & duration,
  const std::vector<PathMatchedPoint2D> & matched_points,
  const size_t & tracked_matched_point_index,
  const double & path_length,
  const Twist2D & twist)
{
  return to_ros_msg(
    to_ros_time(duration),
    matched_points,
    tracked_matched_point_index,
    path_length,
    twist);
}

//-----------------------------------------------------------------------------
romea_path_msgs::msg::PathMatchingInfo2D to_ros_msg(
  const rclcpp::Time & stamp,
  const std::vector<PathMatchedPoint2D> & matched_points,
  const size_t & tracked_matched_point_index,
  const double & path_length,
  const Twist2D & twist)
{
  romea_path_msgs::msg::PathMatchingInfo2D msg;
  msg.header.frame_id = "path";
  msg.header.stamp = stamp;
  msg.matched_points.resize(matched_points.size());
  for (size_t n = 0; n < matched_points.size(); ++n) {
    to_ros_msg(matched_points[n], msg.matched_points[n]);
  }
  msg.tracked_matched_point_index = tracked_matched_point_index;
  msg.path_length = path_length;
  to_ros_msg(twist, msg.twist);
  return msg;
}

}  // namespace romea
