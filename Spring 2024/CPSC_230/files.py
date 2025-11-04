def read_file(file):
    #openning a conection to file file with access mode of r
    input_file=open(file, "r")
    #read in contents from file and store as string
    contents=input_file.read()
    input_file.close()
    return contents

def write_file(file,contents):
    output=open(file,"a")
    output.write(contents)
    output.close()




def character_classifier(char):
    if char.isalpha():
        return '0'
    elif char.isdigit():
        return '1'
    elif char == '\n':
        return '\n'
    else:
        return '2'
    

file=read_file('input.txt')
for i in file:
    x=character_classifier(i)
    write_file('output.txt',x)
    print(x)

