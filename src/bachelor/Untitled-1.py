#!/usr/bin/env python
import rospy
from qt_gesture_controller.srv import gesture_play
from qt_nuitrack_app.msg import Gestures

def gesture_callback(msg):
    print('called')
    print(msg.gestures[0].name)
    if msg.gestures[0].name == "SWIPE RIGHT":
        #gesturePlay("QT/swipe_right",0)
        print("swipe right")
    elif msg.gestures[0].name == "SWIPE LEFT":
        #gesturePlay("QT/swipe_left",0)
        print("swipe left")

if __name__ == '__main__':
    rospy.init_node('my_tutorial_node')
    rospy.loginfo("my_tutorial_node started!")

    #gesturePlay = rospy.ServiceProxy('/qt_robot/gesture/play', gesture_play)
    # define ros subscriber
    rospy.Subscriber('/qt_nuitrack_app/gestures', Gestures, gesture_callback)
   
    try:
        rospy.spin()
    except KeyboardInterrupt:
        pass

    rospy.loginfo("finsihed!")




























#speechSay_pub = rospy.Publisher('/qt_robot/speech/say', String, queue_size=10)

#wtime_begin = rospy.get_time()
#while (speechSay_pub.get_num_connections() == 0 ):
    #rospy.loginfo("waiting for subscriber connections")
    #if rospy.get_time() - wtime_begin > 5.0:
        #rospy.logerr("Timeout while waiting for subscribers connection!")
        #sys.exit()
    #rospy.sleep(1)

#try:
    #speechSay_pub.publish("Bravo?")
#except rospy.ROSInterruptException:
    #pass



