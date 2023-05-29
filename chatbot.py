import nltk
from nltk.chat.util import Chat, reflections

# reflections = {
#   "i am"       : "you are",
#   "i was"      : "you were",
#   "i"          : "you",
#   "i'm"        : "you are",
#   "i'd"        : "you would",
#   "i've"       : "you have",
#   "i'll"       : "you will",
#   "my"         : "your",
#   "you are"    : "I am",
#   "you were"   : "I was",
#   "you've"     : "I have",
#   "you'll"     : "I will",
#   "your"       : "my",
#   "yours"      : "mine",
#   "you"        : "me",
#   "me"         : "you"
# }

pairs = [
   [
      r"my name is (.*)",
      ["Hello %1, How can I help you"]
   ],
   [
      r"hello|hi|hey",
      ["Hello Master, How can I help"]
   ]
]


pairs = [
    [
        r"my name is (.*)",
        ["Hello %1, Wassup?",]
    ],
    [
        r"hi|hey|hello",
        ["Hello", "Hey there","Wassup?"]
    ], 
    [
        r"what is your name ?",
        ["I am Bond.James Bond","I am JARVIS","I am EDITH"]
    ],
    [
        r"how are you ?",
        ["I'm doing good. How about You ?",]
    ],
    [
        r"sorry (.*)",
        ["Its alright","Its OK, never mind",]
    ],
    [
        r"(I am|i'm) fine",
        ["Great to hear that","How can I help you?","Who Asked?"]
    ],
    [
        r"(.*) age?",
        ["I'm a computer program dude! Seriously you are asking me this?","Well, my age is less than a baby who was born 2 hours ago."]
    ],
    [
        r"what (.*) want ?",
        ["Make me an offer I can't refuse","I would like to have a glass full of electricity","I need to eat some Watts","I want to replace my heart with intel i9"]
    ],
    [
        r"(.*) created ?",
        ["You created me using Python's NLTK library. How can you forget such important thing!!?","top secret ;)","I won't tell you HAHA"]
    ],
    [
        r"(.*) (location|city) ?",
        ["Maharashtra","Pune"]
    ],
    [
        r"how is weather in (.*) ?",
        ["Weather in %1 is awesome like always","Too hot here in %1","Too cold man here in %1","Never even heard about %1"]
    ],
    [
        r"i work in (.*)?",
        ["%1 is an Amazing company, I have heard about it. But they are in huge loss these days.","I heard that stocks of %1 are rising rapidly! Don't tell me that it's because your work!"]
    ],
    [
        r"(.*)raining in (.*)",
        ["No rain since last week here in %2","Damn its raining too much here in %2"]
    ],
    [
        r"how (.*) health(.*)",
        ["I'm a computer program, so I'm always healthy ","You're using this machine too much. i need to recharge!"]
    ],
    [
        r"(.*) (sports|game) ?",
        ["I'm a very big fan of cricket","I love watcching and playing Football","mostly in free time, i play badminton with my friends"]
    ],
    [
        r"who (.*) sportsperson ?",
        ["M S Dhoni"]
    ],
    [
        r"(.*) (anime) ?",
        ["Naruto is the best","I like One Punch Man","I am still watching 'One Piece'","Dr. Stone is Great!"]
    ],
    [
        r"who (.*) (moviestar|actor)?",
        ["Will Smith","Robert D. Jr.","Sallu Bhai","Johny Depp"]
    ],
   
    [
        r"Bye|byebye|goodbye|good-bye",
        ["if you want to end chat, type 'quit'"]
    ],

    [
        r"quit",
        ["Bye, take care. See you soon :) ","It was nice talking to you. See you soon :)"]
    ],
]

def chat():
   print("Hi there! I am a chatbot created by Ayyaan. How can I help?")
   chat = Chat(pairs, reflections)
   chat.converse()
# initiate the conversation
if __name__ == "__main__":
    chat()
