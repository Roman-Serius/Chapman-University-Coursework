import math

def circ(rad):
    return (2*math.pi*rad)

def vol_sph(rad):
    return ((4/3)*math.pi*rad**3)

def vol_cyl(rad,hei):
    return ((math.pi*hei*rad**2))

def area_rec(l1,l2):
    return(l1*l2)

rad=float(input('radius?'))
height=float(input('cylindar height?'))
print(circ(rad),vol_sph(rad),vol_cyl(rad,height))

length1=float(input('length 1?'))
length2=float(input('length 2?'))

print(area_rec(length1,length2))