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
#include "romea_path_utils/path_posture2d_conversions.hpp"


//-----------------------------------------------------------------------------
TEST(TestPosture2dConvertion, fromRosMsgToRomea)
{
  romea_path_msgs::msg::PathPosture2D ros_posture2d_msg;
  ros_posture2d_msg.x = 1;
  ros_posture2d_msg.y = 2;
  ros_posture2d_msg.course = 3;
  ros_posture2d_msg.curvature = 4;
  ros_posture2d_msg.dot_curvature = 5;

  romea::PathPosture2D romea_path_posture2d = romea::to_romea(ros_posture2d_msg);

  EXPECT_DOUBLE_EQ(romea_path_posture2d.position.x(), ros_posture2d_msg.x);
  EXPECT_DOUBLE_EQ(romea_path_posture2d.position.y(), ros_posture2d_msg.y);
  EXPECT_DOUBLE_EQ(romea_path_posture2d.course, ros_posture2d_msg.course);
  EXPECT_DOUBLE_EQ(romea_path_posture2d.curvature, ros_posture2d_msg.curvature);
  EXPECT_DOUBLE_EQ(romea_path_posture2d.dotCurvature, ros_posture2d_msg.dot_curvature);
}

//-----------------------------------------------------------------------------
TEST(TestPosture2dConvertion, fromRomeaToRosMsg)
{
  romea::PathPosture2D romea_path_posture2d;
  romea_path_posture2d.position.x() = 1;
  romea_path_posture2d.position.y() = 2;
  romea_path_posture2d.course = 3;
  romea_path_posture2d.curvature = 4;
  romea_path_posture2d.dotCurvature = 5;

  romea_path_msgs::msg::PathPosture2D ros_posture2d_msg;
  romea::to_ros_msg(romea_path_posture2d, ros_posture2d_msg);

  EXPECT_DOUBLE_EQ(romea_path_posture2d.position.x(), ros_posture2d_msg.x);
  EXPECT_DOUBLE_EQ(romea_path_posture2d.position.y(), ros_posture2d_msg.y);
  EXPECT_DOUBLE_EQ(romea_path_posture2d.course, ros_posture2d_msg.course);
  EXPECT_DOUBLE_EQ(romea_path_posture2d.curvature, ros_posture2d_msg.curvature);
  EXPECT_DOUBLE_EQ(romea_path_posture2d.dotCurvature, ros_posture2d_msg.dot_curvature);
}


//-----------------------------------------------------------------------------
int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
