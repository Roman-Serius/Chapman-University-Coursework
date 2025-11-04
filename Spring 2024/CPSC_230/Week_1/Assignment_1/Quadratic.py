#Soren Marius
#002456139
#Marius@chapman.edu
#CPSC-230-02
#Assignment 1
#Quadratic

import math

a=float(input('a:'))
b=float(input('b:'))
c=float(input('c:'))
discriminate= b**2-4*a*c
if discriminate >=0 :
    xpositive=(-b+math.sqrt(b**2-4*a*c))/2*a
    xnegative=(-b-math.sqrt(b**2-4*a*c))/2*a
    print('The roots are:')
    print('x=',xpositive)
    print('x=',xnegative)
else:
    print('The discriminate is:',discriminate)
    print('Negative discriminates are not allowed')