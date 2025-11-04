pref_temp=float(input('What temperature would you like your beverage?'))
bev_temp=190
while pref_temp>190:
    print('I am sorry, we are unable to provide beverages warmer than 190 degrees Farenheit.')
    pref_temp=float(input('What temperature would you like your beverage?'))
if bev_temp>pref_temp:
    print('Cooling in proccess, temperature will be shown.')
    while bev_temp>pref_temp:
        print(bev_temp)
        bev_temp-=1
print(bev_temp)
print('Your beverage is ready!')