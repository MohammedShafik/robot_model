#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from pub_sub.msg import Num

def talker():
    #pub = rospy.Publisher('chatter', String, queue_size=10)
    pub = rospy.Publisher('chatter', Num, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
#        hello_str = "hello world %s" % rospy.get_time()
        hello_str = Num()
        hello_str.num = 5
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
