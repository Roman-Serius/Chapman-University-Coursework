import math

def doubles(str,list):
    return list.count(str)>1

def more_than_one(str,list):
    if str in list:
        list.remove(str)
        if str in list:
            return True
    return False    

print(more_than_one('abc',['abc','abc',123]))

def vowels(list):
    vowel='AEIOUaeiou'
    new_list=[]
    for i in list:
        if i[0] in vowel:
            new_list.append(i)
    return(list,new_list)
print(vowels(['ad','gh','as']))


def square(list):
    return math.sqrt(sum(list)) %1 == 0
    
print(square([1,2,3,1]))  

