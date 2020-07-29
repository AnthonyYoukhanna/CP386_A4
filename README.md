# CP386 Assignment 4

## MOTIVATION
We decided to do this project because it is a requirement for the compeltion of our Operating Systems course at University.

## INSTALLATION

### _REQUIREMENTS:_ Compile and run on **Linux** or **VM running linux shell** (Made on Ubuntu)

1. Download the file as you would a normal Github Repository.

1. Transfer to your VM if necessary and put into a seperate folder.

1. Use Makefile command **"make"** without quotes for compilation using C99.

    1. "make warnings_ok" for ignoring warnings.

1. Run on linux using "./Assignment_4 X X X X"  --replace X X X X with the Max Resources you desire.

    1. you may check file name by typing "ls", the created file will be highlited green.

    1. an input file has been provided to you for convinience.

1. If an emergency stop is required you may use "CTRL+C" on your keyboard to abort the program.


## SCREENSHOTS

![Screenshot1](/pics/SC1.png "Program Start")

![Screenshot2](/pics/SC2.png "RQ, RL and * Example")

![Screenshot3](/pics/SC3.png "Run command Part 1")

![Screenshot4](/pics/SC4.png "Run command Part 2")

## CONTRIBUTION (Per Function)
```c
int main(int argc, char *argv[]) //basil
int readFile(char* fileName, Customer** customer); //basil
int safetyAlgorithm(int customerCount); //sakir
void requestResource(int threadID, int item1, int item2, int item3, int item4, int customerCount); //sakir
void releaseResource(int threadID, int item1, int item2, int item3, int item4); //sakir
void outputValues(int customerCount); //sakir
void runProgram(int customerCount); //basil
void *runThread(void *thread); //basil
```
###check Commit log for more accurate contributions

## FEATURES

1. Error checking for case sensitive commands.
1. String split using fgets instead of scanf for saftey of buffer.
1. Error checking for requesting or releasing more unnecessary number of resources.

## TESTS

EX: ./Assignment_4 10 10 10 10
    RQ 0 1 1 1 1
    RQ 2 9 9 9 9
    RL 2 9 9 9 9
    *
    RUN

## CODE EXAMPLE

RQ: Request Resource
RL: Release Resource
* : Show current resources
RUN: Run safety Algorithm and find Safe sequence
999: Stop the program


    
All commands are case sensitive
    

## AUTHORS

Sakir Jiva, [@sakirjiva](https://github.com/SakirJiva)

Basil Zuberi, [@basilzuberi](https://github.com/basilzuberi)

## CREDITS
Sakir Jiva, @sakirjiva [@sakirjiva](https://github.com/SakirJiva) Contributer

Basil Zuberi, @basilzuberi [@basilzuberi](https://github.com/basilzuberi) Contributer

[Linux Manual](https://linux.die.net/man/) [https://linux.die.net/man/]

## LICENSE
Copyright 2020 SAKIR JIVA AND BASIL ZUBERI

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

