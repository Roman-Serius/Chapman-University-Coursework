# num=int(input('enter an integer:'))
# if num > 0:
#     print("The number,",num,'is greater than 0.')
# if num < 0:
#     print("The number,",num,'is less than 0.')
# if num == 0:
#     print("The number is", num)

#if-else example

# int_a = int(input('enter initial value'))
# int_b = int(input('enter secondary value'))
# if int_a > int_b:
#     print('initial value,',int_a,'is greater than secondary value,', int_b)
# else:
#     print('secondary value,',int_b,'is greater than initial value',int_a)

#Nested Conditional
number=int(input('put in a number'))
if number > 0 :
    if number % 2 == 0:
        print(number, 'is even')
    else:
        print(number,'is odd')
elif number == 0:
    print(number,'is 0')
else:
    print(number,'is negative')
