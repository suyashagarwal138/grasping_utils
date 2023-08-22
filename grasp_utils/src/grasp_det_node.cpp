#include <ros/ros.h>
#include "grasp_utils/GraspExecutor.hpp"
#include "grasp_utils/GraspDetector.hpp"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "grasp_det");

    ros::NodeHandle nodeHandle("grasp_detector");

    grasp_utils::GraspDetector graspDetector(nodeHandle);

    // define the publisher data member of the graspDetector object.
    // set it to advertise a message of type GraspArray.
    // GraspArray is simply an array of moveit_msgs::Grasp messages. 
    graspDetector.set_pub(nodeHandle.advertise<grasp_utils::GraspArray>("grasps", 1000));

    // Loop at 0.4 Hz
    ros::Rate loop_rate(0.4);
    
    // Set the RNG seed so that each message generated is unique
    srand(time(NULL));
    
    while (ros::ok())
    {
        // Initialise a GraspArray
        grasp_utils::GraspArray grasp_array;

        // generate 64 random grasp poses
        int no_of_grasps = 64;
    
        for(int i = 0; i < no_of_grasps; i++){

            // Make a Grasp that will get pushed onto the array
            moveit_msgs::Grasp grasp;

            // Randomise the position variables with values from 0.1 to 0.2
            float rm = RAND_MAX;

            float x = (rand()/rm) * 0.3 + 0.1;
            float y = (rand()/rm) * 0.0;
            float z = (rand()/rm) * 0.1 + 0.1;
            grasp.grasp_pose.pose.position.x = x;
            grasp.grasp_pose.pose.position.y = y;
            grasp.grasp_pose.pose.position.z = z;

            // Randomise the grasp score, also from 0.1 to 0.2
            grasp.grasp_quality = x;

            // The same can be done for the quaternion defining orientation
            
            // Set a unique identifier
            grasp.id = "This is grasp pose no. " + std::to_string(i);

            // Add this grasp to the array
            grasp_array.array.push_back(grasp);
        }

        // Publish the array of grasps onto the topic
        graspDetector.get_pub().publish(grasp_array);

        ros::spinOnce();
        loop_rate.sleep();
    }

    ros::spin();
    return 0;
}