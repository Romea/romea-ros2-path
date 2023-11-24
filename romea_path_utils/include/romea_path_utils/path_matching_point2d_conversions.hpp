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

#ifndef ROMEA_PATH_UTILS__PATH_MATCHING_POINT2D_CONVERSIONS_HPP_
#define ROMEA_PATH_UTILS__PATH_MATCHING_POINT2D_CONVERSIONS_HPP_

// std
#include <vector>

// romea
#include "romea_core_path/PathMatchedPoint2D.hpp"
#include "romea_path_msgs/msg/path_matched_point2_d.hpp"

namespace romea
{
namespace ros2
{

void to_ros_msg(
  const core::PathMatchedPoint2D & romea_matched_point2d,
  romea_path_msgs::msg::PathMatchedPoint2D & ros_path_matched_point2d_msg);

void to_romea(
  const romea_path_msgs::msg::PathMatchedPoint2D & matched_point_msg,
  core::PathMatchedPoint2D & romea_matched_point);


core::PathMatchedPoint2D to_romea(
  const romea_path_msgs::msg::PathMatchedPoint2D & matched_point_msg);

std::vector<core::PathMatchedPoint2D> to_romea(
  const std::vector<romea_path_msgs::msg::PathMatchedPoint2D> & matched_point_msgs);

}  // namespace ros2
}  // namespace romea

#endif  // ROMEA_PATH_UTILS__PATH_MATCHING_POINT2D_CONVERSIONS_HPP_
