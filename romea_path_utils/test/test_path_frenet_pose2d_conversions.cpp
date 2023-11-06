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
#include "romea_path_utils/path_frenet_pose2d_conversions.hpp"

//-----------------------------------------------------------------------------
TEST(TestFrenetPoseConvertion, fromRosMsgToRomea)
{
  romea_path_msgs::msg::PathFrenetPose2D ros_frenet_pose2d_msg;
  ros_frenet_pose2d_msg.curvilinear_abscissa = 1;
  ros_frenet_pose2d_msg.lateral_deviation = 2;
  ros_frenet_pose2d_msg.course_deviation = 3;
  for (size_t n = 0; n < 9; ++n) {
    ros_frenet_pose2d_msg.covariance[n] = n;
  }

  romea::PathFrenetPose2D romea_frenet_pose2d = romea::to_romea(ros_frenet_pose2d_msg);

  EXPECT_DOUBLE_EQ(
    romea_frenet_pose2d.curvilinearAbscissa,
    ros_frenet_pose2d_msg.curvilinear_abscissa);
  EXPECT_DOUBLE_EQ(
    romea_frenet_pose2d.lateralDeviation,
    ros_frenet_pose2d_msg.lateral_deviation);
  EXPECT_DOUBLE_EQ(
    romea_frenet_pose2d.courseDeviation,
    ros_frenet_pose2d_msg.course_deviation);
  for (size_t n = 0; n < 9; ++n) {
    EXPECT_DOUBLE_EQ(
      romea_frenet_pose2d.covariance(n),
      ros_frenet_pose2d_msg.covariance[n]);
  }
}

//-----------------------------------------------------------------------------
TEST(TestFrenetPoseConvertion, fromRomeaToRosMsg)
{
  romea::PathFrenetPose2D romea_frenet_pose2d;
  romea_frenet_pose2d.curvilinearAbscissa = 1;
  romea_frenet_pose2d.lateralDeviation = 2;
  romea_frenet_pose2d.courseDeviation = 3;
  for (size_t n = 0; n < 9; ++n) {
    romea_frenet_pose2d.covariance(n) = n;
  }

  romea_path_msgs::msg::PathFrenetPose2D ros_frenet_pose2d_msg;
  romea::to_ros_msg(romea_frenet_pose2d, ros_frenet_pose2d_msg);

  EXPECT_DOUBLE_EQ(
    romea_frenet_pose2d.curvilinearAbscissa,
    ros_frenet_pose2d_msg.curvilinear_abscissa);
  EXPECT_DOUBLE_EQ(
    romea_frenet_pose2d.lateralDeviation,
    ros_frenet_pose2d_msg.lateral_deviation);
  EXPECT_DOUBLE_EQ(
    romea_frenet_pose2d.courseDeviation,
    ros_frenet_pose2d_msg.course_deviation);
  for (size_t n = 0; n < 9; ++n) {
    EXPECT_DOUBLE_EQ(
      romea_frenet_pose2d.covariance(n),
      ros_frenet_pose2d_msg.covariance[n]);
  }
}


//-----------------------------------------------------------------------------
int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
