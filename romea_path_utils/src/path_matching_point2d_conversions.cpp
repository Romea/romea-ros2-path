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

#include "romea_path_utils/path_matching_point2d_conversions.hpp"
#include "romea_path_utils/path_frenet_pose2d_conversions.hpp"
#include "romea_path_utils/path_posture2d_conversions.hpp"

namespace romea
{

namespace ros2
{

//-----------------------------------------------------------------------------
void to_ros_msg(
  const core::PathMatchedPoint2D & romea_matched_point2d,
  romea_path_msgs::msg::PathMatchedPoint2D & ros_path_matched_point2d_msg)
{
  to_ros_msg(romea_matched_point2d.pathPosture, ros_path_matched_point2d_msg.posture);
  to_ros_msg(romea_matched_point2d.frenetPose, ros_path_matched_point2d_msg.frenet_pose);
  ros_path_matched_point2d_msg.future_curvature = romea_matched_point2d.futureCurvature;
  ros_path_matched_point2d_msg.desired_speed = romea_matched_point2d.desiredSpeed;
  ros_path_matched_point2d_msg.section_index = romea_matched_point2d.sectionIndex;
  ros_path_matched_point2d_msg.curve_index = romea_matched_point2d.curveIndex;
}


//-----------------------------------------------------------------------------
void to_romea(
  const romea_path_msgs::msg::PathMatchedPoint2D & matched_point_msg,
  core::PathMatchedPoint2D & romea_matched_point)
{
  to_romea(matched_point_msg.posture, romea_matched_point.pathPosture);
  to_romea(matched_point_msg.frenet_pose, romea_matched_point.frenetPose);
  romea_matched_point.futureCurvature = matched_point_msg.future_curvature;
  romea_matched_point.desiredSpeed = matched_point_msg.desired_speed;
  romea_matched_point.sectionIndex = matched_point_msg.section_index;
  romea_matched_point.curveIndex = matched_point_msg.curve_index;
}


//-----------------------------------------------------------------------------
core::PathMatchedPoint2D to_romea(
  const romea_path_msgs::msg::PathMatchedPoint2D & matched_point_msg)
{
  core::PathMatchedPoint2D romea_matched_point;
  to_romea(matched_point_msg, romea_matched_point);
  return romea_matched_point;
}


//-----------------------------------------------------------------------------
std::vector<core::PathMatchedPoint2D> to_romea(
  const std::vector<romea_path_msgs::msg::PathMatchedPoint2D> & matched_point_msgs)
{
  std::vector<core::PathMatchedPoint2D> romea_matched_points;
  for (const auto & msg : matched_point_msgs) {
    romea_matched_points.push_back(to_romea(msg));
  }
  return romea_matched_points;
}

}  // namespace ros2
}  // namespace romea
