#Soren Marius
#002456139
#Marius@chapman.edu
#CPSC-230-02
#Assignment 2
#Adventure



#Dec is a variable used for any decision made by the player that will only be used once.

#Room names: 'entryway' 'hall intersection' 'basement' 'dining hall' 'dining room' 'kitchen hall' 'kitchen' 'bathroom' 'living hall' 'living room' 'shed' 'porch' 'landing' 'study hall' 'study' 'laundry' 'master bedroom' 'master bathroom' 'End'
from random import randint
from time import sleep

inventory=[]
item=0
quote_tutorial=0
room='entryway'
boots=0
breaker=False
clean=0
shed_lock=0
man_body=0
woman_body=0
C911=0

#Use the error system to cut down on coding later, to be used at the end of decision points.
def error(Dec): #help from "The Coding Den"
    if Dec!= 'inventory':
        print('\n Error, please input one of the phrases "quoted". Or the correct number. \n')
    
    #Prints the text in a slow stylistic format.
def print_slow(txt):  #README line 17
    for x in txt:                     # cycle through the text one character at a time -not my comment
        print(x, end='', flush=True)  # print one character, no new line, flush buffer -not my comment
        sleep(0.04) #Remember to return to .04. (You can set to 0 for ease of testing)
    print() # go to new line -not my comment

#Random death system!
def amnesia(): # amnesia must only be used in a room loop, not an item loop
    n= randint(1,100)
    inven1=inventory[0:-1]
    inven2=inventory[-1:]
    if n>99:
        global breaker
        global room
        breaker= True
        room = 'End'
        print_slow('''Ah! You feel a pain behind your eyes, darkness floods in from the edges of your vision.
Suddenly you remember this sensation, it comes back to you.
This has happened again and again and again.
The pain, then the darkness, then... you forget everything.''')
        if inventory!= []:
            print('You have gathered,',end=' ')
            sleep(.7)
            print(*inven1,sep=',',end=' ')
            print('and,',*inven2,'.')
            sleep(1)
            print_slow('Hopefully it will be enough to help you when you awake.')


#inventory system
            #allows user to look at and select items to examine them
def inventory_hub(Dec): #help from "The Coding Den"
    if Dec=='inventory':
        inven=0
        if inventory!=[]:
            while inven==0:
                print('You\'re inventory includes:',inventory,'enter an item to inspect or enter "exit".')
                Dec=input()
                if Dec=='keys':
                    print_slow('A key ring with a variety of rings attatched.')
                elif Dec=='journal1':
                    while Dec=='journal1':
                        print_slow('''You open the journal to the first page.
Your name is Mike Glass.
You have Anterograde amnesia.
Basically this means that every so often,
your memory resets. It can be every hour,
two or three hours, sometimes you only get
ten minutes. Doctor's don't fully understand 
why. You live in the memory unit of St. John
Medical Institute.

There's only one additional entry.

Doctor Barnes has invited me to his house for
Dinner on October 27th. He says the window should
be unlocked. He says that the Institute can be
cruel, but he wants to give me a gift of a nice
dinner at his house.
712 Oak St.
                                   
The Journal fits in your coat pocket, where it felt like something had been missing.
''')
                elif Dec=='journal2':
                    while Dec=='journal2':
                        print_slow('''You open the journal to the first page.
Your name is Mike Glass.
You have Anterograde amnesia.
Basically this means that every so often,
your memory resets. It can be every hour,
two or three hours, sometimes you only get
ten minutes. Doctor's don't fully understand 
why. You live in the memory unit of St. John
Medical Institute.

On the following pages there's a series of entries.
They describe day to day life, or sometimes hour to hour life,
seemingly depending on when the thy cycle has restarted.
Many of them describe unsavory sessions with a Doctor Barnes.
He seems to have some private research going on that he's been
using Mike Glass, using You for.

The final entry describes a fear that Dr. Barnes has discovered
the journal, and a worry that he might do something with it.

The Journal fits in your coat pocket, where it felt like something had been missing.
''')
                elif Dec=='flashlight':
                    print_slow('A simple battery operated flashlight, a button switches it on and off.')
                elif Dec=='rope':
                    print_slow('A coil of rope.')
                elif Dec=='phone':
                    print_slow('''The phone looks brand new. infact there's still a plastic screen protector,
yet to be peeled off the screen. The phone prompts you for a password.''')
                    while Dec=='phone':
                        password=input('The password has room for 6 digits:')

                        if password=='102799':
                            print_slow('''The phone opens!
The only activity on it seems to be a couple of SMS messages to an unsaved number:

6:00pm                                       
I hope you like the gift, theres many more
to come, I promise. Listen, if anything goes
wrong tonight I need you to come empty the 
safe in my upstairs study. The password is
my Medical ID which I believe you have.
I can't wait to be with you.
-James
                                       
9:30pm
I'm starting to worry, it's getting late,
he should be here by now, what am I going
to do?
''')
                            Dec=input('''Use phone? 
"yes"

"no"
''')
                            if Dec=='yes':
                                phone(room)
                                
                elif Dec=='exit':
                    inven=1
                else:
                    error(Dec)
        
        #Use this definition so that it can be used on the nokia and kitchen phone
def phone(location):
    global room
    global C911
    print_slow('''You realize you don't know any phone numbers. Except, 911''')
    Dec=input('Call 911? ("yes" or "no")')

    if Dec=='no':
        room=location
    elif Dec=='yes':
        C911=1
        if woman_body==1 and "journal1" in inventory and "journal2" in inventory:
            print_slow('''You call 911 and tell them about the bodies you found and the address.
Hopefully between the two journals and the contents of the safe the evidence wont point to you.
Still you still may be the best suspect.
''')
            
        elif woman_body==1 and man_body==1:
            print_slow('''You call 911 and tell them about the bodies. You know you're the only suspect.
And yet it doesn't sit right with you to do nothing,
maybe you are a good person.
''')
        elif woman_body==1 and 'journal2' in inventory:
            print_slow('''The husband must have done it and run away. You call 911 and tell them what you've found.
You hope that more exploration of the house will prove your theory.''')
            
        elif woman_body==1 or man_body==1:
            print_slow('''You don't know who could have done it. It could've been you.'
But calling 911 is the right thing to do.
So you call and you tell them what you've found.''')
            
        else:
            print_slow('''You call 911, hopefully they can help you figure out what's going on.
''')
        fin=0
        while fin != 1:
            print_slow('''The cops will be here soon, but there's still time to "escape".
Of course you can always choose to "stay".''')
            Dec=input()

            if Dec=='escape':
                print_slow('''You decide to escape. It won't do you any good to be here when the cops arrive.
You'll need to make your way out the front door in order to do so.''')
                fin=1
            
            elif Dec=='stay':
                print_slow('''You decide to stay and wait for the cops.
Hopefully you don't forget everything before they arrive.
        T H E    E N D        ''')
                quit()

            else:
                error(Dec)
    
    else:
        error(Dec)





#Main Body
    
print_slow('''This is a game of choice and a game of discovery.
The only ways to end the game are to leave through the front door
or to make a certain call.
What you do, and what you have discovered,
will change the ending you receive.
Press enter when you are ready to begin.''') 
input()  

print_slow('''
Lightning flashes and thunder booms around you.
You are standing on the front porch of a manor, facing the street, rain pelts the roof above you.
You don't know why you're here, you don't know who you are.

Instinctively you pull open your coat and reach into the inside pocket.
You pause,
''')
sleep(.7)
print_slow('''You're not sure what you were looking for but it isn't there.''')
print_slow('''
You decide to explore the house, maybe someone inside knows what's going on.
You raise your fist to knock,
''')
sleep(1)
print('''Lightning Flashes
      ''')
sleep(.5)
print_slow('''In the bright light you see your hand,
''')
sleep(1)
print('''It's covered in blood
      ''')
sleep(1)
print_slow('''Thunder rumbles around you and you feel a sensation you didn\'t notice before.
There's a trickle of blood making it's way down your arm, down your hand and pooling at your finger tips.''')

sleep(1)
print('What',end='  ',flush=True) #Joe Ellis helped me work this out
sleep(1)
print('is', end='  ',flush=True)
sleep(1)
print('happening?!')
sleep(1)
print_slow('''
it\'s time to make a decision, what are you going to do?
1. Approach the house.

2. Leave.''')
sleep(.7)
Dec=input('type the number corresponding to the decision you would like to make')
if Dec=='1':
    Dec=0
    print_slow('''
You decide that entering the house is the only way of gaining any information,
and just maybe there are people in there who can help you.
You raise your fist again to knock but you realize the door is slightly open.''')
    
    while Dec!= '2':
        Dec=input('''Do you:
1. Knock on the door.

2. Push the door open and enter the house.''')
        if Dec != '2':
            print_slow('''You knock on the door and wait, foot tapping nervously.
                       Nothing happens.''')
            continue
    if Dec == '2':
        print_slow('''You slowly open the door to a dimly lit entry way.''') 


# You can comment out all the main body up until this point, if you do uncomment the next line
#if True:

#The House loop

        while room!='End':

    #Entry way loop
            while room=='entryway':
                amnesia()
                if breaker:
                    break
                print_slow('''There's a "shoe rack" on the floor to the left, filled with shoes and boots.
Coats hang above them and that side of the hall gives way to a "staircase".
The right wall opens up into a "living room"  and the "hall" continues ahead.
The "front door" is behind you.''')
                if quote_tutorial==0:
                    quote_tutorial+=1
                    print_slow('Type options displayed in "quotes" to choose them.')
                Dec=input()
                inventory_hub(Dec)


        #Shoe Rack loop
                if Dec=='shoe rack':
                    item='shoe rack'
                    while item=='shoe rack':
                        if boots==0:
                            amnesia()
                            print_slow('''It seems those who live here take there shoes off when they enter the house.
You look down at your wet boots then at the carpet runner that leads down the hall.
Would you like to take your boots off?
1. Yes

2. No
''')
                            shoes=input()
                            if shoes=='2':
                                room='entryway'
                                break
                            elif shoes=='1':
                                print_slow('''You slip your boots off one at a time.
When you take your second boot off you notice a band around your ankle.
It's almost like a tag, with a label that reads:
        G l a s s, M i k e       302-1
        DOB:03/02/1974          SEX: M
        MRN:4815162342         AGE: 25
        Dr. Barnes          ID: 040540''')
                                boots=1
                                Dec=input('Press enter to continue')
                                room='entryway'
                                continue
                            else:
                                error()
                                continue
                        if boots==1:
                            print_slow('''You see your boots sitting on the shoe rack.
Would you like to put them back on?
1. Yes

2. No
''')
                            Dec=input()
                            if Dec=='1':
                                print('''You slip your boots back on''')
                                boots=2
                            elif Dec=='2':
                                pass
                            else:
                                error()
                                continue
                            room='entryway'
                            break
                        if boots==2:
                            Dec=input('''Would you like to take your boots off?
1. Yes
                        
2. No
''')
                            if Dec=='1':
                                boots=2
                            room='entryway'
                            break

        #Transitions from entryway
                elif Dec == 'staircase':
                    print_slow('''You make your way up the stairs.''')
                    room='platform'
                
                elif Dec == 'hall':
                    print_slow('''You make your way dow the hall''')
                    room='hall intersection'
                
                elif Dec == 'living room':
                    print_slow('You make your way into the living room')
                    room='living room'
                    
                elif Dec == 'front door':
                    print_slow('You open the front door and exit the house.')
                    room='End'
                    
                elif Dec == 'staircase':
                    print_slow('You trudge up the stairs.') 
                    room='platform'   
                else:
                    error(Dec)
                    continue
                

    #Loop for downstairs hall intersection   
            while room =='hall intersection':
                amnesia()
                if breaker:
                    break
                print_slow('''You stand at an intersection of four hallways. One leads to the "entryway",
one leads to the "back door", one leads toward the "living room", 
and one that leads toward the "dining room".
Next to the hall is a "basement" door tucked under where the stairs lead up.
There is a sign on it that reads:
    Caution!
Watch your step
Followed by a picture of a stick figure man falling.  
''')
        
        #Transitions from hall intersection
                Dec=input('Where would you like to go?')
                inventory_hub(Dec)
                if Dec== 'entryway':
                    print_slow('You make your way back to the entryway.')
                    room='entryway'
                    break

                elif Dec=='back door':
                    room='kitchen hall'
                    break

                elif Dec=='dining room':

                    room= 'dining room'
                    print_slow('You make your way through the hall to the dining room.')
                    break

                elif Dec=='living room':
                    room= 'living hall'        
                    break

                elif Dec=='basement':
                    room='basement'
                    break
                else:
                    error(Dec)
                    continue


    #living hall loop
            while room == 'living hall':
                amnesia()
                if breaker:
                    break
                print_slow('''You walk along the hall,
pictures decorate the walls, a young man, a young woman.
Then a bride and groom on their wedding day,
and finally an old man and his old wife.''')
                Dec =input('From this point you can enter the "bathroom", the "living room", or the main "hall".')
                inventory_hub(Dec)

        #Transition from living hall
                if Dec=='bathroom':
                    print_slow('You make your way into the bathroom.')
                    room='bathroom'

                elif Dec=='living room':
                    print_slow('You enter the living room.')
                    room='living room'
                
                elif Dec=='hall':
                    print_slow('You walk to the main hall.')
                    room='hall intersection'

                else:
                    error(Dec)
                    continue



    #living room loop
            while room == 'living room':
                amnesia()
                if breaker:
                    break
                print_slow('''The tv is on, with some news channel droning on in the background.
Opposite the tv is a small couch and a "recliner".
The other side of the room there's a small "table".
From here you can also access the "entryway" and the other "hall"''')
                Dec=input()
                inventory_hub(Dec)

                if Dec=='recliner':
                    print_slow('''It's a well worn recliner, someone sits here a lot.
Balanced on the arm of the chair is a tray from a microwave dinner.
There's a layer of gravy that a fork has slipped into.
Laying on top of it is a reciept for a new phone.
Written in ink it says:
Password is today's date.
''')
                

           #table loop     
                elif Dec=='table':
                    item='table'
                    while item=='table':
                        print_slow('''Sitting on the table is a pile of "mail".''')
                        if 'keys' not in inventory:
                            print_slow('And a ring of "keys"')
                        Dec=input('Enter "back" to leave.')
                        inventory_hub(Dec)

                        if Dec=='mail':
                            print_slow('''It looks like a collection of today's mail, there's a newspaper opened to the crossword.
It's all addressed to either Dr. Barnes, or Mrs. Barnes.
''')
                        elif Dec=='keys':
                            key=1
                            inventory.append('keys')
                            print_slow('''"keys" added to your inventory,
your inventory can be accessed from most decision points by inputting "inventory".
''')    
                        elif Dec=='back':
                            item=0

                        else:
                            error(Dec)


        #Living room transitions    
                elif Dec=='entryway':
                    room='entryway'
                    print_slow('You make your way back to the entryway.')

                elif Dec=='hall':
                    room= 'living hall'

                else:
                    error(Dec)
                    continue

                

    #basement loop
            if room == 'basement':
                amnesia()
                
                    
                if 'flashlight' not in inventory:
                    print_slow('''It is too dark to see anything going on down there,
you'll have to return with a light source.''')
                    room='hall intersection'
                    
                elif 'flashlight' in inventory:
                    if man_body==0:
                        man_body=1
                        print_slow('''You flick on the flashlight to an odd sight.
The floor continues a bit down a small hall way only to drop off suddenly into the basement.
A seven foot drop into the abyss. You shine your flashlight sraight down from the cliff.
                                     . . .                                              
There's a body lying down there, a pool of blood around him.
You feel a surge of panic. How did this happen?
Should you call the cops? But what if they arrest you?
                                    . . .
What if you did it?
''')
                    print_slow('''You could go down there, invesgtigate and see what you can find.
But you'll need a way back up.
''')
                    if 'rope' not in inventory:
                        room='hall intersection'
                    
                    else:
                        print_slow('''You tie the rope you found around a post and lower yourself into the basement.
''')
                        while room=='basement':
                            print_slow('''Closer to the body you see it is an older gentleman.
He has a name tag on which reads:
    Dr. Barnes
You can either inspect the "body" or go "back".''')
                            Dec=input()
                            inventory_hub(Dec)

                            if Dec=='back':
                                room='hall intersection'

                            elif Dec=='body':
                                item='body'
                                while item=='body':
                                    print_slow('''You see clutched in his left hand a kitchen knife, there's blood on it.
''')
                                    if 'journal1' not in inventory and 'phone' not in inventory:
                                        print_slow('''In his other hand you see a small "journal".
And sticking out of his pocket there's a Nokia "phone".
''')
                                        
                                    elif 'journal1' not in inventory:
                                        print_slow('''In his other hand you see a small "journal".
''')
                                    elif 'phone' not in inventory:
                                        print_slow('Sticking out of his pocket there\'s a Nokia "phone".')

                                    else:
                                        print_slow('There\'s nothing more to find')
                                        break
                                    Dec=input()
                                    inventory_hub(Dec)

                                    if Dec=='journal' and 'journal1' not in inventory:
                                        print_slow('Journal added to inventory.')
                                        inventory.append('journal1')

                                    elif Dec=='phone' and 'phone' not in inventory:
                                        print_slow('Phone added to inventory.')
                                        inventory.append('phone')

                                    else:
                                        error()

                                                   


                            else:
                                error(Dec)

            
    #Dining room loop
            while room == 'dining room':
                amnesia()
                if breaker:
                    break
                print_slow('''The dining room is extravengant, with a large crystal chandelier and tall windows.
The "table" is set with a plate and silverwear at each chair, accompanied by a crystal glass.
Just outside the dining room was a wall filled with "accolades".''')
                Dec=input('Where would you like to go? (write "back" to exit the room)')
                inventory_hub(Dec)

                if Dec=='back':
                    room= 'hall intersection'
                    break
                
                if Dec=='accolades':
                    print_slow('''The wall is decorated with frames containing a diploma and some awards.
One catches your eye, an award for scientific excellency in neuroscience.
These are all for the same man, a Doctor James Barnes.''')
                    
                if Dec=='table':
                    print_slow('''You approach the table, it's set as if for a nice dinner.
You put your finger on the table and draw a line.
It leaves a trail in the thick dust, this table hasn't been used in a while.''')
                
                else:
                    error(Dec)
                    continue

    #Kitchen hall loop
            while room == 'kitchen hall':
                amnesia()
                if breaker:
                    break
                print_slow('''You see four ways to go from this little hall.
You can go to the main "hall" of course,
as well as the "kitchen", back "door", and the "bathroom"
''')
                Dec=input()
                inventory_hub(Dec)

                if Dec=='hall':
                    room='hall intersection'

                elif Dec=='kitchen':
                    room='kitchen'
                    print_slow('You step into the kitchen.')

                elif Dec=='door':
                    room='porch'
                    print_slow('You open the door to the back end of the house and take a step outside.')
                
                elif Dec=='bathroom':
                    room='bathroom'
                    print_slow('You enter the bathroom.')

                else:
                    error(Dec)
            
    #Kitchen loop
            while room == 'kitchen':
                amnesia()
                if breaker:
                    break
                print_slow('''The kitchen is very open, to your left you see a fridge and oven ahainst the wall.
A large "island" holds the stovetop as well as a dishwasher and barstool seats.
On the right side there is a round "table" with chairs on one side and window seats on the other.
The kitchen windows overlook a small porch and a backyard.
There's a "phone" on the wall next to you.
(Type "back" to leave)
''')
                Dec=input()
                inventory_hub(Dec)

                if Dec=='island':
                    print_slow('Theres a knife block sitting on the granite countertop, a knife is missing.')

                elif Dec=='table':
                    print_slow('''The table is covered in various fabrics as well as a sewing machine.
Someone must be in the middle of a project.
''')
            #Phone loop
                elif Dec=='phone':
                    print_slow('You take the phone off the wall and hold it to your ear.')
                    phone(room)
                    print_slow('You put the phone back.')

                elif Dec=='back':
                    room='kitchen hall'


                else:
                    error(Dec)

            
    #bathroom loop
            while room == 'bathroom':
                amnesia()
                if breaker:
                    break
                print_slow('''The bathroom has a "sink" with a toilet next to it.
On the other wall there's a shower with a clear glass door. There's two doors from the bathroom, 
one leads to the "kitchen" hall, and one to the "living room" hall.
''')
                Dec=input()
                inventory_hub(Dec)

                if Dec=='sink'and clean==0:
                    clean=1
                    print_slow('''You approach the sink and stop suddenly.
That's you standing in the mirror above the sink.
You touch your face, dark eyebrows, 
long brown hair with hints of gray that falls to your jaw.
You realize your jaw has been clenched and eyebrows furrowed
this whole time, you stop to the best of your ability. 
You splash water on your face and wash the blood from your hands.
Then you open the mirror cabinet, find a roll of bandages, take off your
jacket and- ...are you wearing a hospital gown?... why?
You'll have to figure it out later. For now you wrap your arm with a bandage.
Hopefully noone here minds.''')
                
                elif Dec=='sink':
                    print_slow('You take this opportunity to wash your hands.')

                elif Dec=='kitchen':
                    room='kitchen hall'

                elif Dec=='living room':
                    room='living hall'

                else:
                    error(Dec)
            
    #porch loop
            while room == 'porch':
                amnesia()
                if breaker:
                    break
                print_slow('''You stand on the back porch, listening to the drum of rain on the roof.
In front of the kitchen windows there's two big wooden rockers over looking the "yard".
On the other side of the porch theres a card "table" surrounded by chairs.
The only door leads back to the kitchen "hall".
''')
                Dec=input()
                inventory_hub(Dec)
                if Dec== 'yard':
                    if 'flashlight' not in inventory:
                        print_slow('It is too dark for you to go out there without a light source.')
                    
                    elif boots==1:
                        print_slow('You look down at your socks, you wouldn\'t want to walk out in the wet grass shoeless.')

                    else:
                        print_slow('You flick on your flashlight and head out to the yard.')
                        room='yard'

                elif Dec=='table':
                    item='table'
                    while item=='table':
                        if 'flashlight' not in inventory:
                            print_slow('''The table isn\'t currently being used for anything but a "flashlight" rests upon it.
Enter "back" to go back.
''')
                            Dec=input()
                            inventory_hub(Dec)

                            if Dec=='flashlight':
                                print_slow('flashlight acquired.')
                                print_slow('your inventory can be accessed from most decision points by inputting "inventory".')
                                inventory.append('flashlight')

                            elif Dec=='back':
                                item=0
                            
                            else:
                                error()

                        else:
                            print('The table is empty')
                            item=0

                elif Dec=='hall':
                    room='kitchen hall'

                else:
                    error(Dec)


   #yard loop
            while room =='yard':
                print_slow('''Through the beam of the flashlight you can see a modestly sized yard.
Opposite the "porch" theres a small "shed" pressed against the fence.
''')
                Dec=input()
                inventory_hub(Dec)

                if Dec=='porch':
                    room='porch'

                elif Dec=='shed':
                    item='shed'
                    if item=='shed'and shed_lock==0:
                        print_slow('The shed is locked.')
                        if 'keys' in inventory:
                            print_slow('''You manage to find the right key from the keyring in your pocket.
You unlock the shed.
''')
                            shed_lock=1
                            while item=='shed':
                                print_slow('You open the shed door.')
                                while 'rope' not in inventory:
                                    print_slow('''The shed is a mess, everything is knocked over everything else. 
Nothing is accesible without digging through everything else.
Except.. there is a coil of "rope" hanging on the wall.
(Enter "back" to leave.)
''')
                                    Dec=input()
                                    inventory_hub(Dec)

                                    if Dec=='rope':
                                        print_slow('rope acquired')
                                        inventory.append('rope')
                                        break
                                    
                                    elif Dec=='back':
                                        item=0
                                    
                                    else:
                                        error(Dec)
                                else:
                                    print_slow('The shed is a mess, nothing of use is in there.')
                                    break

                    item=0
                else:
                    error(Dec)

#Upstairs!! Finally!
            while room =='platform':
                print_slow('''You stand at the top of the "stairs". Opposite them is the master "bedroom".
Another hall leads to the "laundry room". And finally going along the upstairs banister brings you to the "study".
''')
                Dec=input()
                inventory_hub(Dec)

                if Dec=='stairs':
                    room='entryway'
                    print_slow('You make your way down the stairs.')

                elif Dec=='study':
                    room='study'
                    print_slow('You make your way around to the study.')

                elif Dec=='laundry room':
                    room='laundry'
                    print_slow('You go down the hall and enter the laundry room.')

                elif Dec=='bedroom':
                    room='master bedroom'
                    print_slow('You open the door to the master bedroom.')

                else:
                    error(Dec)


            while room == 'laundry':
                print_slow('''Theres a load going in the dryer right now.
Like the other rooms it's are nicely decorated.
There's light blue drapes in the windows
and a floral wallpaper.
There doesn\'t seem to be anything interesting in here.
(enter "back" to leave.)''')
                Dec=input()
                inventory_hub(Dec)
                if Dec=='back':
                    room='platform'
                else:
                    error()


            while room == 'master bedroom':
                if woman_body ==0:
                    woman_body=1
                    print_slow('''She draws your attention immediately, the woman lying on the bed.
Blood pools around her and pours off the bed.
Oh god... did you do this?
Should you call 911?
''')
                print_slow('''Opposite the "door" is a window with with red drapes 
and a vase of flowers on most surfaces.
The "body" lies upon a large bed with a night stand on either side.
Opposite the bed is the entrance to the master "bathroom".

''')
                Dec=input()
                inventory_hub(Dec)

                if Dec=='door':
                    print_slow('You exit the room.')
                    room='platform'

                elif Dec== "body":
                    print_slow('''It makes you sad to see her body lying there.
You notice the wound on her chest,
a knife wound.
You touch your arm...
Perhaps you're both visctims.
        
You hope so.
''')
                elif Dec=="bathroom":
                    print_slow('You enter the bathroom.')
                    room='master bathroom'

                else:
                    error(Dec)

                
            while room == 'master bathroom':
                print_slow('''It is quite a nice bathroom. They have romeo and juliet style "sinks"
next to their toilet, and a large bathtub with a shower head.
(enter "back" to leave)
''')
                Dec=input()
                inventory_hub(Dec)

                if Dec=='sinks':
                    print_slow('''Getting closer you can see it.
There's blood on one of the sink faucets.
Someone washed the blood from their hands.
''')
                elif Dec=='back':
                    room='master bedroom'
                
                else:
                    error(Dec)


            while room == 'study':
                print_slow('''The center of the study is a very ornamental wooden desk.
On the front there's a plaque which reads:
        Dr. Barnes
On top of the desk there's a paper rip-off "calendar".
There's also a "computer" in the middle of the desk,
And there's one large "cabinet" on the bottom left side of the desk.
(enter "back" to leave)''')
                Dec=input()
                inventory_hub(Dec)

                if Dec=='back':
                    room='platform'

                elif Dec=='calendar':
                    print_slow('''It's a calendar for the year 1999,
that sounds right to you. You think.
It's currently on October with every day crossed off up to October 27th.
In addition October 27th is circled, perhaps that's today?
10/27/99
''')
                elif Dec=='computer':
                    item='computer'
                    print_slow('''You boot up the computer...''')
                    while item=='computer':

                        print_slow('''It seems to be open to an E-mail program.
There is an E-mail currently open from what seems to be "work",
and there is also a "notification" for a new E-mail.
(enter "back" to leave)
''')
                        Dec=input()
                        inventory_hub(Dec)

                        if Dec=='work':
                            print_slow('''
Dear Dr. Barnes,
                                       
I hope this email finds you well. We are writing to alert you to some
changes that will be comming to our facilities soon. Due to concerns
related to the revalations that came out about the penbrook institute
last spring we have decided to change our ethos and practices. You
are of course a respected member of our institution, so we hope you 
understand that these changes come strictly out of a place of caution,
and not from any lack of trust in your integrity.

That being said, starting in December we will now have an attendent
required to be present at all times in the Electroconvulsive therapy
room. In other words it will no longer be allowed for a Doctor to 
take their patient their privately. In addition camera's will be 
installed in this room. finally, records will be kept of all therapy
Sessions.

Best,
Doctor Conrad
''')
                        elif Dec=='notification':
                            print_slow('''You click on the notification and it takes you to another E-mail.

Dear James,
Understood, I will message your phone from now on. I am awfully excited
but also sick at the thought of tonight. Be sure to let me know how it
goes! I'm sure to be up worried sick. But I'll be there cooking for you soon.
Love,
Marci
''')
                        elif Dec=='back':
                            item=0

                        else:
                            error(Dec)
                            
        
                elif Dec=='cabinet':
                    print_slow('You open the cabinet to find a large metal safe.')
                    item='safe'
                    while item=='safe':
                        print_slow('It requires a passcode of 3 two digit numbers.')
                        print_slow('Ex: "01 02 03"')
                        print_slow('Enter "back" to leave.')
                        Dec=input()
                        inventory_hub(Dec)

                        if Dec=='04 05 40':
                            print_slow('You turn the dial a few times and hear a satisfying click.')
                            while item=='safe':
                                print_slow('''The safe is open. You see a few items resting inside.
There is a "folder" filled with various papers.
There is what seems to be a thin "box" with a bow on it.
Enter "back" to leave.''')
                                if "journal2" not in inventory:
                                    print_slow('There is a small "journal" as well.')
                                Dec=input()
                                inventory_hub(Dec)

                                if Dec=='folder':
                                    print_slow('''The folder contains many different profiles on what appear to be patients.
Flipping through one you find one with a circle on it in red pen.
The name is Mike Glass. In red pen also written on it is:
        10/27/99 approx. 9:30 pm.
In the doctor's notes you notice he's described as violent. 

There's another file that stands out, some sort of accounting work,
a calculation on how much a divorce would cost and how much someone would lose.                      
''')
                                    if clean==1:
                                        print_slow('''You peer a the photo for a second then stop.
That's the reflection you saw in the mirror, that's you!
Why?
''')
                                    elif boots==1 or boots==2:
                                        print_slow('''Mike Glass...
That's the name on the ankle tag you found.
Is this you?
''')
                                    print_slow('You return the folder.')
                                if Dec=='box':
                                    print_slow('''You grab the box and open it.
There's a glamorous necklace inside,
with a diamond teardrop in the center.
There's a tag on the box,
        For: M
          - J
''')
                                if Dec=='journal':
                                    print_slow('Journal added to inventory')
                                    inventory.append('journal2')

                                if Dec=='back':
                                    break
                        elif Dec=='back':
                            break
                        else:
                            print_slow('The Safe doesn\'t open.')
                               

        #The endings!! yay!
        if C911 ==1:
            print_slow('As you take off into the night, you think you hear sirens in the background.')
        if man_body==1 and woman_body==1 and 'journal1' in inventory and 'journal2' in inventory:
            print_slow('''You're taking the evidence that could maybe exhonerate you,
But that doesn't mean it actually will. It's best to be gone before anyone shows up.
Besides,''')
        elif man_body==1 and woman_body==1:
            print_slow('''There's two bodies in there and no evidence of anyone else around.
You're automatically going to be the first suspect. Best to run. Besides,''')
            
        elif man_body==1 or woman_body==1:
            print_slow('''There's no sense waiting around in a house of murder. 
You shudder at the thought. And another thought creeps in.''')
        if man_body==1 or woman_body==1:
            print_slow('''No matter how much evidence you found, not matter how you try and piece it together.
There is no way you can be certain that you didn't have a hand in what happened here tonight.''')

        else:
            print_slow('''You think it\'s best to get out of there sooner rather than later.
You'll find your way on your own.''')
            
else:
    print_slow('''It's best to figure it out on your own you decide, besides, this house doesn't sit quite right with you.
Hunched with your hand clenching your wounded arm you take off with nothing to your name.''')
    sleep(.5)
    print('Hell,',end='',flush=True)
    sleep(.7)
    print_slow('you don\'t even have a name.')

print_slow('            T  H  E      E  N  D            ')