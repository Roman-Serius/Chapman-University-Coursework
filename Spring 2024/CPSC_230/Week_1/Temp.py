temp=int(input('What is the temperature today?'))
if temp > 70:
    print('shorts recommended today')
elif temp > 60:
    print('pants recommended today')
elif temp > 50:
    print('jacket recommended today')
elif temp < 32:
    print('freezing temperatures today dress acordingly')
else:
    print('cool whether today, pants, jacket, and scarf recommended')