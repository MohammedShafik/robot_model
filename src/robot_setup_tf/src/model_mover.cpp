#include <ros/ros.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg){
 tf2_ros::TransformBroadcaster br;
 geometry_msgs::TransformStamped transformStamped;
 
 // set the frames IDs
 transformStamped.header.frame_id = "odom";
 transformStamped.child_frame_id = "base_link";
 
 //process the recieved odometry message
  transformStamped.transform.translation.x = msg->pose.pose.position.x;
  transformStamped.transform.translation.y = msg->pose.pose.position.y;
  transformStamped.transform.translation.z = msg->pose.pose.position.z;
  transformStamped.transform.rotation = msg->pose.pose.orientation;
  
  transformStamped.header.stamp = ros::Time::now();
  
  br.sendTransform(transformStamped);
  }

int main(int argc, char** argv){
  ros::init(argc, argv, "odometry_subscriber");
  ros::NodeHandle n;
  
  tf2_ros::TransformBroadcaster br;

  //we'ull transform a point once every second
  ros::Subscriber odom_sub = n.subscribe("odom",10,odomCallback);
  ros::spin();
  
  return 0;

}
