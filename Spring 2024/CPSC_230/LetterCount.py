def letter_count(str):
    dict={}
    for i in str:
        if i in dict.keys():
            dict[i]+=1
        else:
            dict[i]=1
    return dict




string=input()
print(letter_count(string))