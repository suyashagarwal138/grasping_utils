# grasp_utils
New framework for grasping pipeline.

There are two nodes - a grasp detector and a grasp executor. They communicate via a topic /grasps.
The messages sent over this topic are of type GraspArray. These are simply arrays of moveit_msgs::Grasp messages.

Currently, the grasp positions sent are randomly generated so that the basic pipeline can be established. 
This can be replaced in due course. 

The executor node also implements IK checking - the highest quality grasp that passes the check is the one that gets executed.
