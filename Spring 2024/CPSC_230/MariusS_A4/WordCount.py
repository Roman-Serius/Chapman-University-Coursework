#Soren Marius
#002456139
#Marius@chapman.edu
#CPSC-230-02
#Assignment 4
#WordCount



import operator

#for reading files
def read_file(f):
    file=open(f,"r")
    contents=file.read()
    file.close()
    return contents
#for building dictionary
def build_dictionary(string):
    #split string into a list
    list=string.split()
    #create empty dictionary
    dict={}
    for i in list:
        #account for punctuation
        i=i.strip('.,"\';:|!?@#$%^&*()_-+=[]}{')
        #account for Case
        i=i.upper()

        # I kept getting a count for nothing (which I assume was caused by stripping everything away from a string.)
        #So this removes nothing or '' from the dictionary
        if i == '':
            pass
        else:
            #counts and builds the dictionary
            if i in dict:
                dict[i]+=1
            else:
                dict[i]=1
    return dict

#for writing file
def write_file(f,d):
    dict = sorted(d.items(), key=operator.itemgetter(1))
    dict.reverse()
    file=open(f,"w")
    content=''
    for pair in dict:
        content+=pair[0]+': '+str(pair[1])+'\n'
    file.write(str(content))
    file.close()

loop=0
while loop==0:
    try:
        #read file from input and calls read_file function
        HP_text=read_file(input('Input the file you would like processed.'))
        #calls build_dictionary and stores the string
        HP_dict=build_dictionary(HP_text)
        #calls write file
        write_file('counts.txt',HP_dict)
        loop+=1
    except FileNotFoundError:
        print('The file you input is invalid')

    
