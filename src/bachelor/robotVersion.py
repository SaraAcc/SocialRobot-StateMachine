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
evaluations = ['https://vu.fr/zXGa', 'https://vu.fr/XnRT', 'https://vu.fr/XLAq']

#For the keyboard or gestures implementation
gestures_bool = False
stateIndex = 0
state = ['Greetings', 'Storytelling', 'Evaluation', 'Goodbye']
nextGlobalState = ''

def gesture_callback(msg):
    global nextGlobalState
    global stateIndex
    nextGlobalState = ''

    print('call to gesture')
    print(msg.gestures[0].name)

    if state[stateIndex] == 'Greetings':
        if msg.gestures[0].name == "SWIPE UP": #Go to Storytelling
            nextGlobalState = 'nextContent'
            stateIndex += 1

    elif state[stateIndex] == 'Storytelling':
        if msg.gestures[0].name == "SWIPE RIGHT": #Go to Evaluation
            nextGlobalState = 'nextEvaluation'
            stateIndex += 1
        elif msg.gestures[0].name == "SWIPE LEFT": #Repeat the story
            nextGlobalState = 'repeatStory'
        elif msg.gestures[0].name == "SWIPE UP": #Goodbye
            nextGlobalState = 'nextGoodbye'
            stateIndex = 3

    elif state[stateIndex] == 'Evaluation':
        if msg.gestures[0].name == "SWIPE RIGHT": #Go to another story
            nextGlobalState = 'nextStory'
            stateIndex -= 1
        elif msg.gestures[0].name == "SWIPE UP": #Goodbye
            nextGlobalState = 'nextGoodbye'
            stateIndex = 3



#initiate node
rospy.init_node('smach_example_state_machine')
 
#Create subscriber for the gestures TODO !!!!!!!!!!!!!!!!!!!!
rospy.Subscriber('/qt_nuitrack_app/gestures', Gestures, gesture_callback)

#Create publisher for the speech
speechSay_pub = rospy.Publisher('/qt_robot/speech/say', String, queue_size=10)
wtime_begin = rospy.get_time()
while (speechSay_pub.get_num_connections() == 0 ):
    #rospy.loginfo("waiting for subscriber connections")
    if rospy.get_time() - wtime_begin > 5.0:
        rospy.logerr("Timeout while waiting for subscribers connection!")
        sys.exit()
    rospy.sleep(1)

#choose between gesture or keyboard navigation
print("Press ENTER to navigate using gestures\nPress SPACE to navigate using the keyboard")
def show(key):
    global gestures_bool
    if key == Key.enter: #use the gestures to navigate
        gestures_bool = True
        print("using gestures")
        return False
    if key == Key.space: #use the keyboard to navigate
        return False
with Listener(on_press = show) as ls:
    ls.join()


#define state Greetings
class Greetings(smach.State):

    def __init__(self):
        smach.State.__init__(self, outcomes=['nextContent'])

    def execute(self, userdata):
        
        #speech
        try:
            print("Hello! Thank you for attending this course. We are going to start soon !\n")
            #speechSay_pub.publish("Hello! Thank you for attending this course. We are going to start soon !") TODO
        except rospy.ROSInterruptException:
            pass


        if gestures_bool:           #Using Gestures
            print('Swipe UP to start the first course\n')
            while nextGlobalState == '':
                pass 
            if nextGlobalState != '':
                return nextGlobalState
        else:                       #Using keyboard
            self.count = False
            print("Press ENTER to start the course")
            def show(key):
                if key == Key.enter:
                    self.count = True
                    return False
            with Listener(on_press = show) as ls:
                ls.join()
            if self.count:
                return 'nextContent'
                


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


        if gestures_bool:           #Using gestures
            print('\n-----------------\nSwipe RIGHT to go to evaluation\nSwipe LEFT to repeat the story\nSwipe UP to say goodbye \n-----------------\n')
            nextGlobalState = ''
            while nextGlobalState == '': #waiting for the right gesture to be played
                pass 
            if nextGlobalState != '':
                return nextGlobalState
        else:                       #Using keyboard
            self.repeatStory = False
            self.evaluation = False
            self.goodbye = False
            print('\n-----------------\nPress ENTER to go to evaluation\nPress SPACE to repeat the story\nPress ESC to say goodbye \n-----------------\n')
            def show(key):
                if key == Key.esc: #go to goodbye
                    self.goodbye = True
                    return False
                if key == Key.space: #repeat the same story
                    self.repeatStory = True
                    return False
                if key == Key.enter: #go to evaluation
                    self.evaluation = True
                    return False
            with Listener(on_press = show) as ls:
                ls.join()

            if self.goodbye:
                return 'nextGoodbye'
            if self.repeatStory:
                return 'repeatStory'
            if self.evaluation:
                return 'nextEvaluation'



#define state Evaluation
class Evaluation(smach.State):

    def __init__(self):
        smach.State.__init__(self, outcomes=['nextStory', 'nextGoodbye'])

    def execute(self, userdata):
        global storyIndex
        global speechSay_pub
        global gestures_bool
        global nextGlobalState

        #open the evaluation in a browser
        webbrowser.open(evaluations[storyIndex])
        print('\nThank you for completing the evaluation !')

        #Go to goodbye if no stories left
        if storyIndex == len(evaluations)-1:
            #speechSay_pub.publish("You have finished all the stories. Congratulations !") TODO
            print('\nYou have finished all the stories. Congratulations !\n')
            return 'nextGoodbye'


        if gestures_bool:          #Using Gestures
            print('\nDo you want to hear another story ?\n \n------------\nSwipe RIGHT to hear another story\nSwipe UP to say goodbye\n------------\n')
            nextGlobalState = ''
            while nextGlobalState == '':
                pass 
            if nextGlobalState != '':
                return nextGlobalState
        else :                     #Using keyboard
            self.nextStory = False
            self.goodbye = False
            print('\nDo you want to hear another story ?\n \n------------\nPress ENTER to hear another story\nPress ESC to say goodbye\n------------\n')
            def show(key):
                if key == Key.enter: #hear another story
                    global storyIndex
                    self.nextStory = True
                    storyIndex += 1
                    return False

                if key == Key.esc: #go to goodbye
                    self.goodbye = True
                    return False

            with Listener(on_press = show) as ls:
                ls.join()

            if self.nextStory:
                return 'nextStory'
            if self.goodbye:
                return 'nextGoodbye'


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