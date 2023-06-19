// Copyright 2022 INRAE, French National Research Institute for Agriculture, Food and Environment
// Add license

#include "romea_path_utils/path_frenet_pose2d_conversions.hpp"

namespace romea
{

//-----------------------------------------------------------------------------
void to_ros_msg(
  const PathFrenetPose2D & romea_frenet_pose2d,
  romea_path_msgs::msg::PathFrenetPose2D & ros_frenet_pose2d_msg)
{
  ros_frenet_pose2d_msg.curvilinear_abscissa = romea_frenet_pose2d.curvilinearAbscissa;
  ros_frenet_pose2d_msg.lateral_deviation = romea_frenet_pose2d.lateralDeviation;
  ros_frenet_pose2d_msg.course_deviation = romea_frenet_pose2d.courseDeviation;

  for (size_t n = 0; n < 9; ++n) {
    ros_frenet_pose2d_msg.covariance[n] = romea_frenet_pose2d.covariance(n);
  }
}

//-----------------------------------------------------------------------------
void to_romea(
  const romea_path_msgs::msg::PathFrenetPose2D & frenet_pose_msg,
  PathFrenetPose2D & romea_frenet_pose)
{
  romea_frenet_pose.curvilinearAbscissa = frenet_pose_msg.curvilinear_abscissa;
  romea_frenet_pose.lateralDeviation = frenet_pose_msg.lateral_deviation;
  romea_frenet_pose.courseDeviation = frenet_pose_msg.course_deviation;
  romea_frenet_pose.covariance = Eigen::Matrix3d(frenet_pose_msg.covariance.data());
}

//-----------------------------------------------------------------------------
PathFrenetPose2D to_romea(const romea_path_msgs::msg::PathFrenetPose2D & frenet_pose_msg)
{
  PathFrenetPose2D romea_frenet_pose;
  to_romea(frenet_pose_msg, romea_frenet_pose);
  return romea_frenet_pose;
}

}  // namespace romea
