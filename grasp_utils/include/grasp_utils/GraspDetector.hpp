#pragma once

// ROS
#include <ros/ros.h>
#include <sensor_msgs/Temperature.h>
#include <std_srvs/Trigger.h>
#include <std_msgs/String.h>

#include <vector>
#include <moveit_msgs/Grasp.h>

#include <grasp_utils/GraspArray.h>


namespace grasp_utils
{

  // Class to handle the node that will subscribe to /scan for point cloud data
  // Generates 64 candidates grasps and publishes them on the topic /grasps
  class GraspDetector
  {
  public:
    /*!
     * Constructor.
     * @param nodeHandle the ROS node handle.
     */
    
    GraspDetector(ros::NodeHandle &nodeHandle) : nodeHandle_(nodeHandle){};

    void set_pub(ros::Publisher x){
      publisher_ = x;
    };

    ros::Publisher get_pub(){
      return publisher_;
    }

  private:
    ros::NodeHandle &nodeHandle_;
    ros::Publisher publisher_;
    std::string subscriberTopic_;

  };
} /* namespace */
