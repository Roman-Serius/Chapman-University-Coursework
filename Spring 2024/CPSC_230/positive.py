x=float(input('enter a positive number'))
counter=0 #keep track of non positive numbers inputed
while x<=0 and counter <5:
    counter+=1
    if x==0:
        print('technically 0 is not a positive number')
    else:
        print('You are very bad at following instructions.')
    x=float(input('enter a positive number'))
if counter >= 5 and x<=0:
    print('Do you not know what positive numbers are?')
    print('I can\'t deal with this')
else:
    print('Congrats you entered a positive number.')