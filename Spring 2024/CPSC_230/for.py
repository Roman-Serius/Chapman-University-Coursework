
# num=int(input('What number?'))
# for x in range(1,num+1):
#     if x%2==1:
#         print(x,'is odd.')
#     else:
#         print(x,'is even')

# for num in range(5):
#     print (num)
# counter=0
# while counter<5:
#     print(counter)
#     counter+=1

# while True:
#     for x in range(8):
#         y=2*x+1
#         print(y)
#         if y>6:
#             break

add=True
sum=0
while add:
    num=input('Numbers?')
    if num=='Q'or num=='q':
        add=False
    else:
        sum +=int(num)
        print(sum)