#include<ros/ros.h>
#include<sensor_msgs/LaserScan.h>

//This node removes points from the Hokuyo's LaserScan that are the robot
//The removal of the robot also comes from adjusting the angle viewed by the Hokuyo in the launch file

using namespace std;

//global variable equal to infinity
float inf = numeric_limits<float>::infinity();
ros::Publisher pub;

//removes points that correspond to robot by setting them equal to infinity
void filter(const sensor_msgs::LaserScan msg)
{
   pub.publish(msg);
}

//main
int main(int argc, char **argv)
{
   //initialize
   ros::init(argc, argv, "hokuyo_robot_filter");
   ros::NodeHandle nh;

   //subscribe to LaserScan messages pulished by Hokuyo
   ros::Subscriber sub = nh.subscribe<sensor_msgs::LaserScan>("/scan", 1, filter);

   //publisher for filteres scans
   pub = nh.advertise<sensor_msgs::LaserScan>("hokuyo_filtered", 1);

   //wait for new scans
   ros::spin();

}
