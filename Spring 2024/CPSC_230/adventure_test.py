from random import randint
from time import sleep

room=0
quote_tutorial=0
inventory=[]
inventory.append('journal1')
inventory.append('keys')
inventory.append('journal2')
inventory.append('flashlight')
inventory.append('rope')
inventory.append('phone')
boots=0
woman_body=1

def error(Dec):
    if Dec!= 'inventory':
        print('\n Error, please input one of the phrases "quoted". \n')
def print_slow(txt):  
    for x in txt:                     # cycle through the text one character at a time -not my comment
        print(x, end='', flush=True)  # print one character, no new line, flush buffer -not my comment
        sleep(0) #Remember to return to .04. also this is where I figured out the sleep command
    print() # go to new line -not my comment


print_slow('''kndfvhdfvjhdbv
''')

print_slow('fdjhndvjhjvh')
# def amnesia():
#     n= randint(1,100)
#     items1=items[0:-1]
#     items2=items[-1:]
#     if n>1:
#         print_slow('''Ah! You feel a pain behind your eyes, darkness floods in from the edges of your vision.
# Suddenly you remember this sensation, it comes back to you.
# This has happened again and again and again.
# The pain, then the darkness, then... you forget everything.''')
#         if items!= []:
#             print('You have gathered,',end=' ')
#             sleep(.7)
#             print(*items1,sep=',',end=' ')
#             print('and,',*items2,'.')
#             sleep(1)
#             print_slow('Hopefully it will be enough to help you when you awake.')



def inventory_hub(Dec):
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
Medical Institute.''')
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
Medical Institute.''')
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
The only activity on it seems to be an SMS message to an unsaved number:
                                       
I hope you like the gift, theres many more
to come, I promise. Listen, if anything goes
wrong tonight I need you to come empty the 
safe in my upstairs study. The password is
my Medical ID which I believe you have.
I can't wait to be with you.
-James
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


def phone(location):
    global room
    print_slow('''You realize you don't know any phone numbers. Except, 911''')
    Dec=input('Call 911? ("yes" or "no")')

    if Dec=='no':
        room=location
    
    elif woman_body==1 and "journal1" in inventory and "journal2" in inventory:
        print_slow('You ')


x='1'
if True:
    room='lotus'
    Dec=input()
    inventory_hub
print(room)
room=('flower')
phone(room)
print(room)