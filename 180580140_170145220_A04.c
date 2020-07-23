/*
CP386 Assignment 4

URL:http://www.github.com/SakirJiva/CP386_A4

Basil Zuberi
Github Login: basilzuberi
Student ID: 170145220


Sakir Soyab Jiva
Github Login: SakirJiva 
Student ID: 180580140
*/
#include<stdio.h>

int numAvailable;
int numMaximum;
int numAllocated;
int numNeeded;

/*main is where we will pass the commandline arguments for the filename 
and we call readFile().
main will listen to the user and push the command "RL, RQ or *"
to runCommand function*/
int main(int argc, char *argv[])
{

}

/*readFile function will take in a filename and read and return
its contents for the bankers algorithm
*/
int readFile(char* fileName)
{
    FILE *file = fopen(fileName, "r");
	if (file != NULL)
	{
		char str[1000]; //string buffer
		while (fgets(str, sizeof(str), file) != NULL) //read lines
		{
            //do something with each line
			
		}
		fclose(file);
	}
	else
	{
		perror(fileName); //error
        return -1;
	}



}

/* runProgram will use bankers algorithm to implement the program.
we will use this function to call requestResource, releaseResource and outputValues
depending on what command the user types: "RL, RQ or *"
*/
void runProgram()
{
    

}

/* Will fill an allocation array, then we will use saftey algorithm and
output whether the request was satisfied or denied by using 0 for sucess and -1 
for denied.  Command will look like this:

RQ cus# th# th# th# th#
example: RQ 0 3 1 2 1 (from assignment)
*/
void requestResource()
{

}

/* we will release the resource when the command RL is used:
RQ cus# th# th# th# th#
example: RL 4 1 2 3 1 (from assignment)
*/
void releaseResource()
{

}

/*
when user uses "*" as a command we will output the current state of the struct
show user Available, Maximum, Allocation and Need arrays
*/
void outputValues()
{

}

/* Implmentation of the safety algorithm
*/
int safetyAlgorithm()
{

}