#include <ros/ros.h>
#include <std_msgs/String.h>
#include <pub_sub/Num.h>
#include <sstream>

int main(int argc, char** argv)
{
  // Initialize the ROS node
  ros::init(argc, argv, "talker");

  // Create a node handle
  ros::NodeHandle n;

  // Create a publisher on the "chatter" topic
  //ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 10);
  ros::Publisher chatter_pub = n.advertise<pub_sub::Num>("chatter", 10);

  // Set the loop rate (in Hz)
  ros::Rate loop_rate(1);  // 1 Hz

  while (ros::ok())
  {
  
    pub_sub::Num msg;
    // Create a string message
    //std_msgs::String msg;
   // msg.data = "Hello, World!";
    msg.num = 10;
    msg.name = "Hello";
    
    ROS_INFO("Published: %ld %s", msg.num, msg.name.c_str());

    // Publish the message
    chatter_pub.publish(msg);

    // Log the published message
    //ROS_INFO("Published: %s", msg.data.c_str());

    // Spin once to process callbacks
    ros::spinOnce();

    // Sleep for the remaining time to achieve the desired loop rate
    loop_rate.sleep();
  }

  return 0;
}
