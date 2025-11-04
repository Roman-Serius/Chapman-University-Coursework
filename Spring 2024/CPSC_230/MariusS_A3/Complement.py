#Soren Marius
#002456139
#Marius@chapman.edu
#CPSC-230-02
#Assignment 3
#Complement


#Definition for complement
def complement(DNA):
    #create empty string to use later
    Comp=''
    #iterates over every char in the DNA string
    for i in DNA:
        #replaces A with T
        if i=='A':
            i='T'
        #replaces T with A
        elif i=='T':
            i='A'
        #replaces G with C
        elif i=='G':
            i='C'
        #replaces C with G
        elif i=='C':
            i="G"
        #Catches errors and ends the function
        else:
            return('Error invalid DNA Sequence')
        #stores the new value
        Comp+=i
    #returns the complement
    return Comp

#Definition for reversint the complement   
def rev_complement(DNA):
    #for storing data later
    rev=''
    #calls complement function and stores it
    DNA=complement(DNA)
    #Checks for error
    if DNA=='Error invalid DNA Sequence':
        return DNA
    #Concatenates to the front to reverse the order
    for i in DNA:
        rev=i+rev
    #returns the reverse
    return rev

#calls the complement function of the input and prints the result
print(complement(input('What string would you like the complement of?')))

#calls the rev_complement function of the input and prints the result
print(rev_complement(input('What string would you like the reverse complement of?')))

