import math

def area_circle(radius_float):
    area = math.pi * radius_float **2
    return area
x=0
while x==0:
    try:
        nums=open(input('input file'),'r')
        x+=1
    except FileNotFoundError:
        print('That file doesn\'t exist.')
numb=nums.read()
nums.close()

radii=numb.split('\n')
Result=open('Result_Circle.txt','a')
try:
    for i in radii:
        i=float(i)
        q=str(area_circle(i))
        Result.write(q)
        Result.write('\n')

    print('Program succesful')
except ValueError:
    print('There are characters in radius_in.txt which are not digits, please correct.')
Result.close()



