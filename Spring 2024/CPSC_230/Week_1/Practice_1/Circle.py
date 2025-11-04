#calculating circumfrence and area of a circle given the radius
import math

radius=input("Enter Radius:")

radius=int(radius)

circumfrence=2*math.pi*radius
area=math.pi*radius**2

print("The Circumfrence is:",circumfrence)

print("The Area is:",area)
