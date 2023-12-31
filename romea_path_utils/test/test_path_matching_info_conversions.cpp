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

// std
#include <vector>

// gtest
#include "gtest/gtest.h"

// romea
#include "romea_path_utils/path_matching_info_conversions.hpp"


//-----------------------------------------------------------------------------
TEST(TestMatchingInfoConvertion, toRosMsgWithOneMatchedPoint)
{
  double path_length = 1;
  rclcpp::Time stamp(2, 3);

  romea_path_msgs::msg::PathMatchingInfo2D msg = romea::ros2::to_ros_msg(
    stamp, romea::core::PathMatchedPoint2D(), path_length, romea::core::Twist2D());

  // EXPECT_DOUBLE_EQ(msg.header.stamp.sec, stamp.seconds());
  // EXPECT_DOUBLE_EQ(msg.header.stamp.nanosec, stamp.nanoseconds());

  EXPECT_DOUBLE_EQ(
    msg.header.stamp.sec + msg.header.stamp.nanosec / 1000000000.,
    stamp.seconds());

  EXPECT_DOUBLE_EQ(msg.path_length, path_length);
  EXPECT_EQ(msg.matched_points.size(), 1u);
}

//-----------------------------------------------------------------------------
TEST(TestMatchingInfoConvertion, toRosMsgWithTwoMatchedPoints)
{
  double path_length = 1;
  size_t tracked_matched_point_index = 2;
  rclcpp::Time stamp(3, 4);

  romea_path_msgs::msg::PathMatchingInfo2D msg = romea::ros2::to_ros_msg(
    stamp, std::vector<romea::core::PathMatchedPoint2D>(2),
    tracked_matched_point_index, path_length, romea::core::Twist2D());

  // EXPECT_DOUBLE_EQ(msg.header.stamp.sec, stamp.seconds());
  // EXPECT_DOUBLE_EQ(msg.header.stamp.nanosec, stamp.nanoseconds());
  EXPECT_DOUBLE_EQ(
    msg.header.stamp.sec + msg.header.stamp.nanosec / 1000000000.,
    stamp.seconds());
  EXPECT_DOUBLE_EQ(msg.path_length, path_length);
  EXPECT_DOUBLE_EQ(msg.tracked_matched_point_index, tracked_matched_point_index);
  EXPECT_EQ(msg.matched_points.size(), 2u);
}

//-----------------------------------------------------------------------------
int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
