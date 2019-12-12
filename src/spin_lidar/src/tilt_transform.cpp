#include <ros/ros.h>
#include <tf/transform_listener.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "ouster_tf_listener");
  ros::NodeHandle node;
  ros::Publisher final_transformed_pc = 
    node.advertise<sensor_msgs::PointCLoud2>("transformed_point_cloud", 1);

  tf::TransformListener listener;
  while (node.ok()){
    tf::StampedTransform transform;
    try{
      listener.lookupTransform("/ouster", "/laser",ros::Time(0), transform);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }
    
    final_transformed_pc.publish(vel_msg);

    rate.sleep();
  }
  return 0;
