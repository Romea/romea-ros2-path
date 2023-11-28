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

#ifndef ROMEA_PATH_UTILS__PATH_MATCHING_INFO_CONVERSIONS_HPP_
#define ROMEA_PATH_UTILS__PATH_MATCHING_INFO_CONVERSIONS_HPP_


// std
#include <vector>

// romea
#include "romea_core_path/PathMatchedPoint2D.hpp"
#include "romea_path_msgs/msg/path_matching_info2_d.hpp"
#include "romea_core_common/geometry/Twist2D.hpp"
#include "romea_core_common/time/Time.hpp"

// ros
#include "rclcpp/time.hpp"

namespace romea
{
namespace ros2
{


romea_path_msgs::msg::PathMatchingInfo2D to_ros_msg(
  const core::Duration & duration,
  const core::PathMatchedPoint2D & matched_point,
  const double & path_length,
  const core::Twist2D & twist);

romea_path_msgs::msg::PathMatchingInfo2D to_ros_msg(
  const rclcpp::Time & stamp,
  const core::PathMatchedPoint2D & matched_point,
  const double & path_length,
  const core::Twist2D & twist);

romea_path_msgs::msg::PathMatchingInfo2D to_ros_msg(
  const core::Duration & duration,
  const std::vector<core::PathMatchedPoint2D> & matched_points,
  const size_t & tracked_matched_point_index,
  const double & path_length,
  const core::Twist2D & twist);

romea_path_msgs::msg::PathMatchingInfo2D to_ros_msg(
  const rclcpp::Time & stamp,
  const std::vector<core::PathMatchedPoint2D> & matched_points,
  const size_t & tracked_matched_point_index,
  const double & path_length,
  const core::Twist2D & twist);


std::vector<core::PathMatchedPoint2D> to_romea(
  const romea_path_msgs::msg::PathMatchingInfo2D::_matched_points_type & matched_point_msgs);


}  // namespace ros2
}  // namespace romea

#endif  // ROMEA_PATH_UTILS__PATH_MATCHING_INFO_CONVERSIONS_HPP_
