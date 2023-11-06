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

// gtest
#include "gtest/gtest.h"

// romea
#include "romea_path_utils/path_matching_point2d_conversions.hpp"


//-----------------------------------------------------------------------------
TEST(TestMatchingPoint2DConvertion, fromRosMsgToRomea)
{
  romea_path_msgs::msg::PathMatchedPoint2D ros_path_matching_point2d_msg;
  ros_path_matching_point2d_msg.section_index = 1;
  ros_path_matching_point2d_msg.curve_index = 2;
  ros_path_matching_point2d_msg.desired_speed = 3;
  ros_path_matching_point2d_msg.future_curvature = 4;

  romea::PathMatchedPoint2D romea_path_matching_point = romea::to_romea(
    ros_path_matching_point2d_msg);

  EXPECT_EQ(
    romea_path_matching_point.sectionIndex,
    ros_path_matching_point2d_msg.section_index);
  EXPECT_EQ(
    romea_path_matching_point.curveIndex,
    ros_path_matching_point2d_msg.curve_index);
  EXPECT_DOUBLE_EQ(
    romea_path_matching_point.desiredSpeed,
    ros_path_matching_point2d_msg.desired_speed);
  EXPECT_DOUBLE_EQ(
    romea_path_matching_point.futureCurvature,
    ros_path_matching_point2d_msg.future_curvature);
}

//-----------------------------------------------------------------------------
TEST(TestMatchingPoint2DConvertion, fromRomeaToRosMsg)
{
  romea::PathMatchedPoint2D romea_path_matching_point;
  romea_path_matching_point.sectionIndex = 1;
  romea_path_matching_point.curveIndex = 2;
  romea_path_matching_point.desiredSpeed = 3;
  romea_path_matching_point.futureCurvature = 4;

  romea_path_msgs::msg::PathMatchedPoint2D ros_path_matching_point2d_msg;
  romea::to_ros_msg(romea_path_matching_point, ros_path_matching_point2d_msg);

  EXPECT_EQ(
    romea_path_matching_point.sectionIndex,
    ros_path_matching_point2d_msg.section_index);
  EXPECT_EQ(
    romea_path_matching_point.curveIndex,
    ros_path_matching_point2d_msg.curve_index);
  EXPECT_DOUBLE_EQ(
    romea_path_matching_point.desiredSpeed,
    ros_path_matching_point2d_msg.desired_speed);
  EXPECT_DOUBLE_EQ(
    romea_path_matching_point.futureCurvature,
    ros_path_matching_point2d_msg.future_curvature);
}

//-----------------------------------------------------------------------------
int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
