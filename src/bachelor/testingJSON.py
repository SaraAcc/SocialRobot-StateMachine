#!/usr/bin/env python

import json
import translators as ts
#from translate import Translator

# what I'm thinking about
# make the robot say the story
# choose to go to evaluation or not
# if goes to evaluation, displays all the questions in the form
#   1) what is the name of the main character ?
#   2) what is his age ?
#   3) what do you think about this ?
# then all the answers will be written in a particular file
# Hence we can access all the answers to a particular story in one file


#dump() = writes data to files
#data = "hello"


# WE WILL HAVE: 
# a json file with the story in it
# a json file with the questions and answers in it

#creates file called data_file with data in it
#with open("data_file.json", "a") as write_file:
 #   print("Type your answer : ")
  #  data = str(input())
   # json.dump(data, write_file)




questions = open("questions").read().splitlines()
nbQuestions = len(questions)

faq = {}
for question in questions:
    print(question)
    response = input()
    faq[question] = response

with open("responses.json", "w") as write_file:
    json.dump(faq, write_file, indent="")

