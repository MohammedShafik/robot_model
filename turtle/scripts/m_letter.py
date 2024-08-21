#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist
import time

def draw_letter_m():
    pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
    rospy.init_node('draw_m', anonymous=True)
    rate = rospy.Rate(1)  # 1 Hz

    # Move forward
    move_forward = Twist()
    move_forward.linear.x = 3
    #pub.publish(move_forward)
    time.sleep(1)  # Adjust based on simulation time
    
    # Turn right
    turn_right = Twist()
    turn_right.angular.z = 1.5
    pub.publish(turn_right)
    time.sleep(2)  # Adjust based on simulation time

    # Move forward
    pub.publish(move_forward)
    time.sleep(2)  # Adjust based on simulation time

    # Turn left
    turn_left = Twist()
    turn_left.angular.z = -2.5
    pub.publish(turn_left)
    time.sleep(2)  # Adjust based on simulation time
    
    
    move_forward.linear.x = 2
    # Move forward
    pub.publish(move_forward)
    time.sleep(2)  # Adjust based on simulation time
    
    # Turn left
    turn_left = Twist()
    turn_left.angular.z = 2.3
    pub.publish(turn_left)
    time.sleep(2)  # Adjust based on simulation time
    
    # Move forward
    pub.publish(move_forward)
    time.sleep(2)  # Adjust based on simulation time
    
     # Turn left
    turn_left = Twist()
    turn_left.angular.z = -2.5
    pub.publish(turn_left)
    time.sleep(2)  # Adjust based on simulation time
    move_forward.linear.x = 3
    
    # Move forward
    pub.publish(move_forward)
    time.sleep(2)  # Adjust based on simulation time

    # Stop
    stop = Twist()
    pub.publish(stop)

if __name__ == '__main__':
    try:
        draw_letter_m()
    except rospy.ROSInterruptException:
        pass
