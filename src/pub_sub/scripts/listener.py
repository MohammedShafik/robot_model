#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from pub_sub.msg import Num

def callback(data):
    #rospy.loginfo(rospy.get_caller_id() + 'I heard %s', data.data)
    rospy.loginfo(rospy.get_caller_id() + 'I heard %ld', data.num)

def listener():

    rospy.init_node('listener', anonymous=True)

    #rospy.Subscriber('chatter', String, callback)
    rospy.Subscriber('chatter', Num, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
