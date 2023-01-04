#!/usr/bin/env python

from pynput.keyboard import Key, Listener
import sys
import smach
import rospy
import json
from std_msgs.msg import String
from qt_nuitrack_app.msg import Gestures
import translators as ts
from qt_robot_interface.srv import *

#For the evaluations
storyIndex = 0
nbStories = 3

#For the gestures
stateIndex = 0
state = ['Greetings', 'Storytelling', 'Evaluation', 'Goodbye']

chosen_language = -1
while chosen_language != 0 and chosen_language != 1 and chosen_language != 2:
    print("\nPlease choose your preferred language:\nType 0 for english\nType 1 for german\nType 2 for french\n")
    chosen_language = int(input())

nextGlobalState = ''
name = 'X'

def show(key):
    
    global nextGlobalState
    global stateIndex
    global state
    global storyIndex


    if state[stateIndex] == 'Greetings':
        if key == Key.shift: #Go to Storytelling
            nextGlobalState = 'nextContent'
            stateIndex = 1

    elif state[stateIndex] == 'Storytelling':
        if key== Key.shift: #Go to Evaluation
            nextGlobalState = 'nextEvaluation'
            stateIndex = 2
        elif key == Key.alt: #Repeat the story
            nextGlobalState = 'repeatStory'
        elif key == Key.esc: #Goodbye
            nextGlobalState = 'nextGoodbye'
            stateIndex = 3

    elif state[stateIndex] == 'Evaluation':
        if key == Key.shift: #Go to another story
            nextGlobalState = 'nextStory'
            storyIndex += 1
            stateIndex = 1
        elif key == Key.esc: #Goodbye
            nextGlobalState = 'nextGoodbye'
            stateIndex = 3
    

#For the keyboard
ls = Listener(on_press = show)
ls.start()

def gesture_callback(msg):
    global nextGlobalState
    global stateIndex
    global state
    global storyIndex

    #prints for DEBUGGING
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

#Create service to change the language
speechConfig = rospy.ServiceProxy('/qt_robot/speech/config', speech_config)
rospy.wait_for_service('/qt_robot/speech/config')

if chosen_language == 1:
    language = 'de'
    status = speechConfig("de-DE",0,100)
elif chosen_language == 2:
    language = 'fr'
    status = speechConfig("fr-FR",0,100)
elif chosen_language == 0: 
    language = 'en'
    status = speechConfig("en-US",0,100)
    

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


def translation(message, to_Say):
    if language  != 'en':
        content = ts.google(message, from_language='en', to_language=language) 
        print(content, "\n")
        if to_Say :
           speechSay_pub.publish(content)
    else:
        print(message, "\n")
        if to_Say: 
            speechSay_pub.publish(message)

#define state Greetings
class Greetings(smach.State):

    def __init__(self):
        smach.State.__init__(self, outcomes=['nextContent'])

    def execute(self, userdata):
        global name
        first_question = "Please write your name here :"
        translation(first_question, False)
        name = input()
        try:
            greetings = "Hello {} ! My name is Q T Robot et we are going to learn new things today. Follow the instructions written in the screen !".format(name)
            translation(greetings, True)
        except rospy.ROSInterruptException:
            pass

        instruction = 'Swipe UP or Press SHIFT to start the course'
        translation(instruction, False)

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
            translation(content, True)

        print('\n-----------------\n')
        translation('Swipe RIGHT or press SHIFT to go to evaluation', False)
        translation('Swipe LEFT or press ALT to repeat the story', False)
        translation('Swipe UP or press ESC to say goodbye', False)
        print('-----------------\n')
        
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
        global nextGlobalState


        questions = open("questions{}".format(storyIndex+1)).read().splitlines()

        faq = {}
        for question in questions:
            qst = translation(question, False)
            response = input()
            faq[question] = response

        with open("responses{}.json".format(storyIndex+1), "w") as write_file:
            json.dump(faq, write_file, indent="")

        translation('Thank you for completing the evaluation !', True)

        #Go to goodbye if no stories left
        if storyIndex == nbStories - 1:
            translation('You have finished all the stories. Congratulations !', True)
            return 'nextGoodbye'

        print('\n-----------------\n')
        translation('Do you want to hear another story ?', True)
        translation('Swipe RIGHT or press SHIFT to hear another story', False)
        translation('Swipe UP or press ESC to say goodbye', False)
        print('-----------------\n')
        
        nextGlobalState = ''
        while nextGlobalState == '':
            pass 
        return nextGlobalState

#define state Goodbye
class Goodbye(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['finishState'])

    def execute(self, userdata):
        global name
        global speechSay_pub
        translation('Thank you for your attention {}. See you next time!'.format(name), True)
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