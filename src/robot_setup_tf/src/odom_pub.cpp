#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <tf/tf.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "odometry_publisher");
  ros::NodeHandle n;

  // Create a publisher object
  ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 10);

  // Define the rate at which to publish messages (10 Hz)
  ros::Rate loop_rate(10);

  while (ros::ok()) {
    // Create a new Odometry message
    nav_msgs::Odometry odom_msg;

    // Set the header (frame id and timestamp)
    odom_msg.header.frame_id = "odom";
    odom_msg.child_frame_id = "base_link";
    odom_msg.header.stamp = ros::Time::now();

    // Set the position (example values, you can modify these)
    odom_msg.pose.pose.position.x = 2.0;
    odom_msg.pose.pose.position.y = 2.5;
    odom_msg.pose.pose.position.z = 0.0;

    // Set the orientation (example quaternion, you can modify this)
    odom_msg.pose.pose.orientation = tf::createQuaternionMsgFromYaw(1.57);

    // Set the velocity (example values, you can modify these)
    odom_msg.twist.twist.linear.x = 1.5;
    odom_msg.twist.twist.linear.y = 0.0;
    odom_msg.twist.twist.linear.z = 0.0;
    odom_msg.twist.twist.angular.z = 0.1;

    // Publish the odometry message
    odom_pub.publish(odom_msg);

    // Sleep for the remaining time until we hit our 10 Hz rate
    loop_rate.sleep();
  }

  return 0;
}

