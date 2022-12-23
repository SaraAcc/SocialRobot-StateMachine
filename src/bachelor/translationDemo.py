
#!/usr/bin/env python

import json
import translators as ts


chosen_language = -1
while chosen_language != 0 and chosen_language != 1 and chosen_language != 2:
    print("Please choose your preferred language:\nType 0 for english\nType 1 for german\nType 2 for french")
    chosen_language = int(input())

if chosen_language == 0:
    language = 'en'
elif chosen_language == 1:
    language = 'de'
else: 
    language = 'fr'

with open('story1', 'r') as f:
    content = f.read()
    if language != 'fr':
        s = ts.google(content, from_language='fr', to_language=language)
    if(language != 'fr'):
        print(s)
    else:
        print(content)




