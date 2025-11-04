#Soren Marius
#002456139
#Marius@chapman.edu
#CPSC-230-02
#Assignment 3
#Stats

import math

#definition for sorting lists
def sorted_list(list):
    #sorts list
    list.sort()
    #returns sorted list
    return list

#definition for computing the mean
def compute_mean(list):
    #returns the computed mean (by summing and dividing by length)
    return sum(list)/len(list)

#definition for computing variance
def compute_variance(list):
    #define sum so that it can be used later
    sum=0
    for i in list:
        #calls the computer mean function to get the average
        sum+=(i-compute_mean(list))**2
    #finishes the equation and returns it
    return sum/len(list)

#definition for computing standard deviation
def compute_standard_dev(list):
    #computes the squareroot after calling compute variance and returns
    return math.sqrt(compute_variance(list))

#define so that the loop starts
x=0
#defines for the building of the loop
nums=[]
#will end when user inputs a negative value
while x>-1:
    #appends what the user has inserted
    nums.append(x)
    #asks for the users value
    x=int(input('What number would you like to add?'))
#Removes 0 so that the initial x value I assigned doesn't ruin the math
nums.remove(0)
#calls sorted_list
print (sorted_list(nums))
#calls compute_mean
print (compute_mean(nums))
#calls compute_variance
print (compute_variance(nums))
#calls compute_standard_dev
print (compute_standard_dev(nums))

