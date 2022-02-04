#ifndef _romea_PathPosture2DConversions_hpp_
#define _romea_PathPosture2DConversions_hpp_

//romea
#include <romea_core_path/PathPosture2D.hpp>
#include <romea_path_msgs/msg/path_posture2_d.hpp>

namespace romea {

void to_ros_msg(const PathPosture2D & romea_path_posture2d,
                romea_path_msgs::msg::PathPosture2D & ros_path_posture2d_msg);

void to_romea(const romea_path_msgs::msg::PathPosture2D &posture_msg,
              PathPosture2D & romea_path_posture);

PathPosture2D to_romea(const romea_path_msgs::msg::PathPosture2D &posture_msg);

}

#endif
