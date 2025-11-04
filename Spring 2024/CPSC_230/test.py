import itertools
import random
import math
Rank=['A',1,2,3,4,5,6,7,8,9,10,'J','Q','K']
Suits=['Clubs','Diamonds','Hearts','Spades']
Deck= list (itertools.product(Rank,Suits))

def Deal(num,name):
    l=range(len(Deck)//num)
    for x in name:
        hand=[]
        for i in l:
            n=random.randint(0,len(Deck)-1)
            hand.append(Deck[n])
            Deck.remove(Deck[n])
    x=hand
    print(x)








NumPlayers=int(input('How many people are playing?'))
Names=[]
for i in range(NumPlayers):
    Name=(input('Who is playing?'))
    Names.append(Name)

Deal(NumPlayers,Names)