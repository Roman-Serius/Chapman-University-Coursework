word=input('What word?')
vowels=""
constantants=''
for x in word:
    if 'a' == x or 'e' == x or 'i'== x or 'u' == x or 'o' == x:
        vowels+= x
    else:
        constantants+= x
print(vowels)
print(constantants)