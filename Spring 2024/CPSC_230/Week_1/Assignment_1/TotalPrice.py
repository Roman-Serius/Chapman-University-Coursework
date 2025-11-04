#Soren Marius
#002456139
#Marius@chapman.edu
#CPSC-230-02
#Assignment 1
#Total Price

price=float(input('Price:'))
if price < 0:
    print('Invalid Price')
    print('You entered', price)
    print('Negative values are not accepted')
else:   
    tax_rate=float(input('Tax Rate:'))
    if tax_rate < 0:
        print('Invalid Tax Ratte')
        print('You entered', tax_rate)
        print('Negative values are not accepted')
    else:
        tax_rate=tax_rate/100+1
        price=price*tax_rate
        print('Total price is',price)