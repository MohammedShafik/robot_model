#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist
import time

def draw_letter_m():
    pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
    rospy.init_node('draw_m', anonymous=True)
    rate = rospy.Rate(1)  # 1 Hz
    
    move = Twist()
    move.linear.x = 0
    move.linear.y = 0
    move.linear.z = 0
    time.sleep(1)  
    
    move.angular.z = 1.5
    pub.publish(move)
    time.sleep(2)  
    
    move.linear.x = 3
    move.angular.z = 0
    pub.publish(move)
    time.sleep(2)
    
    move.linear.x = 0
    move.angular.z = -2.5
    pub.publish(move)
    time.sleep(2)
    
    move.linear.x = 2
    move.angular.z = 0
    pub.publish(move)
    time.sleep(2)
    
    move.linear.x = 0
    move.angular.z = 2.3
    pub.publish(move)
    time.sleep(2)  
    
    move.linear.x = 2
    move.angular.z = 0
    pub.publish(move)
    time.sleep(2)
    
    move.linear.x = 0
    move.angular.z = -2.5
    pub.publish(move)
    time.sleep(2)  
    
    move.linear.x = 3
    move.angular.z = 0
    pub.publish(move)
    time.sleep(2)

    # Stop
    stop = Twist()
    pub.publish(stop)

if __name__ == '__main__':
    try:
        draw_letter_m()
    except rospy.ROSInterruptException:
        pass
