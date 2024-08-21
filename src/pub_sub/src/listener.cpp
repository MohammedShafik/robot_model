#include <ros/ros.h>
#include <std_msgs/String.h>
#include <pub_sub/Num.h>

// Callback function to handle received messages
//void chatterCallback(const std_msgs::String::ConstPtr& msg)
void chatterCallback(const pub_sub::Num::ConstPtr& msg)
{
  //ROS_INFO("Received: %s", msg->data.c_str());
  ROS_INFO("Received: %ld %s", msg->num, msg->name.c_str());
  //ROS_INFO("Received: %ld", msg->num);
}

int main(int argc, char** argv)
{
  // Initialize the ROS node
  ros::init(argc, argv, "listener");

  // Create a node handle
  ros::NodeHandle n;

  // Subscribe to the "chatter" topic
  ros::Subscriber sub = n.subscribe("chatter", 10, chatterCallback);

  // Spin to process callbacks
  ros::spin();

  return 0;
}
