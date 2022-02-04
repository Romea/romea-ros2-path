#ifndef _romea_PathMatchingInfoConversions_hpp_
#define _romea_PathMatchingInfoConversions_hpp

//romea
#include <romea_core_path/PathMatchedPoint2D.hpp>
#include <romea_path_msgs/msg/path_matching_info2_d.hpp>
#include <romea_core_common/geometry/Twist2D.hpp>
#include <romea_core_common/time/Time.hpp>

//ros
#include <rclcpp/time.hpp>

namespace romea {


romea_path_msgs::msg::PathMatchingInfo2D to_ros_msg(const Duration & duration,
                                                    const PathMatchedPoint2D &matched_point,
                                                    const double &path_length,
                                                    const Twist2D & twist);

romea_path_msgs::msg::PathMatchingInfo2D to_ros_msg(const rclcpp::Time & stamp,
                                                    const PathMatchedPoint2D &matched_point,
                                                    const double &path_length,
                                                    const Twist2D & twist);

romea_path_msgs::msg::PathMatchingInfo2D to_ros_msg(const Duration & duration,
                                                    const std::vector<PathMatchedPoint2D> &matched_points,
                                                    const size_t & tracked_matched_point_index,
                                                    const double &path_length,
                                                    const Twist2D & twist);

romea_path_msgs::msg::PathMatchingInfo2D to_ros_msg(const rclcpp::Time & stamp,
                                                    const std::vector<PathMatchedPoint2D> &matched_points,
                                                    const size_t &tracked_matched_point_index,
                                                    const double & path_length,
                                                    const Twist2D & twist);
}

#endif
