#!/usr/bin/env python

from pynput.keyboard import Key, Listener
import sys
import smach
import rospy
import webbrowser
from std_msgs.msg import String
from qt_nuitrack_app.msg import Gestures
from qt_gesture_controller.srv import gesture_play


#For the evaluations
storyIndex = 0
nbHistoires = 3

#For the keyboard or gestures implementation
stateIndex = 0
state = ['Greetings', 'Storytelling', 'Goodbye']
nextGlobalState = ''

def gesture_callback(msg):
    global nextGlobalState
    global stateIndex
    global storyIndex
    nextGlobalState = ''

    print('call to gesture')
    print(msg.gestures[0].name)

    if state[stateIndex] == 'Greetings':
        if msg.gestures[0].name == "SWIPE UP": #Go to Storytelling
            nextGlobalState = 'nextContent'
            stateIndex = 1

    elif state[stateIndex] == 'Storytelling':
        if msg.gestures[0].name == "SWIPE RIGHT": #Continue the story
            nextGlobalState = 'storytelling'
            storyIndex += 1

        elif msg.gestures[0].name == "SWIPE LEFT": #Repeat the story
            nextGlobalState = 'storytelling'

        elif msg.gestures[0].name == "SWIPE UP": #Goodbye
            nextGlobalState = 'nextGoodbye'
            stateIndex = 2



#initiate node
rospy.init_node('smach_example_state_machine')

#rospy.Publisher('/qt_robot/speech/config', 'fr-FR', 0, 0)

#Create subscriber for the gestures
rospy.Subscriber('/qt_nuitrack_app/gestures', Gestures, gesture_callback)

#Create publisher for the speech
speechSay_pub = rospy.Publisher('/qt_robot/behavior/talkText', String, queue_size=10)
wtime_begin = rospy.get_time()
while (speechSay_pub.get_num_connections() == 0 ):
    #rospy.loginfo("waiting for subscriber connections")
    if rospy.get_time() - wtime_begin > 5.0:
        rospy.logerr("Timeout while waiting for subscribers connection!")
        sys.exit()
    rospy.sleep(1)



#define state Greetings
class Greetings(smach.State):

    def __init__(self):
        smach.State.__init__(self, outcomes=['nextContent'])

    def execute(self, userdata):
        
        #speech
        try:
            speechSay_pub.publish("Bonjour ! Je m'appelle Q T et je vais vous raconter des histoires aujourd'hui !")
            #print("Hello! Thank you for attending this course. We are going to start soon !\n")
            #speechSay_pub.publish("Hello! Thank you for attending this course. We are going to start soon !") TODO
        except rospy.ROSInterruptException:
            pass
        #Using Gestures
        #print('Swipe UP to start the first course\n')
        print("Lève ta main pour commencer une histoire")
        while nextGlobalState == '':
            pass 

        return nextGlobalState
                


#define state Storytelling
class Storytelling(smach.State):

    def __init__(self):
        smach.State.__init__(self, outcomes=['nextGoodbye','storytelling'])


    def execute(self, userdata):
        
        #Read the story
        global storyIndex
        global speechSay_pub
        global nextGlobalState
        global nbHistoires

        if storyIndex == nbHistoires:
            #speechSay_pub.publish("You have finished all the stories. Congratulations !") TODO
            #print('\nYou have finished all the stories. Congratulations !\n')
            #speechSay_pub.publish("Et voilà ! C'est la fin de cette histoire !")
            return 'nextGoodbye'
        else:
            with open('story{}'.format(storyIndex+1), 'r') as f:
                content = f.read()
                print(content)
                speechSay_pub.publish(content) 

        print("\n-----------------\nBalaie ta main vers la gauche pour recommencer cette partie de l'histoire\nBalaie ta main vers la droite pour continuer l'histoire\nLève ta main vers le haut pour me dire au revoir\n-----------------\n")
        nextGlobalState = ''
        #Go to goodbye if no stories left
        
        while nextGlobalState == '': #waiting for the right gesture to be played
            pass 
        return nextGlobalState




#define state Goodbye
class Goodbye(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['finishState'])

    def execute(self, userdata):
        global speechSay_pub
        #speechSay_pub.publish("Thank you for your attention. See you next time !") TODO
        #print('Thank you for your attention. See you next time!\n\n')
        speechSay_pub.publish("Merci pour votre attention et au revoir !")
        return 'finishState'
        
        


def main():
    

    #create a smach state machine
    sm = smach.StateMachine(outcomes=['outcome4'])
    
    #open the container
    with sm:
        #Add states to the container
        smach.StateMachine.add('GREETINGS', Greetings(), transitions={
            'nextContent':'STORYTELLING'
        })
        smach.StateMachine.add('STORYTELLING', Storytelling(), transitions={
            'storytelling':'STORYTELLING',
            'nextGoodbye':'GOODBYE'
        })
        smach.StateMachine.add('GOODBYE', Goodbye(), transitions={
            'finishState': 'outcome4'
        })

    #Execute smach plan
    outcome = sm.execute()
    

if __name__ == '__main__':
    main()