import random
secret= random.randint(0,100)
num=int(input('What is your guess?'))
while num != secret:
    if 0<=num<=100 :
        if num>secret:
            print('Too high, try again')
        else:
            print('Too low, try again')
        num=int(input('What is your guess?'))
    else: #number is outside of bounds
        print('You guessed', num, 'you forfeit by guessing out of bounds')
        break
else:
    print('Congrats, you guessed the secret number:',secret)