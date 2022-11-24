#!/usr/bin/env python

from pynput.keyboard import Key, Listener
import sys
import smach
import rospy
import webbrowser
from std_msgs.msg import String
from qt_nuitrack_app.msg import Gestures

#For the evaluations
storyIndex = 0
evaluations = ['https://vu.fr/zXGa', 'https://vu.fr/XnRT', 'https://vu.fr/XLAq']

#For the gestures
stateIndex = 0
state = ['Greetings', 'Storytelling', 'Evaluation', 'Goodbye']


nextGlobalState = ''

def show(key):
    print('A key press has been detected')
    
    global nextGlobalState
    global stateIndex
    global state
    global storyIndex

    print(state[stateIndex])

    if state[stateIndex] == 'Greetings':
        if key == Key.enter: #Go to Storytelling
            nextGlobalState = 'nextContent'
            stateIndex = 1

    elif state[stateIndex] == 'Storytelling':
        if key== Key.enter: #Go to Evaluation
            nextGlobalState = 'nextEvaluation'
            stateIndex = 2
        elif key == Key.space: #Repeat the story
            nextGlobalState = 'repeatStory'
        elif key == Key.esc: #Goodbye
            nextGlobalState = 'nextGoodbye'
            stateIndex = 3

    elif state[stateIndex] == 'Evaluation':
        if key == Key.enter: #Go to another story
            nextGlobalState = 'nextStory'
            storyIndex += 1
            stateIndex = 1
        elif key == Key.esc: #Goodbye
            nextGlobalState = 'nextGoodbye'
            stateIndex = 3

    print(nextGlobalState)

#For the keyboard
ls = Listener(on_press = show)
ls.start()

def gesture_callback(msg):
    global nextGlobalState
    global stateIndex
    global state
    global storyIndex

    #prints to suppress TODO
    print('call to gesture')
    print(msg.gestures[0].name)

    if state[stateIndex] == 'Greetings':
        if msg.gestures[0].name == "SWIPE UP": #Go to Storytelling
            nextGlobalState = 'nextContent'
            stateIndex = 1

    elif state[stateIndex] == 'Storytelling':
        if msg.gestures[0].name == "SWIPE RIGHT": #Go to Evaluation
            nextGlobalState = 'nextEvaluation'
            stateIndex = 2
        elif msg.gestures[0].name == "SWIPE LEFT": #Repeat the story
            nextGlobalState = 'repeatStory'
        elif msg.gestures[0].name == "SWIPE UP": #Goodbye
            nextGlobalState = 'nextGoodbye'
            stateIndex = 3

    elif state[stateIndex] == 'Evaluation':
        if msg.gestures[0].name == "SWIPE RIGHT": #Go to another story
            nextGlobalState = 'nextStory'
            storyIndex += 1
            stateIndex = 1
        elif msg.gestures[0].name == "SWIPE UP": #Goodbye
            nextGlobalState = 'nextGoodbye'
            stateIndex = 3



#initiate node
rospy.init_node('smach_example_state_machine')

#Create subscriber for the gestures
rospy.Subscriber('/qt_nuitrack_app/gestures', Gestures, gesture_callback)

#Create publisher for the speeches
speechSay_pub = rospy.Publisher('/qt_robot/speech/say', String, queue_size=10)
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
        try:
            print("Hello! Thank you for attending this course. We are going to start soon !\n")
            #speechSay_pub.publish("Hello! Thank you for attending this course. We are going to start soon !") TODO
        except rospy.ROSInterruptException:
            pass

        print('Swipe UP or Press ENTER to start the course\n')
        global nextGlobalState

        nextGlobalState = ''
        while nextGlobalState == '':
            pass 
        return nextGlobalState


#define state Storytelling
class Storytelling(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['nextGoodbye', 'nextEvaluation', 'repeatStory'])


    def execute(self, userdata):
        
        #Read the story
        global storyIndex
        global speechSay_pub
        global nextGlobalState

        with open('story{}'.format(storyIndex+1), 'r') as f:
            content = f.read()
            print(content)
            #speechSay_pub.publish(content) TODO

        print('\n-----------------\nSwipe RIGHT or press ENTER to go to evaluation\nSwipe LEFT or press SPACE to repeat the story\nSwipe UP or press ESC to say goodbye \n-----------------\n')

        nextGlobalState = ''
        while nextGlobalState == '':
            pass 
        return nextGlobalState

        

#define state Evaluation
class Evaluation(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['nextStory', 'nextGoodbye'])

    def execute(self, userdata):
        global storyIndex
        global speechSay_pub
        global evaluations

        #open the evaluation in a browser
        #webbrowser.open(evaluations[storyIndex])
        print('\nThank you for completing the evaluation !')

        #Go to goodbye if no stories left
        if storyIndex == len(evaluations)-1:
            #speechSay_pub.publish("You have finished all the stories. Congratulations !") TODO
            print('\nYou have finished all the stories. Congratulations !\n')
            return 'nextGoodbye'

        print('\nDo you want to hear another story ?\n \n------------\nSwipe RIGHT or press ENTER to hear another story\nSwipe UP or press ESC to say goodbye\n------------\n')
        
        nextGlobalState = ''
        while nextGlobalState == '':
            pass 
        return nextGlobalState

#define state Goodbye
class Goodbye(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['finishState'])

    def execute(self, userdata):
        global speechSay_pub
        #speechSay_pub.publish("Thank you for your attention. See you next time !") TODO
        print('Thank you for your attention. See you next time!\n\n')
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
            'repeatStory':'STORYTELLING',
            'nextEvaluation': 'EVALUATION',
            'nextGoodbye':'GOODBYE'
        })
        smach.StateMachine.add('EVALUATION', Evaluation(), transitions = {
            'nextStory': 'STORYTELLING',
            'nextGoodbye': 'GOODBYE'

        })
        smach.StateMachine.add('GOODBYE', Goodbye(), transitions={
            'finishState': 'outcome4'
        })

    #Execute smach plan
    outcome = sm.execute()
    
if __name__ == '__main__':
    main()