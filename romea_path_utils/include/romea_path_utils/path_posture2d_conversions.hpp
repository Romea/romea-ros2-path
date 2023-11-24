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

#ifndef ROMEA_PATH_UTILS__PATH_POSTURE2D_CONVERSIONS_HPP_
#define ROMEA_PATH_UTILS__PATH_POSTURE2D_CONVERSIONS_HPP_

// romea
#include "romea_core_path/PathPosture2D.hpp"
#include "romea_path_msgs/msg/path_posture2_d.hpp"

namespace romea
{
namespace ros2
{

void to_ros_msg(
  const core::PathPosture2D & romea_path_posture2d,
  romea_path_msgs::msg::PathPosture2D & ros_path_posture2d_msg);

void to_romea(
  const romea_path_msgs::msg::PathPosture2D & posture_msg,
  core::PathPosture2D & romea_path_posture);

core::PathPosture2D to_romea(const romea_path_msgs::msg::PathPosture2D & posture_msg);

}  // namespace ros2
}  // namespace romea

#endif  // ROMEA_PATH_UTILS__PATH_POSTURE2D_CONVERSIONS_HPP_
