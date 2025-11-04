sum ='hi'
num =0
while sum!='.':
    sum=input('What number would you like to add?')
    if sum == '.':
        pass    
    else:  
        sum=float(sum)
        if sum%2==1:
            print('That number is odd and won\'t be added')
            continue        #in order to not use continue we could put the rest of the loop in an else statement
        num+=sum
        print(num)
print('Addition complete.')
print('Final number is:',num)