Soren Marius
002456139
Marius@chapman.edu
CPSC-350-01
PA4: Genetic Palindromes

SourceFiles:
DblList.H
DNASeq.H
Main.cpp
PalindromFinder.H

Errors:
Occasionally the program seems to act erratically with a variety of issues:
-Not reading in full lines and then exiting the program
     (This shows with a single letter printing to the terminal)
-Being wrong (Genetic palindromes get marked as not genetic palindrome etc.)

HOWEVER
    The program has worked correctly more time than not, it seems sometimes it is necessary 
to recompile and delete and remake the input document.

Sources:
    I used chatGPT to help me remake the DBLList class (because I couldn't find the one we'd made.)
    I used it for help but i didn't have it write code but used inspiration also for error handling.
    https://chatgpt.com/share/67219b6e-9298-800e-93cf-7c122879a507

    Class and past assignment code was used

    To Compile: g++ *.cpp -o myProgram
    To Run: ./myPorogram input.txt