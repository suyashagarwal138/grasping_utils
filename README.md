# grasp_utils
New framework for grasping pipeline.

There are two nodes - a grasp detector and a grasp executor. They communicate via a topic /grasps.
The messages sent over this topic are of type GraspArray. These are simply arrays of moveit_msgs::Grasp messages.

Currently, the grasp positions sent are randomly generated so that the basic pipeline can be established. 
This can be replaced in due course. 

The executor node also implements IK checking - the highest quality grasp that passes the check is the one that gets executed.

Changes to codebase for K1 arm are currently on the k1 branch only.

For use with the Panda arm:
Must first run  roslaunch panda_moveit_config demo.launch
panda_moveit_config is provided by MoveIt!

For use with the K1 arm:
Must first run roslaunch k1_moveit_config demo.launch
k1_moveit_config is a custom config package.
